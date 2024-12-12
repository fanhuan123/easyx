#include"tree.h"
using namespace std;
int main()
{
	init();//初始化函数 
	char imagefile_route[100];//图片文件路径数组 
	IMAGE img_bk,img_plant,img_fire,img_enemy;//图片变量 
	int plantimg_h ;//植物图片高度变量 
	int plantimg_w ;//植物图片宽度变量 
	int fireimg_h ;
	int fireimg_w;
	int plant_x=100;
	int plant_y=100;
	int is_add=-1;
	double angle=0;
	int radim=200;
	ExMessage msg1;
	BeginBatchDraw();//开始批量作图 
	//gameexit_graph();
	while(1)
	{	
	cleardevice();//用背景颜色刷新游戏窗口 
	sprintf(imagefile_route,".\\image\\bk%d.png",clock()/120%10+1);
	loadimage(&img_bk,imagefile_route,graph_width,graph_height);//获取背景图片 
	putimage(0,-100,&img_bk);//加载背景图片 
	sprintf(imagefile_route,".\\image\\enemy%d.png",clock()/150%9+1);
	loadimage(&img_enemy,imagefile_route,100,100);//获取丧尸图片 
	imageput_alpha(&img_enemy,500,200);//加载丧尸图片 
	sprintf(imagefile_route,".\\image\\Imitater_spin%d.png",clock()/60%6+1);//往字符串中插入变量 
	loadimage(&img_plant,imagefile_route);//获取植物图片 
	plantimg_h = img_plant.getheight();//获取植物图片高度 
	plantimg_w = img_plant.getwidth();//获取植物图片宽度 
	fireimg_h = img_fire.getheight();//获取鬼火图片高度 
	fireimg_w = img_fire.getwidth();//获取鬼火图片宽度
	loadimage(&img_fire,".\\image\\fire.png",100,50);
	while(peekmessage(&msg1))
	{
		move(&msg1,plant_x,plant_y);
	}
	imageput_alpha(&img_plant,plant_x,plant_y);//以透明背景方式加载植物图片
	imageput_alpha(&img_fire,plant_x+plantimg_w*0.5+radim*cos(angle)-fireimg_w*0.5,plant_y+plantimg_h*0.5+radim*sin(angle)-fireimg_h*0.5);
    imageput_alpha(&img_fire,plant_x+plantimg_w*0.5+radim*cos(angle+2*M_PI/3)-fireimg_w*0.5,plant_y+plantimg_h*0.5+radim*sin(angle+2*M_PI/3)-fireimg_h*0.5);
    imageput_alpha(&img_fire,plant_x+plantimg_w*0.5+radim*cos(angle+4*M_PI/3)-fireimg_w*0.5,plant_y+plantimg_h*0.5+radim*sin(angle+4*M_PI/3)-fireimg_h*0.5);
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
	}	
}
