#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QtTest/QTest>
#include <QDebug>

#include "palnet.h"
#include "eclipse.h"


class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = 0);
    Palnet* solar;
    Eclipse* eclipse;

signals:

public slots:

private slots:
    /**
      * test class
      * this function is called before test
      */
    void initTestCase()
    {
        qDebug("called before test");
        solar = new Palnet();
        if(!solar->readData())
        {
            qDebug("Sorry, couldn't find your files!");
        }
        eclipse = new Eclipse();
    }

    /**
      * test class
      * this function is called after the test
      */
    void cleanupTestCase()
    {
        qDebug("called after test");
    }

    /********************************************************
      *
      * add own test function here
      *
      *******************************************************/

    /**
      * check if the init is right
      */
    void checkInitPanlet();
    void checkInitEclipse();

    /**
      * read data here and jduge if they are right
      */
    void dataRightMercury();
    void dataRightVenus();
    void dataRightEarth();
    void dataRightMars();
    void dataRightJupiter();
    void dataRightSaturn();
    void dataRightUranus();
    void dataRightneptune();

    /**
      * test class
      * set speed
      */
    void palnetSetSpeed();

    /**
      * test class
      * pause
      */
    void palnetPause();



};

#endif // TEST_H
