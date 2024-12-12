#include"tree.h"
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
	settextstyle(text_height,text_width,"宋体");
	mciSendString("open ..\\music\\M500000yLI8y2RJRq3.mp3",NULL,0,NULL);
	mciSendString("play ..\\music\\M500000yLI8y2RJRq3.mp3",NULL,0,NULL);
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
void move(ExMessage*msg1,int &plant_x,int& plant_y)
{
	bool is_up;
	bool is_down;
	bool is_left;
	bool is_right;
if(msg1->message==WM_KEYDOWN)
		{
		switch(msg1->vkcode)
		{
			case 'W':
			case 'w':
				is_up=true;
				break;
			case 'S':
			case 's':
				is_down=true;
				break;
			case 'A':
			case 'a':
				is_left=true;
				break;
			case 'D':
			case 'd':
				is_right=true;
				break;
		}
	   }
	    if(msg1->message==WM_KEYUP)
	    {
		switch(msg1->vkcode)
		{
			case 'W':
			case 'w':
				is_up=false;
				break;
			case 'S':
			case 's':
				is_down=false;
				break;
			case 'A':
			case 'a':
				is_left=false;
				break;
			case 'D':
			case 'd':
				is_right=false;
				break;
		}
	    }
	if(is_up)
	 plant_y-=10;
	if(is_down)
	 plant_y+=10;
	if(is_left)
	 plant_x-=10;
	if(is_right)
	 plant_x+=10; 
}
