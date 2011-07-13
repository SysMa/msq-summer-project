// Base.h: interface for the CBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASE_H__5B929723_17FD_4CF1_B2CB_F2B6DBD9A0BD__INCLUDED_)
#define AFX_BASE_H__5B929723_17FD_4CF1_B2CB_F2B6DBD9A0BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Color 
{
public:
	float r;
	float g;
	float b;
};

class CBase  
{
public:
	CBase();
	virtual ~CBase();

	CRect  Field;
	float    Width;
	Color  color;



	virtual void Draw(){};
	virtual void DrawCurrentOperation(){};
	virtual void OnLButtonDown(float x, float y){};
	virtual bool OnLButtonUp(float x, float y){return false;};
	virtual void OnRButtonUp(float x, float y){};
	virtual void OnMouseMove(float x, float y){};
	virtual void OnLButtonDblClk(float x, float ){};

	virtual bool    Read(CString str){return true;};
	virtual CString Save(){return "";};


	virtual CString GetClassName(){return "CBase";};


	virtual void Clip(CBase*elem,CBase*list[],int& count){};
	virtual bool Pick(float x,float y){return false;};
	virtual bool GetTheFeildCrect(){return false;};
	virtual void OnKeyMove(UINT nChar){};

	virtual void SetColor(float r, float g, float b){};
	virtual void SetSize(float size){};
	virtual void Translate(float x, float y){};
	virtual void GetPos(float& x, float& y){};

};

#endif // !defined(AFX_BASE_H__5B929723_17FD_4CF1_B2CB_F2B6DBD9A0BD__INCLUDED_)
