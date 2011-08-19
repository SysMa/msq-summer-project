#include "test.h"


test::test(QObject *parent) :
    QObject(parent)
{
}

/*********************************************
  *
  * add own test funcitno realization here
  *
  *******************************************/

/**
  * check if the init panlet is right
  */
void test::checkInitPanlet()
{
   QCOMPARE(solar->mercury_axis_angle,0.0);
   QCOMPARE(solar->venus_axis_angle,0.0);
   QCOMPARE(solar->earth_axis_angle,0.0);
   QCOMPARE(solar->mars_axis_angle,0.0);
   QCOMPARE(solar->jupiter_axis_angle,0.0);
   QCOMPARE(solar->saturn_axis_angle,0.0);
   QCOMPARE(solar->uranus_axis_angle,0.0);
   QCOMPARE(solar->neptune_axis_angle,0.0);
   QCOMPARE(solar->moon_axis_angle,0.0);
}

/**
  * check if the init eclipse is right
  */
void test::checkInitEclipse()
{
    QCOMPARE(eclipse->sun_dis,3.0);
    QCOMPARE(eclipse->sun_r,1.0);
    QCOMPARE(eclipse->moon_dis,1.0);
    QCOMPARE(eclipse->moon_r,0.5);
    QCOMPARE(eclipse->angle,0.0);
    QCOMPARE(eclipse->pause,false);
}

/**
  * read data from file, check if they are right
  */
void test::dataRightMercury()
{
    // DATA ABOUT MERCURY
    QCOMPARE(-0.140728,solar->mercury_data_x[0]);
    QCOMPARE(-0.443901,solar->mercury_data_y[0]);
    QCOMPARE(-0.0233456,solar->mercury_data_z[0]);

    QCOMPARE(0.276416,solar->mercury_data_x[109560]);
    QCOMPARE(0.170014,solar->mercury_data_y[109560]);
    QCOMPARE(-0.011202,solar->mercury_data_z[109560]);

    QCOMPARE(-0.114773,solar->mercury_data_x[109573]);
    QCOMPARE(0.292951,solar->mercury_data_y[109573]);
    QCOMPARE(0.0344909,solar->mercury_data_z[109573]);
}

/**
  * read data from file, check if they are right
  */
void test::dataRightVenus()
{
    // data about venus
    QCOMPARE(-0.71863,solar->venus_data_x[0]);
    QCOMPARE(-0.0225041,solar->venus_data_y[0]);
    QCOMPARE(0.041172,solar->venus_data_z[0]);

    QCOMPARE(0.627279,solar->venus_data_x[109560]);
    QCOMPARE(0.360774,solar->venus_data_y[109560]);
    QCOMPARE(-0.0308195,solar->venus_data_z[109560]);

    QCOMPARE(0.457357,solar->venus_data_x[109573]);
    QCOMPARE(0.559089,solar->venus_data_y[109573]);
    QCOMPARE(-0.0181808,solar->venus_data_z[109573]);
}

/**
  * read data from file, check if they are right
  */
void test::dataRightEarth()
{
    QCOMPARE(-0.168596,solar->earth_data_x[0]);
    QCOMPARE(0.968754,solar->earth_data_y[0]);
    QCOMPARE(0.0,solar->earth_data_z[0]);

    QCOMPARE(0.052967,solar->earth_data_x[109560]);
    QCOMPARE(0.982795,solar->earth_data_y[109560]);
    QCOMPARE(0.0,solar->earth_data_z[109560]);

    QCOMPARE(-0.17336,solar->earth_data_x[109573]);
    QCOMPARE(0.96808,solar->earth_data_y[109573]);
    QCOMPARE(0.0,solar->earth_data_z[109573]);
}

/**
  * read data from file, check if they are right
  */
void test::dataRightMars()
{
    QCOMPARE(1.39036,solar->mars_data_x[0]);
    QCOMPARE(-0.0210091,solar->mars_data_y[0]);
    QCOMPARE(-0.0346182,solar->mars_data_z[0]);

    QCOMPARE(-1.61718,solar->mars_data_x[109560]);
    QCOMPARE(0.390601,solar->mars_data_y[109560]);
    QCOMPARE(0.0469092,solar->mars_data_z[109560]);

    QCOMPARE(-1.64457,solar->mars_data_x[109573]);
    QCOMPARE(0.227668,solar->mars_data_y[109573]);
    QCOMPARE(0.0441357,solar->mars_data_z[109573]);
}

/**
  * read data from file, check if they are right
  */
void test::dataRightJupiter()
{
    QCOMPARE(4.00346,solar->jupiter_data_x[0]);
    QCOMPARE(2.93536,solar->jupiter_data_y[0]);
    QCOMPARE(-0.101821,solar->jupiter_data_z[0]);

    QCOMPARE(-4.21249,solar->jupiter_data_x[109560]);
    QCOMPARE(3.2928,solar->jupiter_data_y[109560]);
    QCOMPARE(0.0793049,solar->jupiter_data_z[109560]);

    QCOMPARE(-4.27352,solar->jupiter_data_x[109573]);
    QCOMPARE(3.21953,solar->jupiter_data_y[109573]);
    QCOMPARE(0.0809778,solar->jupiter_data_z[109573]);
}

/**
  * read data from file, check if they are right
  */
void test::dataRightSaturn()
{
    QCOMPARE(6.40855,solar->saturn_data_x[0]);
    QCOMPARE(6.56805,solar->saturn_data_y[0]);
    QCOMPARE(-0.369128,solar->saturn_data_z[0]);

    QCOMPARE(-4.454,solar->saturn_data_x[109560]);
    QCOMPARE(7.89965,solar->saturn_data_y[109560]);
    QCOMPARE(0.0452469,solar->saturn_data_z[109560]);

    QCOMPARE(-4.521,solar->saturn_data_x[109573]);
    QCOMPARE(7.86343,solar->saturn_data_y[109573]);
    QCOMPARE(0.0485534,solar->saturn_data_z[109573]);
}

/**
  * read data from file, check if they are right
  */
void test::dataRightUranus()
{
    QCOMPARE(14.4306,solar->uranus_data_x[0]);
    QCOMPARE(-13.7357,solar->uranus_data_y[0]);
    QCOMPARE(-0.23813,solar->uranus_data_z[0]);

    QCOMPARE(-16.9039,solar->uranus_data_x[109560]);
    QCOMPARE(6.99979,solar->uranus_data_y[109560]);
    QCOMPARE(0.243999,solar->uranus_data_z[109560]);

    QCOMPARE(-16.9238,solar->uranus_data_x[109573]);
    QCOMPARE(6.95,solar->uranus_data_y[109573]);
    QCOMPARE(0.244075,solar->uranus_data_z[109573]);
}

/**
  * read data from file, check if they are right
  */
void test::dataRightneptune()
{
    QCOMPARE(16.8108,solar->neptune_data_x[0]);
    QCOMPARE(-24.9925,solar->neptune_data_y[0]);
    QCOMPARE(0.127267,solar->neptune_data_z[0]);

    QCOMPARE(-15.2512,solar->neptune_data_x[109560]);
    QCOMPARE(-26.2011,solar->neptune_data_y[109560]);
    QCOMPARE(0.891404,solar->neptune_data_z[109560]);

    QCOMPARE(-15.2163,solar->neptune_data_x[109573]);
    QCOMPARE(-26.2214,solar->neptune_data_y[109573]);
    QCOMPARE(0.891016,solar->neptune_data_z[109573]);
}

/**
  * check speed function
  */
void test::palnetSetSpeed()
{
    solar->setSpeed(-100);
    QCOMPARE(-100,solar->speed);

    solar->setSpeed(-1);
    QCOMPARE(-1,solar->speed);

    solar->setSpeed(0);
    QCOMPARE(0,solar->speed);

    solar->setSpeed(1);
    QCOMPARE(1,solar->speed);

    solar->setSpeed(100);
    QCOMPARE(100,solar->speed);
}

/**
  * check pause function
  */
void test::palnetPause()
{
    solar->pause();
    QCOMPARE(solar->speed,0);
}

/*********************************************
  *
  * over
  *
  ********************************************/

// self create a main funciton and take over
//QTEST_MAIN(test)
