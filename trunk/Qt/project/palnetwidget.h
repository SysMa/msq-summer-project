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
#include "eclipse.h"
#include <QMessageBox>

class palnetWidget : public QGLWidget
{
    Q_OBJECT
public:
    //explicit palnetWidget(QObject *parent = 0);

signals:
    void date_updated(int);

public slots:


/***************************************************************************
  *
  *
  * added by MSQ
  *
  **************************************************************************/
public :
    bool fullscreen;    // bool var to store if it is fullscreen.
    int time_id;        // deal with the timer func, remember the time id
    QLabel* label;      // label to show the date time
    class Palnet* solar;// solar system
    class Eclipse* eclipse_model;// the model of the eclipse

    bool watchEclipse;  // determine pause if the eclipse happen
    bool watchStars;    // determine pause if the watchStars happen

    bool changeModel;

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

    // to show messages
    QMessageBox* showMessage;

    // jduge if the message has shown or not
    bool flag;

    // draw the sun
    bool sun;

    // determine watch potion and goal
    bool camera_from_default;
    bool camera_from_sun;
    bool camera_from_moon;
    bool camera_from_mercury;
    bool camera_from_venus;
    bool camera_from_mars;
    bool camera_from_earth;
    bool camera_from_jupiter;
    bool camera_from_saturn;
    bool camera_from_uranus;
    bool camera_from_neptune;

    bool view_to_default;
    bool view_to_moon;
    bool view_to_mercury;
    bool view_to_venus;
    bool view_to_earth;
    bool view_to_mars;
    bool view_to_jupiter;
    bool view_to_saturn;
    bool view_to_uranus;
    bool view_to_neptune;

    bool camera_changed;        // namely not default
    bool view_changed;          // namely not default

    bool light0;
    bool light1;
    bool light2;
    bool light_default;

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
