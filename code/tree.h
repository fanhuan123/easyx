#include<bits/stdc++.h>
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<cmath>
#define graph_width 2000
#define graph_height 1000
#define	bk_color WHITE
#define fill_color RED
#define line_color BLACK
#define	text_color YELLOW
#define	text_height 50
#define text_width 20
void imageput_alpha(IMAGE* img1,int x,int y);
void init();
void text_scan(char a[],int x,int y,int b);
void gameexit_graph();
void move(ExMessage* msg,int &x,int& y);
