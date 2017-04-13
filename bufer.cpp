#define _USE_MATH_DEFINES
#include <math.h>
#include "bufer.h"

namespace gwapi{

gwapi::StyleText::StyleText(int size1, std::string name1, int thick1, bool italic1, bool underline1, bool strikedOut1, int symbolSlope1, int textSlope1) :
	size(size1),
	name(name1),
	symbolSlope(symbolSlope1),
	textSlope(textSlope1),
	thick(thick1),
	italic(italic1),
	underline(underline1),
	strikedOut(strikedOut1) {
}

Bufer::Bufer(int x, int y) : sizex(x), sizey(y) {
	VOID *pvBits;

	/* ��������� ��� ����, ����� ������� �������� � ��������. */
	BITMAPINFO bmi;
	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER); 
	bmi.bmiHeader.biWidth = x;
	bmi.bmiHeader.biHeight = -y;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = x * y * 4;
	
	hdc_ = CreateCompatibleDC(NULL);
	hbmp_ = CreateDIBSection(hdc_, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0);

	SetGraphicsMode(hdc_, GM_ADVANCED);
	
	mas_ = (UINT32*) pvBits;
	SelectObject(hdc_, hbmp_);

	clear();
	brushSet();
	penSet();
	textStyle(StyleText());
}

void gwapi::Bufer::resize(int x, int y) {
	DeleteObject(hbmp_);
	DeleteDC(hdc_);

	sizex = x;
	sizey = y;

	VOID *pvBits;

	/* ��������� ��� ����, ����� ������� �������� � ��������. */
	BITMAPINFO bmi;
	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER); 
	bmi.bmiHeader.biWidth = x;
	bmi.bmiHeader.biHeight = -y;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = x * y * 4;

	hdc_ = CreateCompatibleDC(NULL);
	hbmp_ = CreateDIBSection(hdc_, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0);

	SetGraphicsMode(hdc_, GM_ADVANCED);

	mas_ = (UINT32*) pvBits;
	SelectObject(hdc_, hbmp_);

	clear();
	brushSet();
	penSet();
	textStyle(StyleText());
}

Bufer::Bufer(HDC hdc) {
	hdc_ = hdc;
	hbmp_ = NULL;
	mas_ = NULL;
	sizex = 1000;
	sizey = 1000;

	brushSet(White);
	penSet(Black);
}

Bufer::~Bufer() {
	DeleteObject(hbmp_);
	DeleteDC(hdc_);
}

void boardsToCorrect(int sizex, int sizey, int &x, int &y, int &width, int &height) {
	// TODO �������������� �� ��� ������ �����.
	/* ���� ������ � ������ ����� ����, �� ��� ������, ��� ���� ���������� ���� �����. */
	if (width == 0) width = sizex;	
	if (height == 0) height = sizey;

	/* �������� ������ �� ������� ������ ��� ���������. */
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (width > sizex) width = sizex;
	if (height > sizey) height = sizey;

	if (sizex != -1) {
		/* ��������, �� ������� �� x y �� ������� ������� ������. */
		if (x > sizex) x = sizex;
		if (y > sizey) y = sizey;

		/* �������� �� ������� �� ������� �������� �� ������� ������� ������. */
		if (x+width > sizex) width = sizex-x;
		if (y+width > sizey) height = sizey-y;
	}
}

void Bufer::drawTo(Bufer &a, int x, int y, int width, int height) {
	boardsToCorrect(sizex, sizey, x, y, width, height);
	BitBlt(a.hdc_, x, y, width, height, hdc_, 0, 0, SRCCOPY);
}

void Bufer::drawAlphaTo(Bufer &a, int x, int y, int width, int height) {
	boardsToCorrect(sizex, sizey, x, y, width, height);

	/* ���� ��������� � �������������. */
	Point c, d;
	for (int x1 = x; x1<x+width; x1++) {
		for (int y1 = y; y1<y+height; y1++) {
			c = Point(x1, y1);
			d = Point(x1 - x, y1 - y);
			a[c] = overlay(operator[](d), a[c]).clrref;
		}
	}
}

void Bufer::clear(Color cls) {
	if (cls.m[3] == 255) {
		Color oldBrush = brush_;
		brushSet(cls);
		PatBlt(hdc_, 0, 0, sizex, sizey, PATCOPY);
		brushSet(oldBrush);
	} else {
		DWORD clr1 = cls.clrref;
		for (register int i = 0; i < sizey; i++) {
			for (register int j = 0; j < sizex; j++) {
				operator[](Point(j, i)) = clr1;
			}
		}
	}
}

Pen Bufer::penSet(Color clr, double thick) {
	Pen a1 = pen_;
	
	pen_.color = clr;
	pen_.thickness = thick;
	
	DeleteObject(SelectObject(hdc_, CreatePen(PS_SOLID, (int) thick, toWindowsColor(clr))));

	SetTextColor(hdc_, toWindowsColor(clr));
	
	return a1;
}

Brush Bufer::brushSet(Color clr) {
	Brush a1 = brush_;
	
	brush_ = clr;
	
	DeleteObject(SelectObject(hdc_, CreateSolidBrush(toWindowsColor(clr))));
	
	return a1;
}

void Bufer::textOut(Point x, std::string str, TextWriteStyle stl) {
	if (stl == Center) x = x - textSize(str)/2;
	std::string first;
	do {
		first = str.substr(0, str.find("\n"));
		TextOut(hdc_, x.x, x.y, first.c_str(), first.size()); 
		x = x + Point(0, textSize(first).y);
		str.erase(0, first.size()+1);
	} while (str.size() != 0);
}

Point gwapi::Bufer::textSize(std::string str) {
	SIZE *sz = new SIZE;
	std::string first;
	Point x(0,0);

	do {
		first = str.substr(0, str.find("\n"));
		GetTextExtentPoint32(hdc_, first.c_str(), first.size(), sz);
		x = Point(max(x.x, sz->cx), max(x.y, sz->cy));
		str.erase(0, first.size()+1);
	} while (str.size() != 0);
	delete sz;

	return x;
}

void Bufer::textStyle(StyleText stl) {
	// TODO ������: ���� �� ����� ��� ������� �������� ����� ���������, ���: �������, ������ � �.�. ��� �������� ����� ���������
	LOGFONT font;
	font.lfHeight 			= -stl.size; /* ������ ������. */ 
	font.lfWidth 			= 0; /* ������ �������� � ������. */
	font.lfEscapement 		= stl.textSlope; /* ���� ������� ������������ ���������. */ 
	font.lfOrientation 		= stl.symbolSlope; /* ���� ����� �������� ������ ������� ������� � ���� X ����������. */ 
	font.lfWeight 			= stl.thick*100; /* ������� ������ � ��������� �� 0 �� 1000. */ 
	font.lfItalic 			= stl.italic; /* ��������� �����. */
	font.lfUnderline 		= stl.underline; /* ������������ �����. */
	font.lfStrikeOut 		= stl.strikedOut; /* ����������� �����. */
	font.lfCharSet 			= RUSSIAN_CHARSET; /* ����� ��������. */
	font.lfOutPrecision 	= OUT_STROKE_PRECIS; /* �������� ������. */
	font.lfClipPrecision 	= CLIP_DEFAULT_PRECIS; /* �������� ���������. */
	font.lfQuality 			= ANTIALIASED_QUALITY; /* �������� ������. */
	font.lfPitchAndFamily 	= 0; /* ������ �������� � ��������� ������. */

	/* �������� ������. */
	for (int i = 0; i < stl.name.size(); i++) {
		font.lfFaceName[i] = stl.name[i];
	}
	for (int i = stl.name.size(); i < 32; i++) {
		font.lfFaceName[i] = 0;
	}

	/* ���������� ������ � ����������� ����. */
	HFONT hfont = CreateFontIndirect(&font);
	DeleteObject(SelectObject(hdc_, hfont));
}

void Bufer::pixelDraw(Point x, Color c) {
	operator[](x) = c.clrref;
}

void Bufer::rectDraw(Point a, Point b) {
	/*for (int i = a.x; i < b.x; i++) {
		for (int j = a.y; j < b.y; j++) {
			operator[](Point(i, j)) = brush_.clrref;
		}
	}*/
	PatBlt(hdc_, a.x, a.y, b.x-a.x, b.y-a.y, PATCOPY);
	lineDraw(a, Point(b.x, a.y));
	lineDraw(a, Point(a.x, b.y));
	lineDraw(b, Point(b.x, a.y-1));
	lineDraw(b, Point(a.x-1, b.y));
}

void Bufer::circleDraw(Point c, int r) {
	Ellipse(hdc_, c.x - r, c.y - r, c.x + r, c.y + r);
}

void Bufer::lineDraw(Point a, Point b) {
	MoveToEx(hdc_, a.x, a.y, NULL);
	LineTo(hdc_, b.x, b.y);
}

void gwapi::Bufer::polyDraw(std::vector<Point> mas) {
	POINT *mas1 = new POINT[mas.size()];
	for (int i = 0; i < mas.size(); i++) {
		mas1[i] = {mas[i].x, mas[i].y};
	}
	Polyline(hdc_, mas1, mas.size());
	delete mas1;
}

inline UINT32& Bufer::operator[](Point a) {
	return mas_[a.x + sizey*a.y];
}

UINT32& Bufer::pixelGet(Point a) {
	if (inRectangle(a, Point(sizex,sizey),Point(0,0))) {
		return operator[](a);
	} else {
		// TODO ������: ��� ����� ���� ����������? ������ ����� ����� ������ ������ �� ������
		throw Bad_Coordinate();
	}
}

void Bufer::bezierDraw(std::vector<Point> a, BezierStyle stl) {
	// TODO �����������
	// ������������������ ������:
	//		���������� ����� ������� �� ������.
	//		����� ���������� �������� = �����\5.
	//		�������� ������ ����� ������� ������� �� ����������� ����� �������� ��� ������ ������������� ������.

	double len = 0;
	for (int i = 0; i < a.size()-1; i++) {
		len += (a[i]-a[i+1]).length();
	}

	int iters = (int)(len/5.0);
	double t;
	std::vector<point2> b(a.size());
	Point b2;
	Point b1;
	for (int i = 0; i <= iters; i++) {
		for (int j = 0; j < a.size(); j++) b[j] = a[j];

		for (int j = 1; j < a.size(); j++) {
			for (int k = 0; k < a.size()-j; k++) {
				b[k] = b[k] + (b[k+1]-b[k])*((double)(i)/iters);
			}
		}
		b2 = b[0];
		if (i != 0) lineDraw(b2, b1);
		b1 = b2;
	}
}

void gwapi::Bufer::pixelDraw(point2, Color) {
	// TODO �����������
	// ��� ������������ �������. 
	// ���� ���������� ����� - �� ����������� ���� �������.
	// ���� ���������� �������, �� ���������, ��� ��� �������, ����� �������� ��������� +point2(0.5,0.5), 
	//		� ��� ��� ��������� ����� ������� �������� ��������� ����� ����� �������. � ����� �� ������ �� ������ �������.
}

void gwapi::Bufer::rectDraw(point2, point2) {
	// TODO �����������
	// ��� ����, ����� ���������� ������������� � ������������� ������������ ����: 
	//		���������� ��� ���������� �����
	//		����������� ������� � ����������� �������� ������� � ���������� �����.
}

void gwapi::Bufer::circleDraw(point2, double) {
	// TODO �����������
	// ���������� �������� ���������� ������ � ������� �������� � ������� ����.
	// ������� ����� ����� ������� ������� ��� ������������. ������� ���������� ����� ����� ���������� �� ���������� ����� �������.
	// ������ ���������� ��� ��� �� ������� - �� ���������� �����, ������� � ����� ��� ����� ������������ ������ �������.
	// ������� ���������� ����� ������������ ������ �� ��������, ��� � �����
}

void createBorders(point2 p1, point2 p2, Point &p3, Point &p4, double thick, int sizex, int sizey) {
	p3 = Point(min(p1.x, p2.x), min(p1.y, p2.y));
	p4 = Point(max(p1.x, p2.x), max(p1.y, p2.y));

	p3.x -= thick*1.5 + 3;
	p3.y -= thick*1.5 + 3;
	p4.x += thick*1.5 + 3;
	p4.y += thick*1.5 + 3;

	p4 = p4 - p3;
	boardsToCorrect(sizex, sizey, p3.x, p3.y, p4.x, p4.y);
	p4 = p4 + p3;
}

double pa_, pb_, pc_, ab_, sab_;
double getAlpha(Point &x1, const point2 &p1, const point2 &p2, double thick) {
	point2 x = x1;
	x = x + point2(0.5, 0.5);

	double a, b, c, d, r, r1;
	a = pa_;
	b = pb_;
	c = pc_;

	thick = thick-1;
	if (thick < 0) thick = 0;

	// ���������� �� ����� �� ������
	r = fabs(a*x.x + b*x.y + c)/sab_;

	// �������� ����� �� ������
	point2 pr = point2(
		(b*(b*x.x-a*x.y)-a*c)/ab_, 
		(a*(-b*x.x+a*x.y)-b*c)/ab_);

	if (r < (thick+1)) { // ����� ��������� � ����������� �������������� ������, ������������ ��������
		bool inRect = inRectangle(pr, p1 - point2(0.3,0.3), p2 + point2(0.3,0.3)) || inRectangle(pr, p2 - point2(0.3,0.3), p1 + point2(0.3,0.3));

		if (!inRect && ((r1 = min((p1-x).length(), (p2-x).length())) <= thick+1)) { 
			if (r1 > thick) {
				// ����� �� ����� ��������������
				r1 -= thick;
				return 1-r1;
			} else {
				// ����� ������ ��������������
				return 1;
			}
		}
		if (inRect) {
			if (r > thick) {
				// ����� �� ����� ��������������
				r -= thick;
				return 1-r;
			} else {
				// ����� ������ ��������������
				return 1;
			}
		}
	}
	return 0;
}

double getAlpha1(Point x, point2 p1, point2 p2, double thick) {
	static double a, b, c, d, r, r1;
	a = pa_;
	b = pb_;
	c = pc_;

	thick *= sab_;

	const double num = 15; // �� 0.1 �� 15 �����������

	// �������� ����� �� ������
	point2 pr, y;

	int sum = 0;
	bool inRect;
	for (int i = 0; i <= num; i++) {
		for (int j = 0; j <= num; j++) {
			y = point2(x.x + i/num, x.y + j/num);
			r = fabs(a*y.x + b*y.y + c);
			pr = point2( (b*(b*y.x-a*y.y)-a*c)/ab_, 
					(a*(-b*y.x+a*y.y)-b*c)/ab_);
			bool inRect = inRectangle(pr, p1 - point2(0.3,0.3), p2 + point2(0.3,0.3)) || inRectangle(pr, p2 - point2(0.3,0.3), p1 + point2(0.3,0.3));
			if (inRect && r<=thick) {
				sum++;
			}
		}
	}

		
	return sum/((num+1)*(num+1));
}

void getParams(point2 p1, point2 p2) {
	// ��������� ���������� ������
	static double d;
	if ((d = p2.x*p1.y-p1.x*p2.y) != 0) {
		pa_ = (p2.y-p1.y)/d;
		pb_ = (p1.x-p2.x)/d;
		pc_ = 1;
	} else if ((d = p2.y-p1.y) != 0) {
		pa_ = 1;
		pb_ = (p1.x-p2.x)/d;
		pc_ = (p2.x*p1.y-p1.x*p2.y)/d;
	} else {
		std::cout << "Points not to line: " << p1 << " " << p2 << std::endl;
	}
	ab_ = pa_*pa_ + pb_*pb_;
	sab_ = sqrt(ab_);
}

void gwapi::Bufer::lineDraw(point2 p1, point2 p2) {
	// TODO �����������
	// ��� ����, ����� ���������� ����� �� ������������, ����� ������� � ������������ ������� ������������ ����� � ������ ������:
	//		������������ ��������� ��� ��������� ������� ������� �������� ������������� ����� � �� �������� � ������ ������� � ������� �������
	//		������ �������� �������:
	//			������������ n x n ����� ������ �������-�������� � ��� ������ ��������������, ����������� �� ��� ������ �����, � ��� ������� ��������� ��� ���������� ������������� �����
	//			������� ��������� ������, � ������� ������ ������������� ��� ������� ���������������� �������� �����
	//			������� ��������� ��� ������, ���������� ���������� x^n + y^n = 1, ��� n - ������� ������ �����. ��� ��� ������� ��������� ����� ������� �����.
	//			������������ ���������� ������� ��� �������� ��������� ������� ������� ����� �������� � �������.
	//		� ������� ����� ����� ����������� ��� ��� ������ � �������� �������� �������� � �������� ������.
	//		� ��� � �������� ������� ������ ����������� �� �������� � ��������.
	p1 = p1 + point2(0.5, 0.5); p2 = p2 + point2(0.5, 0.5);
	getParams(p1, p2);

	Point p3, p4;
	createBorders(p1, p2, p3, p4, pen_.thickness, sizex, sizey);

	Color newc;
	double alpha;
	for (int i = p3.x; i < p4.x; i++) {
		for (int j = p3.y; j < p4.y; j++) {
			alpha = getAlpha(Point(i, j), p1, p2, pen_.thickness/2.0);

			newc = pen_.color;
			newc.m[3] = newc.m[3]*alpha;
			if (newc.m[3] == 0) newc.m[3] = 1;
			operator[](Point(i, j)) = gwapi::overlay(newc, operator[](Point(i, j))).clrref;
		}
	}
}

void gwapi::Bufer::polyDraw(std::vector<point2> mas) {
	// TODO �����������
	// ��� ����, ����� ���������� ������������� ���� ������������ ����� XOR ��� ������.
	// ������������ ����� ��������������� ����� ��� ��, ��� � � ������� ������.
	// ��� ����� ���� �� ����� �������.
}

}

#ifdef __BUFERTEST
using namespace gwapi;
#include <windows.h>
#include <iostream>
#include <stdlib.h>
int main() {
	Bufer a(300,300), b(300, 300), currConsole(GetDC(GetConsoleWindow()));

	b.clear(Transparent);
	b.brushSet(argb(128,128,0,128));
	b.penSet(rgb(255,0,0), 2);
	b.rectDraw(Point(100, 100), Point(170, 170));

	a.clear();
	a.penSet(rgb(128,0,128), 3);
	a.lineDraw(Point(100,100), Point(200,200));
	a.lineDraw(Point(100,200), Point(200,100));
	a.circleDraw(Point(150,150), 50);
	a.textStyle(14, "Times New Roman");
	a.textOut(Point(100,100), string("TEXT TEST"));

	b.drawAlphaTo(a);

	a.drawTo(currConsole);
	b.drawTo(currConsole, 300);
	system("pause");
	return 0;
}
#endif