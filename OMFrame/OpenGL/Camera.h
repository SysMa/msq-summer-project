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
	float	    g_eye [3]; 	                        //�ӵ�
	float	    g_look[3];	                        //Ŀ���
	float	    rad_xz;		                        //�Ƕ�
	float	    g_Angle;	                        //��λ��
	float	    g_elev;		                        //������
	BOOL		DisplayScene();	                    //��������

};

#endif // !defined(AFX_CAMERA_H__3741F0A0_01A2_4ECD_BE2C_A46CC13D97C5__INCLUDED_)
