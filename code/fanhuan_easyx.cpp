#include"tree.h"
using namespace std;
int main()
{
	init();//��ʼ������ 
	char imagefile_route[100];//ͼƬ�ļ�·������ 
	IMAGE img_bk,img_plant,img_fire,img_enemy;//ͼƬ���� 
	int plantimg_h ;//ֲ��ͼƬ�߶ȱ��� 
	int plantimg_w ;//ֲ��ͼƬ��ȱ��� 
	int fireimg_h ;
	int fireimg_w;
	int plant_x=100;
	int plant_y=100;
	int is_add=-1;
	double angle=0;
	int radim=200;
	ExMessage msg1;
	BeginBatchDraw();//��ʼ������ͼ 
	//gameexit_graph();
	while(1)
	{	
	cleardevice();//�ñ�����ɫˢ����Ϸ���� 
	sprintf(imagefile_route,".\\image\\bk%d.png",clock()/120%10+1);
	loadimage(&img_bk,imagefile_route,graph_width,graph_height);//��ȡ����ͼƬ 
	putimage(0,-100,&img_bk);//���ر���ͼƬ 
	sprintf(imagefile_route,".\\image\\enemy%d.png",clock()/150%9+1);
	loadimage(&img_enemy,imagefile_route,100,100);//��ȡɥʬͼƬ 
	imageput_alpha(&img_enemy,500,200);//����ɥʬͼƬ 
	sprintf(imagefile_route,".\\image\\Imitater_spin%d.png",clock()/60%6+1);//���ַ����в������ 
	loadimage(&img_plant,imagefile_route);//��ȡֲ��ͼƬ 
	plantimg_h = img_plant.getheight();//��ȡֲ��ͼƬ�߶� 
	plantimg_w = img_plant.getwidth();//��ȡֲ��ͼƬ��� 
	fireimg_h = img_fire.getheight();//��ȡ���ͼƬ�߶� 
	fireimg_w = img_fire.getwidth();//��ȡ���ͼƬ���
	loadimage(&img_fire,".\\image\\fire.png",100,50);
	while(peekmessage(&msg1))
	{
		move(&msg1,plant_x,plant_y);
	}
	imageput_alpha(&img_plant,plant_x,plant_y);//��͸��������ʽ����ֲ��ͼƬ
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
	FlushBatchDraw();//��������ͼƬ 
	}	
}
