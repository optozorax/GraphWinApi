<html>
<head>
	<style>
	p{
		margin: 5px 0px;
		font: 500 13.5px Ubuntu;
		text-align: justify;
	}
	
	h1{
		font: bold 20pt Ubuntu Mono;
		color: #800080;
	}
	
	td {
		padding: 3px 3% 3px 3px;
		background: rgba(255, 255, 255, 0.85);
		//-webkit-filter:blur(1px);
	}
	
	strcom {
		font: italic 11pt Ubuntu Mono;
		color: #808080;
	}
	
	li {
		font: 11pt Ubuntu Mono;
		color: #008000;
	}
	
	li ol li{
		font: 11pt Ubuntu Mono;
		color: #000080;
	}
	
	li ol li ol li{
		font: 10pt Ubuntu Mono;
		color: #800000;
	}
	li ol li ol li ol li{
		font: 11pt Ubuntu Mono;
		color: #008080;
	}
	li ol li ol li ol li ol li{
		font: 11pt Ubuntu Mono;
		color: #008000;
	}
	li ol li ol li ol li ol li ol li{
		font: 11pt Ubuntu Mono;
		color: #000080;
	}
	li ol li ol li ol li ol li ol li ol li{
		font: 11pt Ubuntu Mono;
		color: #800000;
	}
	li ol li ol li ol li ol li ol li ol li ol li{
		font: 11pt Ubuntu Mono;
		color: #008080;
	}
	#backgroundimage
	{
		border-width: 0;
		left: 0;
		margin: 0;
		max-height: 100%;
		min-height: 100%;
		padding: 0;
		position: fixed;
		top: 0;
		z-index: -1;
	}
	</style>
</head>

<body>
<center>
<img alt='' id='backgroundimage' src='wallhaven-22879.jpg' style="width: 100%"> 
<table border='1' width='800px' id='thh'>
<alla>	
<!--
	<tr> <td>
		<p></p>
		<ol>
			<hr>
			<p></p>
			<li><p></p>
		</ol>
		
		</ol>
		<ol>
		
		</ol>
	</td> </tr>
	<tr> <td>
		<ol>
		
	</td> </tr>
--> 

	<!-- ===================================================================== -->
	<!-- ===================================================================== -->
	<!-- ===================================================================== -->
	<tr> <td>
		<center> <h1>������ ��� ��������� ������� � ��, GraphC.h.</h1> </center>
		<ol>
			<p>����:</p>
			<li><p>������ ���� ������� ����� � ������� ����������� ��� ��������� ������� � �++, ��������� ������, ����� ��� ���� ����������� ��� ����������� ���������, �� ������������, ���, � ��� �� � ������������� � ���. ����� �� ��� ���������� ������ GraphABC, � � ��� �������������� �������. � ����� �� �������� ���.</p>
		</ol>
		<ol>
			<p>�������:</p>
			<li><p>GraphABC.</p>
				<ol>
					<li><p>���� ������� �������: lockdrawing, redraw.</p>
					<li><p>����� ������������ ��� ����������, ������� ���� ����, ���� �����, ����� ���� � �.�.</p>
					<li><p>���� ��� �������� ����������� ���������: setpixel, line, circle, ellipse, polyline, polygon, rectangle, rounrect, arc, pie, chord, floodfill, TextOut.</p>
					<li><p>����� ����������� ���� ����, �����, � ���� ����������� �����, ��� �� ���� ������� rgb, getred, getgreen, getblue.</p>
					<li><p>����� ����������� ����: ����, �������, �����.</p>
					<li><p>����� ����������� �����: ����, �����, ������� ����������� �����.</p>
					<li><p>����� ����������� ����� ���������� ������: ���, ������, ����, ������������-������ � �.�., � ��� �� ����� ������ ����� �������� ����� ���������� ������ ����� �� ������.</p>
					<li><p>����� �������� � ���������: ���������, ���������, ���������, ������� �� ������, ��������, ��������, �������, ��������� ������� � ������.</p>
					<li><p>����� �������� � �����: �������, ������ ������, �����������, �������� ���������, ���������, ������������� � �����������.</p>
					<li><p>����� �������� � ��������: �������������� �� ��������� � ������, ����������� ������������ �������� �� ������� � ����.</p>
				</ol>
			<li><p>Events.</p>
				<ol>
					<li><p>���� ������� ��: �������, ���������, �������� ����; �������, ��������� �������; ��������� ��������, �������� ����.</p>
					<li><p>���� ���� ����������� ������ �� ����������� �������.</p>
				</ol>
			<li><p>Utils.</p>
				<ol>
					<li><p>����� �������� � ����������: ���������, ���������������, �������, ���������� �������������, ���������� �������, ������ �������.</p>
					<li><p>����� �������� � �������: ���������������, �������, ���������� �������������. ��� �� ����� ���������� ��� ����� � ��������.</p>
					<li><p>����� �������� Warning ����� ����������.</p>
					<li><p>����� �������� �� �������� ����: ��������� �������, ��������� ���������� �����, ��� � �.�.</p>
				</ol>
			<li><p>Timer.</p>
				<ol>
					<li><p>����� ���������, ������� ������.</p>
					<li><p>����� ����������� ����� �������.</p>
					<li><p>����� ���������, ������������� ������.</p>
					<li><p>����� ��������� ������� �������, ����� ��� ��������� �����������.</p>
				</ol>
			<li><p>GraphCanvas - ���.</p>
				<ol>
					<li><p>������������ ������������ � �� ��� ������ � ���: ���������� �����, ��� ��������� ����� ���������� ��� ��������� � ���������� �����.</p>
					<li><p>������������ �����������, ��� �� ����������� ��������� � �������������. ����������� �� ���� ����������, ����� �� ����� �������� ��������� ������� �� ������������ � �������������.</p>
					<li><p>��� �� ������� �� ���������, ��� ���� � GraphABC.</p>
				</ol>
			<li><p>ZenGL.</p>
				<ol>
					<li><p>� ����� ������ ����� ���������� ����� ������� ������.</p>
					<li><p>������ �� ����, � ��� ����, ��������� ��, ��� ����.</p>
				</ol>
			<li><p>WinAPI.</p>
				<ol>
					<li><p>���� ������� ��������� ����.</p>
					<li><p>����� ��������� ������.</p>
				</ol>
		</ol>
	</td> </tr>
	<tr> <td>
		<ol>
			<p>����:</p>
			<li><p>������� ����� ���� ������� ����������, �������� �� define aplha, define smooth, define smoothSize 4; � ��� ���������, ������� ����� ����� ���������.</p>
			<li><p>����� ������������� ������ ��� ����� point2, point3 � �.�.</p>
			<li><p>��� �� ������ � ���� ������� ����� ���������� ������ ��� ������������� �� ����������� ������ ������������ � ����� ������.</p>
			<li><p>����� ������� ����� ���� ������ ��� ����������, ������ � �������, �������� � ���������� ������������. � ����� �� ����� ���� ������� � ������ � ��� ������ ������������ ��������, ��� ���� ������� ��������� ��������.</p>
				<ol>
					<li><p>��� ��������� �������� ����� �� ���������� ���������, ��� ����� ��������������.</p>
					<li><p>��� �� ����� ���� �������� �� ��������� - ��������� � XY � ������� 1 �� ��� z.</p>
				</ol>
			<li><p>�������, ����� ���� ����������� �������������, � ��������� ������������.</p>
				<ol>
					<li><p>��� ������������� ����� �������� ��� ����, �������, �����, ������� ��� ��������� ��������� � ������.</p>
					<li><p>����� ������� ���������, ����� �� ���������� ������������.</p>
					<li><p>�������, ����� ����� ���� �������� ��� ���� ����, ��������� � WinAPI.</p>
					<li><p>����� � ��������� ���������� ��������� ��������� ������.</p>
				</ol>
			<hr>
			<p>������� �������:</p>
			<li><p>�������, ����� ���� ����� ��������� �����, � ���������� �� ���, ����� ��� ������ ���������� �� ��������������, ��� ����������, � ����� ����� ���� �������� ������ ��������.</p>
			<li><p>������� ��������� ������� �� ������, ����� ��� ���� � ������� *.chm, ��� �� ����� � ��� ���� �������� ��� ������������� ���������, �����, ����� ���� �������� ��� ���������� ����� � ������� WinAPI, � ��� ���-��.</p>
			<hr>
			<p>��������, ������� ���� ������:</p>
			<li><p>����� �� �������� ���������� ������, � ����� ��� ������� ��� ���������?</p>
				<ol>
					<li><p>���������� ������ �������� �����, �������, �� �� �� ��������������. ������������� �������� ����� ����������.</p>
					<li><p>���� ������������ ������������, �� �� ����������� ���������� ����� ����������.</p>
						<ol>
							<li><p>��� �������� �� �� ������ ����-�������, � ������ ���� �������� ���������� �����.</p>
							<li><p>�������� ��� ������� ��������.(��� ���, ����� ���������)</p>
						</ol>
				</ol>
			<li><p>���� ����������� ��� ���� � ������� ����� � �������������.</p>
				<ol>
					<li><p>����� ������� ��������� ��������� ��� ��������� � �������������� ����������� �����(� ��������� ��� ����� ����������� ������������ ������).</p>
					<li><p>� ��������� ��������� ��� ��������� �������� ����������� �����������.</p>
					<li><p>����� ������������ �������� �� ��������������.</p>
					<li><p>���������� ����� ����� ������ ����������� �������.</p>
					<hr>
					<li><p><b>���� ������ ������� �������:</b> ��� ��������� �������� � ������� ������ ������������. ����� ����� ������� �������, ���� ���� ������������ �������, �� ������� ��� 255. � ������� ������� ������� ������������, ����� �������� �� �������� ��� 0�01.</p>
				</ol>
		</ol>
	</td> </tr>	
	<tr> <td>
		<ol>
			<p>���� ������</p>
			<li><p>����� - �������� ��� ��������� � ��������.</p>
				<ol>
					<p>����������:</p>
					<li><p>�����, ����.</p>
					<hr>
				</ol>
				<ol>
					<li><p>�����������(������ ������), ����������.</p>
					<li><p><s>������� ����� �� ����������� ����.</s></p>
						<ol>
							<li><p>������ �� �����, ��� ��������� � ������� ���� ������������ hdc ������� � �������.</p>
						</ol>
					<li><p>��������� ��� ������ � ������� ��������.</p>
						<ol>
							<li><p>������</p>
							<li><p>���������� �����.</p>
							<li><p>���������� ���.</p>
						</ol>
					<li><p>��������� ��� ������ � ������ � �����.</p>
						<ol>
							<li><p>��������� �����, �������, �����(��� ����� �� ����� ��������).</p>
						</ol>
					<li><p>��������� ��� ������ ������.</p>
					<li><p>��������� ��� ������ � ���������.</p>
					<li><p>������� ��������.(���������� - ������ ���� �������)</p>
					<li><p>���������:</p>
						<ol>
							<li><p>��������� �������.</p>
							<li><p>���������� �������������</p>
							<li><p>���������� ����������(��������� �� �������� - ���� ������, ������� �����, ���� ����).</p>
							<li><p>���������� �����(��������� �� ���������� - ����, �������, �����, ���� ������).</p>
							<li><p>���������� �������������(�� ��������� ������� ������).</p>
							<li><p>���������� ������ ����� �� ����������� �������(����� ����� ���������).</p>
								<ol>
									<li><p>���� ������� ��� �� ������������, ��� � ���.</p>
									<li><p>����� �����-�� ������������� �������� ���� ����������, � ������ ��� ��������(� ������� �������).</p>
								</ol>
						</ol>
				</ol>
			<li><p>����� ������� �������:</p>
				<ol>
					<li><p>��������� ������.</p>
					<li><p>������ �� ������� �����-��.</p>
					<li><p>������� ��������.</p>
				</ol>
			<li><p>���� - �������� �������� ��� �����. �������� � ���� ������ ������ � ����������� �� ������� ���������� �������. ������� �������� ������ �� ������ ���������� �����.</p>
				<ol>
					<p>����������:</p>
					<li><p>HWND, HDC</p>
					<hr>
				</ol>
				<ol>
					<p>�������:</p>
					<li><p>�����������(������ ����, ���������, �����), ����������.</p>
					<li><p>���������� �� ������.</p>
					<li><p>�������� ������ ����, ���������, ���������.</p>
					<li><p>��������� �� ������� �������. �������: ������� �������, ��������� ��������� ����� � ������.</p>
				</ol>
			<li><p>�������� - ����� ��� �������������� �������� � ������ � �������� � ������������� ��� ������.</p>
				<ol>
					<p>������ ����� ���� ����� ����� �� ���������� � ��������� �����. � ����� ��� ���� ����� ��� ������� ������. ��� ����� ����������� ����� ffmpeg - �  ��������� ������ �� �� ��� ������.</p>
					<hr>
					<p>�������:</p>
					<li><p>���������� ������ �� ����� �� ����� � ����� �� ����, ����� �� ��������, � �����-�� ����� ����������.</p>
					<li><p>��������� ��������(���� �� ����������� ���, �� ����������� ���, ��� ���� ����� �������� ��������)(����� �������� ����� ��������� ��� �������� ������).</p>
					<li><p>���������� ����������� �������� � ������������� ����� � ��������� ���������� ����� �������� � �������� ������.</p>
					<li><p>��� ����������� ������� ������� ��� �� ��� ��������� ��������, ������� �� ������������ � �����.</p>
				</ol>
			<li><p>���� - ����� �������������� ��� ������.</p>
				<ol>
					<p>� ��������� ������ ������ ������� �����, ����� ����������.</p>
					<hr>
					<p>�������:</p>
					<li><p>������� rgb. ��� argb.</p>
					<li><p>����� �� ������ �����.</p>
					<li><p>������ �� ����� � ��� ���������.</p>
					<li><p>����������� ������.</p>
					<li><p>������, ������� ���������� � ������.</p>
					<li><p>�������� �� ������ ������� ������(���������� ����� ������� ���������).</p>
					<li><p>��������� ������ ����� �� ������. ������������, ����������� ���������������� �������.</p>
				</ol>
		</ol>
	</td> </tr>
</table>
</center>

<script>
	document.getElementById('thh').innerHTML = document.getElementById('thh').innerHTML.replace(/('[^$].*?')/g, '<strcom>$1</strcom>');
</script>

</body>
</html>