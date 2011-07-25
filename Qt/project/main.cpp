/************************************************************
 *
 * Project : solar system
 * Author  : Shiqing Ma
 * Date    : 2011 summer
 *
 *************************************************************/
//#include <QtGui/QApplication>
//#include "mainwindow.h"


/*************************************************************
 *
 * before these notes the declare are required by the sys
 * the ones next are added by MSq
 *
 *************************************************************/
#define QT3_SUPPORT
#include <qapplication.h>
#include <qmessagebox.h>

#include "call.h"
#include "mywidget.h"
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWidget solar(0,0,false);
    a.setMainWidget(&solar);
    solar.show();

    return a.exec();
}
