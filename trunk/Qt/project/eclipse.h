#ifndef ECLIPSE_H
#define ECLIPSE_H

#include <QGLWidget>

/**
 * this is a model to show the eclipse
 * introcuction: earth is in the center with the moon around it.
 * the sun is in a stable place.
 */

class Eclipse : public QGLWidget
{
    Q_OBJECT
public:

signals:

public slots:


public:
    // the place of the moon and the sun
    // only two of them for z = 0
    /*
    double sun[2];
    double moon[2];
    */// ont useful for we can calculate from the distance

    // distance of the two things.
    double sun_dis;
    double moon_dis;

    // radius of the models
    double sun_r;
    double moon_r;

    // the speed of the moon
    double angle;
    double speed;

    // pause or not
    bool pause;

public:
    // here are some functions

    /**
     * the construction
     */
    Eclipse();

    /**
     * draw objects
     */
    void drawSun();
    void drawMoon();

    /**
     * update the model
     */
    void step();
};

#endif // ECLIPSE_H
