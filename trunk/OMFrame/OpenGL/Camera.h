// Camera.h: interface for the CCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAMERA_H__3741F0A0_01A2_4ECD_BE2C_A46CC13D97C5__INCLUDED_)
#define AFX_CAMERA_H__3741F0A0_01A2_4ECD_BE2C_A46CC13D97C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCamera  
{
public:
	CCamera();
	virtual ~CCamera();
	float     speed;
	float	    g_eye [3]; 	                        //视点
	float	    g_look[3];	                        //目标点
	float	    rad_xz;		                        //角度
	float	    g_Angle;	                        //方位角
	float	    g_elev;		                        //仰俯角
	BOOL		DisplayScene();	                    //摄像漫游

};

#endif // !defined(AFX_CAMERA_H__3741F0A0_01A2_4ECD_BE2C_A46CC13D97C5__INCLUDED_)
