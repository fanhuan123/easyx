#include<bits/stdc++.h>
#include<easyx.h>
#include"tree.h"
using namespace std;
#define graph_width 1000
#define graph_height 500
int main()
{
	init();
	int plantimg_h ;
	int plantimg_w ;
	char imagefile_route[100];
	IMAGE img_bk,img_plant;
	BeginBatchDraw();
	//gameexit_graph();
	while(1)
	{	
	cleardevice();
	loadimage(&img_bk,"C:\\Users\\Dell\\Desktop\\background.jpg",graph_width,graph_height);
	putimage(0,0,&img_bk);
	text_scan("金币数量:",0,0,0);
	sprintf(imagefile_route,"C:\\Users\\Dell\\Desktop\\植物大战僵尸素材包\\reanim\\Imitater_spin%d.png",clock()/100%6+1);
	loadimage(&img_plant,imagefile_route);
	plantimg_h = img_plant.getheight();
	plantimg_w = img_plant.getwidth();
	imageput_alpha(&img_plant,(graph_width-plantimg_w)*0.5,(graph_height-plantimg_h)*0.5);
	FlushBatchDraw();
	Sleep(50);
	}	
}
