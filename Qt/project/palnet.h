/*****************************************
 *
 *This is time-line solar system model
 *
 *****************************************/
#ifndef PALNET_H
#define PALNET_H

#include <GL/gl.h>
#include <GL/glu.h>

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
                  double data_z[], double cycle);

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
                    double angle, GLuint texture_id );


    /**
     * load texture for palnets
     */
    bool loadTexture(GLuint* texture_id);

public:
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
    GLuint texture_id[8];

    // texture image
    // used to texutre
    //
    char* image[8];

public:
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
};

#endif // PALNET_H
