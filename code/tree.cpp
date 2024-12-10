#include<bits/stdc++.h>
#include<easyx.h>
#include"tree.h"
#include<graphics.h>
#include<conio.h>
#define graph_width 1000
#define graph_height 500
#define	bk_color WHITE
#define fill_color RED
#define line_color BLACK
#define	text_color YELLOW
#define	text_height 50
#define text_width 20
void imageput_alpha(IMAGE* img1,int x,int y)
{
	int w=img1->getwidth();
	int h=img1->getheight();
	AlphaBlend(GetImageHDC(NULL),x,y,w,h,GetImageHDC(img1),0,0,w,h,{AC_SRC_OVER,0,255,AC_SRC_ALPHA});
}
void init()
{
	initgraph(graph_width,graph_height);
	setbkcolor(bk_color);
	cleardevice();
	setfillcolor(fill_color);
	setlinecolor(line_color);
	setbkmode(TRANSPARENT);
	settextcolor(text_color);
	setlinestyle(PS_SOLID);
	settextstyle(text_height,text_width,"楷体");
	mciSendString("open C:\\Users\\Dell\\Downloads\\M500000yLI8y2RJRq3.mp3",NULL,0,NULL);
	mciSendString("play C:\\Users\\Dell\\Downloads\\M500000yLI8y2RJRq3.mp3",NULL,0,NULL);
	HWND hwd=GetHWnd();
	SetWindowText(hwd,"游戏窗口");
	
}
void text_scan(char a[],int x,int y,int b)
{ char c[10];
	outtextxy(x,y,a);
	sprintf(c,"%d",b);
	outtextxy(x+sizeof(a)/sizeof(a[0])*text_width+text_width,y,c);
}
void gameexit_graph()
{
	HWND hwd=GetHWnd();
	int isok=MessageBox(hwd,"是否要退出游戏","提示",MB_OKCANCEL);
	if(isok==IDOK)
	{
		closegraph();
	}
}
