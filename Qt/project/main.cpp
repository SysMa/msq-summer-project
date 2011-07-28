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
#include "palnetwidget.h"
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //myWidget test(0,0,false);
    //a.setMainWidget(&test);
    //test.show();

    palnetWidget solar_sys(0,0,false);
    a.setMainWidget(&solar_sys);
    solar_sys.showNormal();

    return a.exec();
}
