#include"tree.h"
using namespace std;
int main()
{
	init();//初始化函数 
	char imagefile_route[100];//图片文件路径数组 
	IMAGE img_bk,img_plant,img_shell;//图片变量 
	int plantimg_h ;//植物图片高度变量 
	int plantimg_w ;//植物图片宽度变量 
	int shellimg_h ;
	int shellimg_w;
	int plant_x=0;
	int plant_y=0;
	int is_add=-1;
	double angle=0;
	int radim=200;
	ExMessage msg1;
	BeginBatchDraw();//开始批量作图 
	//gameexit_graph();
	while(1)
	{	
	cleardevice();//用背景颜色刷新游戏窗口 
	loadimage(&img_bk,"..\\image\\background.jpg",graph_width,graph_height);//获取背景图片 
	putimage(0,0,&img_bk);//加载背景图片 
	text_scan("金币数量:",0,0,0);//窗口插入文本 
	sprintf(imagefile_route,"..\\image\\Imitater_spin%d.png",clock()/50%6+1);//往字符串中插入变量 
	loadimage(&img_plant,imagefile_route);//获取植物图片 
	plantimg_h = img_plant.getheight();//获取植物图片高度 
	plantimg_w = img_plant.getwidth();//获取植物图片宽度 
	shellimg_h = img_shell.getheight();//获取火球图片高度 
	shellimg_w = img_shell.getwidth();//获取火球图片宽度
	loadimage(&img_shell,"C:\\Users\\1\\Desktop\\easyx素材\\植物大战僵尸素材包\\reanim\\FirePea.png");
	while(peekmessage(&msg1))
	{
		move(&msg1,plant_x,plant_y);
	}
	imageput_alpha(&img_plant,plant_x,plant_y);//以透明背景方式加载植物图片
	imageput_alpha(&img_shell,plant_x+plantimg_w*0.5+radim*cos(angle)-shellimg_w*0.5,plant_y+plantimg_h*0.5+radim*sin(angle)-shellimg_h*0.5);
    imageput_alpha(&img_shell,plant_x+plantimg_w*0.5+radim*cos(angle+2*M_PI/3)-shellimg_w*0.5,plant_y+plantimg_h*0.5+radim*sin(angle+2*M_PI/3)-shellimg_h*0.5);
    imageput_alpha(&img_shell,plant_x+plantimg_w*0.5+radim*cos(angle+4*M_PI/3)-shellimg_w*0.5,plant_y+plantimg_h*0.5+radim*sin(angle+4*M_PI/3)-shellimg_h*0.5);
    angle+=0.1;
    if(radim==100)
    {
    	is_add=1;
	}
	if(radim==200)
	{
		is_add=-1;
	}
	radim+=is_add*10;
	FlushBatchDraw();//放置所有图片 
	Sleep(50);
	}	
}
