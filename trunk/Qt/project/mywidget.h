#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QGLWidget>

/***********************************************************
 *
 * these decalration are added by MSQ
 *
 *************************************************************/
#include <QtOpenGL/qgl.h>

/**
 * this is my own widget
 */
class myWidget : public QGLWidget
{
    Q_OBJECT
public:
signals:
public slots:

/*********************************************************
 *
 * Here are my code.
 *
 *********************************************************/
public :
    myWidget(QWidget* parent = 0, const char* name = 0, bool fs = false);
    ~myWidget();

protected :
    /**
     * init func
     */
    void initializeGL();

    /**
     * paint the widget function
     */
    void paintGL();

    /**
     * resize the window func
     */
    void resizeGL(int width, int height);

    /**
     * deal with the key pressing func
     */
    void keyPressEvent(QKeyEvent *e);

protected :
    bool fullscreen;    //bool var to store if it is fullscreen.
};

#endif // MYWIDGET_H
