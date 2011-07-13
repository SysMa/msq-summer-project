// Text.h: interface for the CText class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXT_H__657CE35D_BE7A_404F_A9E7_5FECAE113C7C__INCLUDED_)
#define AFX_TEXT_H__657CE35D_BE7A_404F_A9E7_5FECAE113C7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base.h"
	static int isFirstCall;
    static GLuint lists=1;

class CText : public CBase  
{
public:
	CText();
	virtual ~CText();
	CText(char *str, int size);

	float length;
	char  *text;
	int size;


	 

	float screenX;
	float screenY;


    unsigned int texID;		// font texture id
	unsigned int callList;	// font display list

	

	 
    bool OnLButtonUp(float x, float y);
     
	bool Pick(float x,float y);
    bool GetTheFeildCrect();
    void GetPos(float& x, float& y);
	//void LoadTexture();		// loads the TGA font texture
	//	void CreateCallLists();	// creates the font display list
     void Draw();

	void Build(char *name, int size);
	void ClearFont();
	
	void Print( char *str);
	void OnKeyMove(UINT nChar);

	bool     Read(CString str);
    CString  Save();
    CString  GetClassName(){return "CText";};
	
	void SetPos2D(int x, int y) 
	{ screenX = x; screenY = y; }

	


};

#endif // !defined(AFX_TEXT_H__657CE35D_BE7A_404F_A9E7_5FECAE113C7C__INCLUDED_)
