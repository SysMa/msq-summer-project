#ifndef PALNETWIDGET_H
#define PALNETWIDGET_H

#include <QGLWidget>

/***********************************************************
 *
 * these decalration are added by MSQ
 *
 *************************************************************/
#include <QtOpenGL/qgl.h>
#include <QLabel>
#include <qlabel.h>
#include "palnet.h"

class palnetWidget : public QGLWidget
{
    Q_OBJECT
public:
    //explicit palnetWidget(QObject *parent = 0);

signals:

public slots:


/***************************************************************************
  *
  *
  * added by MSQ
  *
  **************************************************************************/
protected :
    bool fullscreen;    // bool var to store if it is fullscreen.
    int time_id;        // deal with the timer func, remember the time id

    QLabel* label;
    class Palnet* solar;// solar system


    // view port
    double from_x;
    double from_y;
    double from_z;
    double to_x;
    double to_y;
    double to_z;
    double up_x;
    double up_y;
    double up_z;

/*********************************************************
 *
 * Here are my code.
 *
 *********************************************************/
public :
    palnetWidget(QWidget* parent = 0, const char* name = 0, bool fs = false);
    ~palnetWidget();

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

    /**
     * timer to define a animation
     */
    void timerEvent(QTimerEvent* e);

    //鼠标移动事件

    void mouseMoveEvent(QMouseEvent *e);

    //鼠标点击事件

    void mousePressEvent(QMouseEvent *e);


    //鼠标释放事件

    void mouseReleaseEvent(QMouseEvent *e);

    //移动鼠标
    void enterEvent(QEvent *);
    void move(int x, int y);
};

#endif // PALNETWIDGET_H
