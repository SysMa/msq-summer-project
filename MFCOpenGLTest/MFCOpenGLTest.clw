; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCOpenGLTest.h"
LastPage=0

ClassCount=8
Class1=CMFCOpenGLTestApp
Class2=CMFCOpenGLTestDoc
Class3=CMFCOpenGLTestView
Class4=CMainFrame

ResourceCount=6
Resource1=IDR_TOOLBAR1
Class5=CAboutDlg
Class6=CPaintToolBar
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class7=CCharacterDialog
Resource4=IDD_DIALOG1
Resource5=IDD_DIALOG2
Class8=CSizeDialog
Resource6=IDD_DIALOG3

[CLS:CMFCOpenGLTestApp]
Type=0
HeaderFile=MFCOpenGLTest.h
ImplementationFile=MFCOpenGLTest.cpp
Filter=N
LastObject=CMFCOpenGLTestApp

[CLS:CMFCOpenGLTestDoc]
Type=0
HeaderFile=MFCOpenGLTestDoc.h
ImplementationFile=MFCOpenGLTestDoc.cpp
Filter=N

[CLS:CMFCOpenGLTestView]
Type=0
HeaderFile=MFCOpenGLTestView.h
ImplementationFile=MFCOpenGLTestView.cpp
Filter=C
LastObject=CMFCOpenGLTestView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=MFCOpenGLTest.cpp
ImplementationFile=MFCOpenGLTest.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_APP_EXIT
Command4=ID_EDIT_RESTAR
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_VIEW_TOOLBAR
Command9=ID_VIEW_STATUS_BAR
Command10=ID_PAINTTOOL
Command11=ID_APP_ABOUT
CommandCount=11

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CPaintToolBar]
Type=0
HeaderFile=PaintToolBar.h
ImplementationFile=PaintToolBar.cpp
BaseClass=CToolBarCtrl
Filter=W

[TB:IDR_TOOLBAR1]
Type=1
Class=?
CommandCount=0

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDITTEXT,edit,1350631552
Control3=IDC_SLIDER,msctls_trackbar32,1342242840
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDITSIZE,edit,1484849280
Control6=IDC_BUTTONOK,button,1342242816

[DLG:IDD_DIALOG2]
Type=1
Class=CCharacterDialog
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT,edit,1350631552
Control3=IDC_SLIDER,msctls_trackbar32,1342242840
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BUTTON,button,1342242816
Control6=IDC_EDITSIZE,edit,1484849280

[CLS:CCharacterDialog]
Type=0
HeaderFile=CharacterDialog.h
ImplementationFile=CharacterDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCharacterDialog

[DLG:IDD_DIALOG3]
Type=1
Class=CSizeDialog
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_SLIDER,msctls_trackbar32,1342242840
Control3=IDC_BUTTON,button,1342242816
Control4=IDC_EDIT,edit,1484849280

[CLS:CSizeDialog]
Type=0
HeaderFile=SizeDialog.h
ImplementationFile=SizeDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSizeDialog

