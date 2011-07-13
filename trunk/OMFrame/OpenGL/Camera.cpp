// Camera.cpp: implementation of the CCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "MySDOpenGL.h"
#include "Camera.h"
#include <math.h>
#define KEY_DOWN(vk_code)((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
// #define MAP_W       32       // size of map along x-axis 32 
// #define MAP_SCALE   24.0f     // the scale of the terrain map
// #define MAP			MAP_W*MAP_SCALE/2

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCamera::CCamera()
{
	g_eye[0]=0;g_eye[1]=0;g_eye[2]=0.0;
	speed=1;
	g_elev=2;
	g_Angle=20;
	
}

CCamera::~CCamera()
{

}
BOOL CCamera::DisplayScene()//摄像漫游
{ 
	float x=g_eye[0],y=g_eye[2],z=g_eye[2];

	if (KEY_DOWN(VK_SHIFT))  speed   =speed*2;//按SHIFT时的加速true
	if (KEY_DOWN(VK_CONTROL))  speed = speed/2;
	
	if (KEY_DOWN(VK_LEFT))   g_Angle+=speed*2;//左转,方位角+
	if (KEY_DOWN(VK_RIGHT))  g_Angle-=speed*2;//右转,方位角-
	rad_xz = float (3.13149* g_Angle/180.0f);	//计算左右旋转角度
	if (KEY_DOWN(33))		   g_elev +=speed;	//Page UP  键
	if (KEY_DOWN(34))		   g_elev -=speed;	//Page Down键
	if (g_elev<-360)		   g_elev  =-360;	//仰俯角
	if (g_elev> 360)		   g_elev  = 360;	//仰俯角
	if (KEY_DOWN(VK_UP))						//前进
	{
		g_eye[2]+=(float)sin(rad_xz)*speed/8.0;			//视点的x分量
		g_eye[0]+=(float)cos(rad_xz)*speed/8.0;			//视点的Z分量
	}
	if (KEY_DOWN(VK_DOWN))					//后退
	{
		g_eye[2]-=(float)sin(rad_xz)*speed/8.0;			//视点的x分量
		g_eye[0]-=(float)cos(rad_xz)*speed/8.0;			//视点的Z分量
	}
	//控制到摄像机不离开地面
	/*
	if(g_eye[0]<  MAP_SCALE)			g_eye[0]=  MAP_SCALE;
	if(g_eye[0]> (MAP_W-2)*MAP_SCALE)	g_eye[0]= (MAP_W-2)*MAP_SCALE;
	if(g_eye[2]<-(MAP_W-2)*MAP_SCALE)	g_eye[2]=-(MAP_W-2)*MAP_SCALE;
	if(g_eye[2]> -MAP_SCALE)			g_eye[2]= -MAP_SCALE;*/

	if (KEY_DOWN(VK_HOME)) 
	{
		g_eye[1]+=(speed/10.0);
	}
	if (KEY_DOWN(VK_END)) 
	{
		g_eye[1]-=(speed/10.0);
	}
	//////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////
	//g_eye[1] =GetHeight((float)g_eye[0],(float)g_eye[2])+1.8f;//设置摄像机对地位置高
	//摄像机的方向
	///////////////////////////////////////////////////////////////////////////////
	g_look[0] = (float)(g_eye[0] +100*cos(rad_xz));//目标点X分量
	g_look[2] = (float)(g_eye[2] +100*sin(rad_xz));	///目标点Z分量
	g_look[1] = g_eye[1] +g_elev;				//目标点Y分量
	//////////////////////////////////////////////////////////////////////////////
	//建立modelview矩阵方向
	gluLookAt(g_eye[0],g_eye[1],g_eye[2],		//视点
		g_look[0],g_look[1],g_look[2],	//目标点
		0.0,1.0,0.0						//视点方向
		);
	return TRUE;
}
