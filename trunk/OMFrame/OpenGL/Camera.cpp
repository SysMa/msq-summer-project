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
BOOL CCamera::DisplayScene()//��������
{ 
	float x=g_eye[0],y=g_eye[2],z=g_eye[2];

	if (KEY_DOWN(VK_SHIFT))  speed   =speed*2;//��SHIFTʱ�ļ���true
	if (KEY_DOWN(VK_CONTROL))  speed = speed/2;
	
	if (KEY_DOWN(VK_LEFT))   g_Angle+=speed*2;//��ת,��λ��+
	if (KEY_DOWN(VK_RIGHT))  g_Angle-=speed*2;//��ת,��λ��-
	rad_xz = float (3.13149* g_Angle/180.0f);	//����������ת�Ƕ�
	if (KEY_DOWN(33))		   g_elev +=speed;	//Page UP  ��
	if (KEY_DOWN(34))		   g_elev -=speed;	//Page Down��
	if (g_elev<-360)		   g_elev  =-360;	//������
	if (g_elev> 360)		   g_elev  = 360;	//������
	if (KEY_DOWN(VK_UP))						//ǰ��
	{
		g_eye[2]+=(float)sin(rad_xz)*speed/8.0;			//�ӵ��x����
		g_eye[0]+=(float)cos(rad_xz)*speed/8.0;			//�ӵ��Z����
	}
	if (KEY_DOWN(VK_DOWN))					//����
	{
		g_eye[2]-=(float)sin(rad_xz)*speed/8.0;			//�ӵ��x����
		g_eye[0]-=(float)cos(rad_xz)*speed/8.0;			//�ӵ��Z����
	}
	//���Ƶ���������뿪����
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
	//g_eye[1] =GetHeight((float)g_eye[0],(float)g_eye[2])+1.8f;//����������Ե�λ�ø�
	//������ķ���
	///////////////////////////////////////////////////////////////////////////////
	g_look[0] = (float)(g_eye[0] +100*cos(rad_xz));//Ŀ���X����
	g_look[2] = (float)(g_eye[2] +100*sin(rad_xz));	///Ŀ���Z����
	g_look[1] = g_eye[1] +g_elev;				//Ŀ���Y����
	//////////////////////////////////////////////////////////////////////////////
	//����modelview������
	gluLookAt(g_eye[0],g_eye[1],g_eye[2],		//�ӵ�
		g_look[0],g_look[1],g_look[2],	//Ŀ���
		0.0,1.0,0.0						//�ӵ㷽��
		);
	return TRUE;
}
