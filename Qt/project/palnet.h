/*****************************************
 *
 *This is time-line solar system model
 *
 *****************************************/
#ifndef PALNET_H
#define PALNET_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

/**
 *
 */
struct GlobalPosition
{
        float fPosX,fPosY;
        int iDegreesX,iDegreesY;
        bool bRotationOn;
};


/**
 *
 * this is a time-line solar system model
 *
 **/
class Palnet
{
public:
    /**
     * constructin
     * read data from the files and use them to draw a model
     * used as the default construction
     * @param none
     * @return nothing
     **/
    Palnet();


    /**
     * read data from the files
     * @param none
     * @retun none
     **/
    bool readData();

    /**
     * read data from one file
     * used by func: readData();
     */
    bool getData(char* filename, double data_x[],
                 double data_y[], double data_z[]);

    /**
     * draw lines
     * use points data
     * @param bool * 9 to determine weather lines are needed
     */
    bool drawLines();

    /**
     * draw line
     */
    bool drawLine(double data_x[], double data_y[],
                  double data_z[], double cycle,
                  double line_width);

    /**
     * draw planets and the moon
     * note: the sun is always there t "provide" light
     **/
    bool drawPalnets();

    /**
     * draw a singal palnet
     */
    bool drawPalnet(double point_x, double point_y,
                    double point_z, double size,
                    double solar_angle,
                    double axis_angle,
                    GLuint texture);


    /**
     * draw our sun
     */
    void drawSun();

    /**
     * draw our moon
     */
    bool drawMoon( double earth_x, double earth_y, double earth_z,
                   double solar_angle, double axis_angle);
    /**
     * load texture for palnets
     */
    bool loadTexture(GLuint *texture,char* path,int i);
    //bool loadTextures(GLuint *texture_id);
    bool loadMoonTexture(GLuint moon_id, char* path);

    /**
     * update the postion
     */
    void setNew();

    /**
     * draw moon line
     */
    bool drawMoonLine();

    /**
     * use aux to load the bit map file
     */
    AUX_RGBImageRec* LoadBMP(char *Filename);

    /**
     * rendre screen
     */
    bool renderscreen();

    /**
     * draw stars
     */
    bool drawStars();


    /**
     * set speed
     */
    bool setSpeed(int desire_speed);

    /**
     * eclipse
     */
    bool isEclipse();

    /**
     * planets in line
     */
    bool isInline();

public:
    // PI
    double pie;

    // nine boolean vars to determine if the line is needed.
    // used as public to be modified easily
    bool mercury_line;
    bool venus_line;
    bool earth_line;
    bool mars_line;
    bool jupiter_line;
    bool saturn_line;
    bool uranus_line;
    bool neptune_line;
    bool moon_line;

    // nine boolean vars to determine if the palnets or moon is needed.
    // used as public to be modified easily
    bool mercury;
    bool venus;
    bool earth;
    bool mars;
    bool jupiter;
    bool saturn;
    bool uranus;
    bool neptune;
    bool moon;

    // palnets cycles
    // used as public to be modified easily
    double mercury_cycle;
    double venus_cycle;
    double earth_cycle;
    double mars_cycle;
    double jupiter_cycle;
    double saturn_cycle;
    double uranus_cycle;
    double neptune_cycle;
    double moon_cycle;

    // the size of palnets
    // used to draw
    double sun_size;
    double mercury_size;
    double venus_size;
    double earth_size;
    double mars_size;
    double jupiter_size;
    double saturn_size;
    double uranus_size;
    double neptune_size;
    double moon_size;

    // rotate angle
    // used to self rotate
    double mercury_angle;
    double venus_angle;
    double earth_angle;
    double mars_angle;
    double jupiter_angle;
    double saturn_angle;
    double uranus_angle;
    double neptune_angle;
    double moon_angle;

    // solar angle
    // used to ratate
    double mercury_solar_angle;
    double venus_solar_angle;
    double earth_solar_angle;
    double mars_solar_angle;
    double jupiter_solar_angle;
    double saturn_solar_angle;
    double uranus_solar_angle;
    double neptune_solar_angle;
    double moon_solar_angle;

    // axis angle
    // used to ratate
    double mercury_axis_angle;
    double venus_axis_angle;
    double earth_axis_angle;
    double mars_axis_angle;
    double jupiter_axis_angle;
    double saturn_axis_angle;
    double uranus_axis_angle;
    double neptune_axis_angle;
    double moon_axis_angle;

    // speed of aixs angle
    double mercury_axis_speed;
    double venus_axis_speed;
    double earth_axis_speed;
    double mars_axis_speed;
    double jupiter_axis_speed;
    double saturn_axis_speed;
    double uranus_axis_speed;
    double neptune_axis_speed;
    double moon_axis_speed;

    // speed of the solar angle
    double mercury_solar_speed;
    double venus_solar_speed;
    double earth_solar_speed;
    double mars_solar_speed;
    double jupiter_solar_speed;
    double saturn_solar_speed;
    double uranus_solar_speed;
    double neptune_solar_speed;
    double moon_solar_speed;


    // the data to be shown on the screen
    // used in the time-animation
    // default 0
    int data_num;

    // the speed time flies
    // used in the timer_event
    // default 1
    int speed;

    // texture id
    // used to texture
    //
    GLuint texture_id[10];

    // texture image
    // used to texutre
    //
    char* image[10];

    // the distance from moon to earth
    //
    double distance;

    // global positon
    //
    GlobalPosition globalPosition;

    // line width
    // used when to draw lines
    //
    double mercury_line_width;
    double venus_line_width;
    double earth_line_width;
    double mars_line_width;
    double jupiter_line_width;
    double saturn_line_width;
    double uranus_line_width;
    double neptune_line_width;
    double moon_line_width;

    // radius data eight planets without the moon and the sun
    double mercury_data_x[109574];
    double mercury_data_y[109574];
    double mercury_data_z[109574];

    double venus_data_x[109574];
    double venus_data_y[109574];
    double venus_data_z[109574];

    double earth_data_x[109574];
    double earth_data_y[109574];
    double earth_data_z[109574];

    double mars_data_x[109574];
    double mars_data_y[109574];
    double mars_data_z[109574];

    double jupiter_data_x[109574];
    double jupiter_data_y[109574];
    double jupiter_data_z[109574];

    double saturn_data_x[109574];
    double saturn_data_y[109574];
    double saturn_data_z[109574];

    double uranus_data_x[109574];
    double uranus_data_y[109574];
    double uranus_data_z[109574];

    double neptune_data_x[109574];
    double neptune_data_y[109574];
    double neptune_data_z[109574];

    // light
    GLfloat LightAmbient[4];
    GLfloat LightDiffuse[4];
    GLfloat LightPosition[4];

    GLfloat LightAmbient2[4];
    GLfloat LightDiffuse2[4];
    GLfloat LightPosition2[4];

    // center
    double center_x;
    double center_y;
    double center_z;

    // required angle
    // the angle required to jduge the stars in line
    //
    double required_angle;

};

#endif // PALNET_H
