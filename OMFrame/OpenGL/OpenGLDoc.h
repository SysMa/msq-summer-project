// OpenGLDoc.h : COpenGLDoc ��Ľӿ�
//


#pragma once


class COpenGLDoc : public CDocument
{
protected: // �������л�����
	COpenGLDoc();
	DECLARE_DYNCREATE(COpenGLDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~COpenGLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


