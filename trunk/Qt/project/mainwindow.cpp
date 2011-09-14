#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QDesktopServices>

/*
  for dubug
  */
#include <QDebug>

/**/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(showPlanet(int)));
    connect(ui->comboBox_2,SIGNAL(currentIndexChanged(int)),this,SLOT(cameraPosition(int)));
    connect(ui->comboBox_3,SIGNAL(currentIndexChanged(int)),this,SLOT(viewPositon(int)));

    connect(ui->widget_2,SIGNAL(date_updated(int)),this,SLOT(refreshTime(int)));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(showAbout()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(showAdvice()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(keepTime()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(showHotkey()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(showHelp()));

    showMessage = new QMessageBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * show the selected one
 */
void MainWindow::showPlanet(int index)
{
    switch(index)
    {
    case 0:
        ui->widget_2->solar->moon_line_color[0] = 0;
        ui->widget_2->solar->moon_line_color[1] = 1;
        ui->widget_2->solar->moon_line_color[2] = 0;

        ui->widget_2->solar->mercury_line_color[0] = 0;
        ui->widget_2->solar->mercury_line_color[1] = 1;
        ui->widget_2->solar->mercury_line_color[2] = 0;

        ui->widget_2->solar->venus_line_color[0] = 0;
        ui->widget_2->solar->venus_line_color[1] = 1;
        ui->widget_2->solar->venus_line_color[2] = 0;

        ui->widget_2->solar->earth_line_color[0] = 0;
        ui->widget_2->solar->earth_line_color[1] = 1;
        ui->widget_2->solar->earth_line_color[2] = 0;

        ui->widget_2->solar->mars_line_color[0] = 0;
        ui->widget_2->solar->mars_line_color[1] = 1;
        ui->widget_2->solar->mars_line_color[2] = 0;

        ui->widget_2->solar->jupiter_line_color[0] = 0;
        ui->widget_2->solar->jupiter_line_color[1] = 1;
        ui->widget_2->solar->jupiter_line_color[2] = 0;

        ui->widget_2->solar->saturn_line_color[0] = 0;
        ui->widget_2->solar->saturn_line_color[1] = 1;
        ui->widget_2->solar->saturn_line_color[2] = 0;

        ui->widget_2->solar->uranus_line_color[0] = 0;
        ui->widget_2->solar->uranus_line_color[1] = 1;
        ui->widget_2->solar->uranus_line_color[2] = 0;

        ui->widget_2->solar->neptune_line_color[0] = 0;
        ui->widget_2->solar->neptune_line_color[1] = 1;
        ui->widget_2->solar->neptune_line_color[2] = 0;

        ui->widget_2->updateGL();
        break;
    case 1:
        ui->widget_2->solar->moon_line_color[0] = 0;
        ui->widget_2->solar->moon_line_color[1] = 1;
        ui->widget_2->solar->moon_line_color[2] = 0;

        ui->widget_2->solar->mercury_line_color[0] = 1;
        ui->widget_2->solar->mercury_line_color[1] = 0;
        ui->widget_2->solar->mercury_line_color[2] = 0;

        ui->widget_2->solar->venus_line_color[0] = 0;
        ui->widget_2->solar->venus_line_color[1] = 1;
        ui->widget_2->solar->venus_line_color[2] = 0;

        ui->widget_2->solar->earth_line_color[0] = 0;
        ui->widget_2->solar->earth_line_color[1] = 1;
        ui->widget_2->solar->earth_line_color[2] = 0;

        ui->widget_2->solar->mars_line_color[0] = 0;
        ui->widget_2->solar->mars_line_color[1] = 1;
        ui->widget_2->solar->mars_line_color[2] = 0;

        ui->widget_2->solar->jupiter_line_color[0] = 0;
        ui->widget_2->solar->jupiter_line_color[1] = 1;
        ui->widget_2->solar->jupiter_line_color[2] = 0;

        ui->widget_2->solar->saturn_line_color[0] = 0;
        ui->widget_2->solar->saturn_line_color[1] = 1;
        ui->widget_2->solar->saturn_line_color[2] = 0;

        ui->widget_2->solar->uranus_line_color[0] = 0;
        ui->widget_2->solar->uranus_line_color[1] = 1;
        ui->widget_2->solar->uranus_line_color[2] = 0;

        ui->widget_2->solar->neptune_line_color[0] = 0;
        ui->widget_2->solar->neptune_line_color[1] = 1;
        ui->widget_2->solar->neptune_line_color[2] = 0;
        ui->widget_2->updateGL();
        break;
    case 2:
        ui->widget_2->solar->moon_line_color[0] = 0;
        ui->widget_2->solar->moon_line_color[1] = 1;
        ui->widget_2->solar->moon_line_color[2] = 0;

        ui->widget_2->solar->mercury_line_color[0] = 0;
        ui->widget_2->solar->mercury_line_color[1] = 1;
        ui->widget_2->solar->mercury_line_color[2] = 0;

        ui->widget_2->solar->venus_line_color[0] = 1;
        ui->widget_2->solar->venus_line_color[1] = 0;
        ui->widget_2->solar->venus_line_color[2] = 0;

        ui->widget_2->solar->earth_line_color[0] = 0;
        ui->widget_2->solar->earth_line_color[1] = 1;
        ui->widget_2->solar->earth_line_color[2] = 0;

        ui->widget_2->solar->mars_line_color[0] = 0;
        ui->widget_2->solar->mars_line_color[1] = 1;
        ui->widget_2->solar->mars_line_color[2] = 0;

        ui->widget_2->solar->jupiter_line_color[0] = 0;
        ui->widget_2->solar->jupiter_line_color[1] = 1;
        ui->widget_2->solar->jupiter_line_color[2] = 0;

        ui->widget_2->solar->saturn_line_color[0] = 0;
        ui->widget_2->solar->saturn_line_color[1] = 1;
        ui->widget_2->solar->saturn_line_color[2] = 0;

        ui->widget_2->solar->uranus_line_color[0] = 0;
        ui->widget_2->solar->uranus_line_color[1] = 1;
        ui->widget_2->solar->uranus_line_color[2] = 0;

        ui->widget_2->solar->neptune_line_color[0] = 0;
        ui->widget_2->solar->neptune_line_color[1] = 1;
        ui->widget_2->solar->neptune_line_color[2] = 0;
        ui->widget_2->updateGL();
        break;
    case 3:
        ui->widget_2->solar->moon_line_color[0] = 0;
        ui->widget_2->solar->moon_line_color[1] = 1;
        ui->widget_2->solar->moon_line_color[2] = 0;

        ui->widget_2->solar->mercury_line_color[0] = 0;
        ui->widget_2->solar->mercury_line_color[1] = 1;
        ui->widget_2->solar->mercury_line_color[2] = 0;

        ui->widget_2->solar->venus_line_color[0] = 0;
        ui->widget_2->solar->venus_line_color[1] = 1;
        ui->widget_2->solar->venus_line_color[2] = 0;

        ui->widget_2->solar->earth_line_color[0] = 1;
        ui->widget_2->solar->earth_line_color[1] = 0;
        ui->widget_2->solar->earth_line_color[2] = 0;

        ui->widget_2->solar->mars_line_color[0] = 0;
        ui->widget_2->solar->mars_line_color[1] = 1;
        ui->widget_2->solar->mars_line_color[2] = 0;

        ui->widget_2->solar->jupiter_line_color[0] = 0;
        ui->widget_2->solar->jupiter_line_color[1] = 1;
        ui->widget_2->solar->jupiter_line_color[2] = 0;

        ui->widget_2->solar->saturn_line_color[0] = 0;
        ui->widget_2->solar->saturn_line_color[1] = 1;
        ui->widget_2->solar->saturn_line_color[2] = 0;

        ui->widget_2->solar->uranus_line_color[0] = 0;
        ui->widget_2->solar->uranus_line_color[1] = 1;
        ui->widget_2->solar->uranus_line_color[2] = 0;

        ui->widget_2->solar->neptune_line_color[0] = 0;
        ui->widget_2->solar->neptune_line_color[1] = 1;
        ui->widget_2->solar->neptune_line_color[2] = 0;
        ui->widget_2->updateGL();
        break;
    case 4:
        ui->widget_2->solar->moon_line_color[0] = 0;
        ui->widget_2->solar->moon_line_color[1] = 1;
        ui->widget_2->solar->moon_line_color[2] = 0;

        ui->widget_2->solar->mercury_line_color[0] = 0;
        ui->widget_2->solar->mercury_line_color[1] = 1;
        ui->widget_2->solar->mercury_line_color[2] = 0;

        ui->widget_2->solar->venus_line_color[0] = 0;
        ui->widget_2->solar->venus_line_color[1] = 1;
        ui->widget_2->solar->venus_line_color[2] = 0;

        ui->widget_2->solar->earth_line_color[0] = 0;
        ui->widget_2->solar->earth_line_color[1] = 1;
        ui->widget_2->solar->earth_line_color[2] = 0;

        ui->widget_2->solar->mars_line_color[0] = 1;
        ui->widget_2->solar->mars_line_color[1] = 0;
        ui->widget_2->solar->mars_line_color[2] = 0;

        ui->widget_2->solar->jupiter_line_color[0] = 0;
        ui->widget_2->solar->jupiter_line_color[1] = 1;
        ui->widget_2->solar->jupiter_line_color[2] = 0;

        ui->widget_2->solar->saturn_line_color[0] = 0;
        ui->widget_2->solar->saturn_line_color[1] = 1;
        ui->widget_2->solar->saturn_line_color[2] = 0;

        ui->widget_2->solar->uranus_line_color[0] = 0;
        ui->widget_2->solar->uranus_line_color[1] = 1;
        ui->widget_2->solar->uranus_line_color[2] = 0;

        ui->widget_2->solar->neptune_line_color[0] = 0;
        ui->widget_2->solar->neptune_line_color[1] = 1;
        ui->widget_2->solar->neptune_line_color[2] = 0;
        ui->widget_2->updateGL();
        break;
    case 5:
        ui->widget_2->solar->moon_line_color[0] = 0;
        ui->widget_2->solar->moon_line_color[1] = 1;
        ui->widget_2->solar->moon_line_color[2] = 0;

        ui->widget_2->solar->mercury_line_color[0] = 0;
        ui->widget_2->solar->mercury_line_color[1] = 1;
        ui->widget_2->solar->mercury_line_color[2] = 0;

        ui->widget_2->solar->venus_line_color[0] = 0;
        ui->widget_2->solar->venus_line_color[1] = 1;
        ui->widget_2->solar->venus_line_color[2] = 0;

        ui->widget_2->solar->earth_line_color[0] = 0;
        ui->widget_2->solar->earth_line_color[1] = 1;
        ui->widget_2->solar->earth_line_color[2] = 0;

        ui->widget_2->solar->mars_line_color[0] = 0;
        ui->widget_2->solar->mars_line_color[1] = 1;
        ui->widget_2->solar->mars_line_color[2] = 0;

        ui->widget_2->solar->jupiter_line_color[0] = 1;
        ui->widget_2->solar->jupiter_line_color[1] = 0;
        ui->widget_2->solar->jupiter_line_color[2] = 0;

        ui->widget_2->solar->saturn_line_color[0] = 0;
        ui->widget_2->solar->saturn_line_color[1] = 1;
        ui->widget_2->solar->saturn_line_color[2] = 0;

        ui->widget_2->solar->uranus_line_color[0] = 0;
        ui->widget_2->solar->uranus_line_color[1] = 1;
        ui->widget_2->solar->uranus_line_color[2] = 0;

        ui->widget_2->solar->neptune_line_color[0] = 0;
        ui->widget_2->solar->neptune_line_color[1] = 1;
        ui->widget_2->solar->neptune_line_color[2] = 0;
        ui->widget_2->updateGL();
        break;
    case 6:
        ui->widget_2->solar->moon_line_color[0] = 0;
        ui->widget_2->solar->moon_line_color[1] = 1;
        ui->widget_2->solar->moon_line_color[2] = 0;

        ui->widget_2->solar->mercury_line_color[0] = 0;
        ui->widget_2->solar->mercury_line_color[1] = 1;
        ui->widget_2->solar->mercury_line_color[2] = 0;

        ui->widget_2->solar->venus_line_color[0] = 0;
        ui->widget_2->solar->venus_line_color[1] = 1;
        ui->widget_2->solar->venus_line_color[2] = 0;

        ui->widget_2->solar->earth_line_color[0] = 0;
        ui->widget_2->solar->earth_line_color[1] = 1;
        ui->widget_2->solar->earth_line_color[2] = 0;

        ui->widget_2->solar->mars_line_color[0] = 0;
        ui->widget_2->solar->mars_line_color[1] = 1;
        ui->widget_2->solar->mars_line_color[2] = 0;

        ui->widget_2->solar->jupiter_line_color[0] = 0;
        ui->widget_2->solar->jupiter_line_color[1] = 1;
        ui->widget_2->solar->jupiter_line_color[2] = 0;

        ui->widget_2->solar->saturn_line_color[0] = 1;
        ui->widget_2->solar->saturn_line_color[1] = 0;
        ui->widget_2->solar->saturn_line_color[2] = 0;

        ui->widget_2->solar->uranus_line_color[0] = 0;
        ui->widget_2->solar->uranus_line_color[1] = 1;
        ui->widget_2->solar->uranus_line_color[2] = 0;

        ui->widget_2->solar->neptune_line_color[0] = 0;
        ui->widget_2->solar->neptune_line_color[1] = 1;
        ui->widget_2->solar->neptune_line_color[2] = 0;
        ui->widget_2->updateGL();
        break;
    case 7:
        ui->widget_2->solar->moon_line_color[0] = 0;
        ui->widget_2->solar->moon_line_color[1] = 1;
        ui->widget_2->solar->moon_line_color[2] = 0;

        ui->widget_2->solar->mercury_line_color[0] = 0;
        ui->widget_2->solar->mercury_line_color[1] = 1;
        ui->widget_2->solar->mercury_line_color[2] = 0;

        ui->widget_2->solar->venus_line_color[0] = 0;
        ui->widget_2->solar->venus_line_color[1] = 1;
        ui->widget_2->solar->venus_line_color[2] = 0;

        ui->widget_2->solar->earth_line_color[0] = 0;
        ui->widget_2->solar->earth_line_color[1] = 1;
        ui->widget_2->solar->earth_line_color[2] = 0;

        ui->widget_2->solar->mars_line_color[0] = 0;
        ui->widget_2->solar->mars_line_color[1] = 1;
        ui->widget_2->solar->mars_line_color[2] = 0;

        ui->widget_2->solar->jupiter_line_color[0] = 0;
        ui->widget_2->solar->jupiter_line_color[1] = 1;
        ui->widget_2->solar->jupiter_line_color[2] = 0;

        ui->widget_2->solar->saturn_line_color[0] = 0;
        ui->widget_2->solar->saturn_line_color[1] = 1;
        ui->widget_2->solar->saturn_line_color[2] = 0;

        ui->widget_2->solar->uranus_line_color[0] = 1;
        ui->widget_2->solar->uranus_line_color[1] = 0;
        ui->widget_2->solar->uranus_line_color[2] = 0;

        ui->widget_2->solar->neptune_line_color[0] = 0;
        ui->widget_2->solar->neptune_line_color[1] = 1;
        ui->widget_2->solar->neptune_line_color[2] = 0;
        ui->widget_2->updateGL();
        break;
    case 8:
        ui->widget_2->solar->moon_line_color[0] = 0;
        ui->widget_2->solar->moon_line_color[1] = 1;
        ui->widget_2->solar->moon_line_color[2] = 0;

        ui->widget_2->solar->mercury_line_color[0] = 0;
        ui->widget_2->solar->mercury_line_color[1] = 1;
        ui->widget_2->solar->mercury_line_color[2] = 0;

        ui->widget_2->solar->venus_line_color[0] = 0;
        ui->widget_2->solar->venus_line_color[1] = 1;
        ui->widget_2->solar->venus_line_color[2] = 0;

        ui->widget_2->solar->earth_line_color[0] = 0;
        ui->widget_2->solar->earth_line_color[1] = 1;
        ui->widget_2->solar->earth_line_color[2] = 0;

        ui->widget_2->solar->mars_line_color[0] = 0;
        ui->widget_2->solar->mars_line_color[1] = 1;
        ui->widget_2->solar->mars_line_color[2] = 0;

        ui->widget_2->solar->jupiter_line_color[0] = 0;
        ui->widget_2->solar->jupiter_line_color[1] = 1;
        ui->widget_2->solar->jupiter_line_color[2] = 0;

        ui->widget_2->solar->saturn_line_color[0] = 0;
        ui->widget_2->solar->saturn_line_color[1] = 1;
        ui->widget_2->solar->saturn_line_color[2] = 0;

        ui->widget_2->solar->uranus_line_color[0] = 0;
        ui->widget_2->solar->uranus_line_color[1] = 1;
        ui->widget_2->solar->uranus_line_color[2] = 0;

        ui->widget_2->solar->neptune_line_color[0] = 1;
        ui->widget_2->solar->neptune_line_color[1] = 0;
        ui->widget_2->solar->neptune_line_color[2] = 0;
        ui->widget_2->updateGL();
        break;
    default:
        break;
    }
}


/**
 * show the date with the same time in the widget
 */
void MainWindow::refreshTime(int add)
{
    //qDebug()<<add;
    QDate begin(2000,1,1);
    QDate show;
    show = begin.addDays(add);
    //qDebug()<<begin<<"  "<<show;
    ui->dateEdit->setDate(show);
}

/**
 * keep time with widget
 */
void MainWindow::keepTime()
{
    if(ui->pushButton_3->text() == "Set")
    {
        ui->widget_2->solar->setSpeed(0);
        ui->pushButton_3->setText("OK");
    }
    else if(ui->pushButton_3->text() == "OK")
    {
        //qDebug()<<ui->dateEdit->date();
        QDate end = ui->dateEdit->date();
        QDate begin(2000,1,1);
        int add = begin.daysTo(end);
        if( add < 0 || add > 109574)
        {
            QMessageBox* show = new QMessageBox;
            show->setText("Sorry, wrong date!");
            return;
        }
        else
        {
            ui->pushButton_3->setText("Set");
            ui->widget_2->solar->data_num = add;
            ui->widget_2->solar->setSpeed(1);
        }
    }
}

/**
 * determine the camera postion
 */
void MainWindow::cameraPosition(int index)
{
    switch(index)
    {
    case 0:
        ui->widget_2->camera_changed = false;
        ui->widget_2->camera_from_default = true;
        ui->widget_2->camera_from_sun     = false;
        ui->widget_2->camera_from_moon    = false;
        ui->widget_2->camera_from_mercury = false;
        ui->widget_2->camera_from_venus   = false;
        ui->widget_2->camera_from_earth   = false;
        ui->widget_2->camera_from_mars    = false;
        ui->widget_2->camera_from_jupiter = false;
        ui->widget_2->camera_from_saturn  = false;
        ui->widget_2->camera_from_uranus  = false;
        ui->widget_2->camera_from_neptune = false;

        // reset
        ui->widget_2->from_x  = 0;
        ui->widget_2->from_y  = ui->widget_2->solar->neptune_data_y[0];
        ui->widget_2->from_z  = 15;

        ui->widget_2->updateGL();
        break;
    case 1:
        ui->widget_2->camera_changed = true;
        ui->widget_2->camera_from_default = false;
        ui->widget_2->camera_from_sun     = true;
        ui->widget_2->camera_from_moon    = false;
        ui->widget_2->camera_from_mercury = false;
        ui->widget_2->camera_from_venus   = false;
        ui->widget_2->camera_from_earth   = false;
        ui->widget_2->camera_from_mars    = false;
        ui->widget_2->camera_from_jupiter = false;
        ui->widget_2->camera_from_saturn  = false;
        ui->widget_2->camera_from_uranus  = false;
        ui->widget_2->camera_from_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 2:
        ui->widget_2->camera_changed = true;
        ui->widget_2->camera_from_default = false;
        ui->widget_2->camera_from_sun     = false;
        ui->widget_2->camera_from_moon    = true;
        ui->widget_2->camera_from_mercury = false;
        ui->widget_2->camera_from_venus   = false;
        ui->widget_2->camera_from_earth   = false;
        ui->widget_2->camera_from_mars    = false;
        ui->widget_2->camera_from_jupiter = false;
        ui->widget_2->camera_from_saturn  = false;
        ui->widget_2->camera_from_uranus  = false;
        ui->widget_2->camera_from_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 3:
        ui->widget_2->camera_changed = true;
        ui->widget_2->camera_from_default = false;
        ui->widget_2->camera_from_sun     = false;
        ui->widget_2->camera_from_moon    = false;
        ui->widget_2->camera_from_mercury = true;
        ui->widget_2->camera_from_venus   = false;
        ui->widget_2->camera_from_earth   = false;
        ui->widget_2->camera_from_mars    = false;
        ui->widget_2->camera_from_jupiter = false;
        ui->widget_2->camera_from_saturn  = false;
        ui->widget_2->camera_from_uranus  = false;
        ui->widget_2->camera_from_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 4:
        ui->widget_2->camera_changed = true;
        ui->widget_2->camera_from_default = false;
        ui->widget_2->camera_from_sun     = false;
        ui->widget_2->camera_from_moon    = false;
        ui->widget_2->camera_from_mercury = false;
        ui->widget_2->camera_from_venus   = true;
        ui->widget_2->camera_from_earth   = false;
        ui->widget_2->camera_from_mars    = false;
        ui->widget_2->camera_from_jupiter = false;
        ui->widget_2->camera_from_saturn  = false;
        ui->widget_2->camera_from_uranus  = false;
        ui->widget_2->camera_from_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 5:
        ui->widget_2->camera_changed = true;
        ui->widget_2->camera_from_default = false;
        ui->widget_2->camera_from_sun     = false;
        ui->widget_2->camera_from_moon    = false;
        ui->widget_2->camera_from_mercury = false;
        ui->widget_2->camera_from_venus   = false;
        ui->widget_2->camera_from_earth   = true;
        ui->widget_2->camera_from_mars    = false;
        ui->widget_2->camera_from_jupiter = false;
        ui->widget_2->camera_from_saturn  = false;
        ui->widget_2->camera_from_uranus  = false;
        ui->widget_2->camera_from_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 6:
        ui->widget_2->camera_changed = true;
        ui->widget_2->camera_from_default = false;
        ui->widget_2->camera_from_sun     = false;
        ui->widget_2->camera_from_moon    = false;
        ui->widget_2->camera_from_mercury = false;
        ui->widget_2->camera_from_venus   = false;
        ui->widget_2->camera_from_earth   = false;
        ui->widget_2->camera_from_mars    = true;
        ui->widget_2->camera_from_jupiter = false;
        ui->widget_2->camera_from_saturn  = false;
        ui->widget_2->camera_from_uranus  = false;
        ui->widget_2->camera_from_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 7:
        ui->widget_2->camera_changed = true;
        ui->widget_2->camera_from_default = false;
        ui->widget_2->camera_from_sun     = false;
        ui->widget_2->camera_from_moon    = false;
        ui->widget_2->camera_from_mercury = false;
        ui->widget_2->camera_from_venus   = false;
        ui->widget_2->camera_from_earth   = false;
        ui->widget_2->camera_from_mars    = false;
        ui->widget_2->camera_from_jupiter = true;
        ui->widget_2->camera_from_saturn  = false;
        ui->widget_2->camera_from_uranus  = false;
        ui->widget_2->camera_from_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 8:
        ui->widget_2->camera_changed = true;
        ui->widget_2->camera_from_default = false;
        ui->widget_2->camera_from_sun     = false;
        ui->widget_2->camera_from_moon    = false;
        ui->widget_2->camera_from_mercury = false;
        ui->widget_2->camera_from_venus   = false;
        ui->widget_2->camera_from_earth   = false;
        ui->widget_2->camera_from_mars    = false;
        ui->widget_2->camera_from_jupiter = false;
        ui->widget_2->camera_from_saturn  = true;
        ui->widget_2->camera_from_uranus  = false;
        ui->widget_2->camera_from_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 9:
        ui->widget_2->camera_changed = true;
        ui->widget_2->camera_from_default = false;
        ui->widget_2->camera_from_sun     = false;
        ui->widget_2->camera_from_moon    = false;
        ui->widget_2->camera_from_mercury = false;
        ui->widget_2->camera_from_venus   = false;
        ui->widget_2->camera_from_earth   = false;
        ui->widget_2->camera_from_mars    = false;
        ui->widget_2->camera_from_jupiter = false;
        ui->widget_2->camera_from_saturn  = false;
        ui->widget_2->camera_from_uranus  = true;
        ui->widget_2->camera_from_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 10:
        ui->widget_2->camera_changed = true;
        ui->widget_2->camera_from_default = false;
        ui->widget_2->camera_from_sun     = false;
        ui->widget_2->camera_from_moon    = false;
        ui->widget_2->camera_from_mercury = false;
        ui->widget_2->camera_from_venus   = false;
        ui->widget_2->camera_from_earth   = false;
        ui->widget_2->camera_from_mars    = false;
        ui->widget_2->camera_from_jupiter = false;
        ui->widget_2->camera_from_saturn  = false;
        ui->widget_2->camera_from_uranus  = false;
        ui->widget_2->camera_from_neptune = true;

        ui->widget_2->updateGL();
        break;
    default:
        ui->widget_2->camera_changed = false;
        ui->widget_2->camera_from_default = true;
        ui->widget_2->camera_from_sun     = false;
        ui->widget_2->camera_from_moon    = false;
        ui->widget_2->camera_from_mercury = false;
        ui->widget_2->camera_from_venus   = false;
        ui->widget_2->camera_from_earth   = false;
        ui->widget_2->camera_from_mars    = false;
        ui->widget_2->camera_from_jupiter = false;
        ui->widget_2->camera_from_saturn  = false;
        ui->widget_2->camera_from_uranus  = false;
        ui->widget_2->camera_from_neptune = false;

        // reset
        ui->widget_2->from_x  = 0;
        ui->widget_2->from_y  = ui->widget_2->solar->neptune_data_y[0];
        ui->widget_2->from_z  = 15;

        ui->widget_2->updateGL();
        break;
    }
}

/**
 * determine the view position
 */
void MainWindow::viewPositon(int index)
{
    switch(index)
    {
    case 0:
        ui->widget_2->view_changed = false;
        ui->widget_2->view_to_default = true;
        ui->widget_2->view_to_moon    = false;
        ui->widget_2->view_to_mercury = false;
        ui->widget_2->view_to_venus   = false;
        ui->widget_2->view_to_earth   = false;
        ui->widget_2->view_to_mars    = false;
        ui->widget_2->view_to_jupiter = false;
        ui->widget_2->view_to_saturn  = false;
        ui->widget_2->view_to_uranus  = false;
        ui->widget_2->view_to_neptune = false;

        // reset
        ui->widget_2->to_x  = 0;
        ui->widget_2->to_y  = 0;
        ui->widget_2->to_z  = 0;

        ui->widget_2->updateGL();
        break;
    case 1:
        ui->widget_2->view_changed = true;
        ui->widget_2->view_to_default = false;
        ui->widget_2->view_to_moon    = true;
        ui->widget_2->view_to_mercury = false;
        ui->widget_2->view_to_venus   = false;
        ui->widget_2->view_to_earth   = false;
        ui->widget_2->view_to_mars    = false;
        ui->widget_2->view_to_jupiter = false;
        ui->widget_2->view_to_saturn  = false;
        ui->widget_2->view_to_uranus  = false;
        ui->widget_2->view_to_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 2:
        ui->widget_2->view_changed = true;
        ui->widget_2->view_to_default = false;
        ui->widget_2->view_to_moon    = false;
        ui->widget_2->view_to_mercury = true;
        ui->widget_2->view_to_venus   = false;
        ui->widget_2->view_to_earth   = false;
        ui->widget_2->view_to_mars    = false;
        ui->widget_2->view_to_jupiter = false;
        ui->widget_2->view_to_saturn  = false;
        ui->widget_2->view_to_uranus  = false;
        ui->widget_2->view_to_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 3:
        ui->widget_2->view_changed = true;
        ui->widget_2->view_to_default = false;
        ui->widget_2->view_to_moon    = false;
        ui->widget_2->view_to_mercury = false;
        ui->widget_2->view_to_venus   = true;
        ui->widget_2->view_to_earth   = false;
        ui->widget_2->view_to_mars    = false;
        ui->widget_2->view_to_jupiter = false;
        ui->widget_2->view_to_saturn  = false;
        ui->widget_2->view_to_uranus  = false;
        ui->widget_2->view_to_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 4:
        ui->widget_2->view_changed = true;
        ui->widget_2->view_to_default = false;
        ui->widget_2->view_to_moon    = false;
        ui->widget_2->view_to_mercury = false;
        ui->widget_2->view_to_venus   = false;
        ui->widget_2->view_to_earth   = true;
        ui->widget_2->view_to_mars    = false;
        ui->widget_2->view_to_jupiter = false;
        ui->widget_2->view_to_saturn  = false;
        ui->widget_2->view_to_uranus  = false;
        ui->widget_2->view_to_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 5:
        ui->widget_2->view_changed = true;
        ui->widget_2->view_to_default = false;
        ui->widget_2->view_to_moon    = false;
        ui->widget_2->view_to_mercury = false;
        ui->widget_2->view_to_venus   = false;
        ui->widget_2->view_to_earth   = false;
        ui->widget_2->view_to_mars    = true;
        ui->widget_2->view_to_jupiter = false;
        ui->widget_2->view_to_saturn  = false;
        ui->widget_2->view_to_uranus  = false;
        ui->widget_2->view_to_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 6:
        ui->widget_2->view_changed = true;
        ui->widget_2->view_to_default = false;
        ui->widget_2->view_to_moon    = false;
        ui->widget_2->view_to_mercury = false;
        ui->widget_2->view_to_venus   = false;
        ui->widget_2->view_to_earth   = false;
        ui->widget_2->view_to_mars    = false;
        ui->widget_2->view_to_jupiter = true;
        ui->widget_2->view_to_saturn  = false;
        ui->widget_2->view_to_uranus  = false;
        ui->widget_2->view_to_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 7:
        ui->widget_2->view_changed = true;
        ui->widget_2->view_to_default = false;
        ui->widget_2->view_to_moon    = false;
        ui->widget_2->view_to_mercury = false;
        ui->widget_2->view_to_venus   = false;
        ui->widget_2->view_to_earth   = false;
        ui->widget_2->view_to_mars    = false;
        ui->widget_2->view_to_jupiter = false;
        ui->widget_2->view_to_saturn  = true;
        ui->widget_2->view_to_uranus  = false;
        ui->widget_2->view_to_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 8:
        ui->widget_2->view_changed = true;
        ui->widget_2->view_to_default = false;
        ui->widget_2->view_to_moon    = false;
        ui->widget_2->view_to_mercury = false;
        ui->widget_2->view_to_venus   = false;
        ui->widget_2->view_to_earth   = false;
        ui->widget_2->view_to_mars    = false;
        ui->widget_2->view_to_jupiter = false;
        ui->widget_2->view_to_saturn  = false;
        ui->widget_2->view_to_uranus  = true;
        ui->widget_2->view_to_neptune = false;

        ui->widget_2->updateGL();
        break;
    case 9:
        ui->widget_2->view_changed = true;
        ui->widget_2->view_to_default = false;
        ui->widget_2->view_to_moon    = false;
        ui->widget_2->view_to_mercury = false;
        ui->widget_2->view_to_venus   = false;
        ui->widget_2->view_to_earth   = false;
        ui->widget_2->view_to_mars    = false;
        ui->widget_2->view_to_jupiter = false;
        ui->widget_2->view_to_saturn  = false;
        ui->widget_2->view_to_uranus  = false;
        ui->widget_2->view_to_neptune = true;

        ui->widget_2->updateGL();
        break;
    default:
        ui->widget_2->view_changed = false;
        ui->widget_2->view_to_default = true;
        ui->widget_2->view_to_moon    = false;
        ui->widget_2->view_to_mercury = false;
        ui->widget_2->view_to_venus   = false;
        ui->widget_2->view_to_earth   = false;
        ui->widget_2->view_to_mars    = false;
        ui->widget_2->view_to_jupiter = false;
        ui->widget_2->view_to_saturn  = false;
        ui->widget_2->view_to_uranus  = false;
        ui->widget_2->view_to_neptune = false;

        // reset
        ui->widget_2->to_x  = 0;
        ui->widget_2->to_y  = 0;
        ui->widget_2->to_z  = 0;

        ui->widget_2->updateGL();
        break;
    }
}


/**
  * show about
  */
void MainWindow::showAbout()
{
    aboutform = new About();
    aboutform->show();
}

void MainWindow::showHotkey()
{
    hotkeyform = new Hotkey();
    hotkeyform->show();
}


/**
  * show advice
  */
void MainWindow::showAdvice()
{
    adviceform = new Advice();
    adviceform->show();
}

/**
  * shwo help
  */
void MainWindow::showHelp()
{
    QUrl url("help.chm");
    QDesktopServices::openUrl(url);

}

/**
  * show the palnet or not
  */
void MainWindow::on_actionToogle_Mercury_triggered()
{
    ui->widget_2->solar->mercury = !ui->widget_2->solar->mercury;
}

/**
  * show the palnet or not
  */
void MainWindow::on_actionVenus_triggered()
{
    ui->widget_2->solar->venus = !ui->widget_2->solar->venus;
}

/**
  * show the palnet or not
  */
void MainWindow::on_actionEarth_triggered()
{
    ui->widget_2->solar->earth = !ui->widget_2->solar->earth;
}

/**
  * show the palnet or not
  */
void MainWindow::on_actionMoon_triggered()
{
    ui->widget_2->solar->moon = !ui->widget_2->solar->moon;
}

/**
  * show the palnet or not
  */
void MainWindow::on_actionMars_triggered()
{
    ui->widget_2->solar->mars = !ui->widget_2->solar->mars;
}

/**
  * show the palnet or not
  */
void MainWindow::on_actionJupiter_triggered()
{
    ui->widget_2->solar->jupiter = !ui->widget_2->solar->jupiter;
}

/**
  * show the palnet or not
  */
void MainWindow::on_actionNeptune_triggered()
{
    ui->widget_2->solar->neptune = !ui->widget_2->solar->neptune;
}

/**
  * show the palnet or not
  */
void MainWindow::on_actionSaturn_triggered()
{
    ui->widget_2->solar->saturn = !ui->widget_2->solar->saturn;
}

/**
  * show the palnet or not
  */
void MainWindow::on_actionUranus_triggered()
{
    ui->widget_2->solar->uranus = !ui->widget_2->solar->uranus;
}

/**
  * show the palnet cirle or not
  */
void MainWindow::on_actionMercury_triggered()
{
    ui->widget_2->solar->mercury_line = !ui->widget_2->solar->mercury_line;
}

/**
  * show the palnet cirle or not
  */
void MainWindow::on_actionVenus_2_triggered()
{
    ui->widget_2->solar->venus_line = !ui->widget_2->solar->venus_line;
}

/**
  * show the palnet cirle or not
  */
void MainWindow::on_actionEarth_2_triggered()
{
    ui->widget_2->solar->earth_line = !ui->widget_2->solar->earth_line;
}

/**
  * show the palnet cirle or not
  */
void MainWindow::on_actionMoon_2_triggered()
{
    ui->widget_2->solar->moon_line = !ui->widget_2->solar->moon_line;
}

/**
  * show the palnet cirle or not
  */
void MainWindow::on_actionMars_2_triggered()
{
    ui->widget_2->solar->mars_line = !ui->widget_2->solar->mars_line;
}

/**
  * show the palnet cirle or not
  */
void MainWindow::on_actionJupiter_2_triggered()
{
    ui->widget_2->solar->jupiter_line = !ui->widget_2->solar->jupiter_line;
}

/**
  * show the palnet cirle or not
  */
void MainWindow::on_actionSaturn_2_triggered()
{
    ui->widget_2->solar->saturn_line = !ui->widget_2->solar->saturn_line;
}

/**
  * show the palnet cirle or not
  */
void MainWindow::on_actionNeptune_2_triggered()
{
    ui->widget_2->solar->neptune_line = !ui->widget_2->solar->neptune_line;
}

/**
  * show the palnet cirle or not
  */
void MainWindow::on_actionUranus_2_triggered()
{
    ui->widget_2->solar->uranus_line = !ui->widget_2->solar->uranus_line;
}

/**
  * show the about form to introduce
  */
void MainWindow::on_actionAbout_triggered()
{
    aboutform = new About();
    aboutform->show();
}

/**
  * show the acvice form to provide some infomation
  */
void MainWindow::on_actionHelp_triggered()
{
    adviceform = new Advice();
    adviceform->show();
}

/**
  * show the hot key list to help the users
  */
void MainWindow::on_actionHot_Key_List_triggered()
{
    hotkeyform = new Hotkey();
    hotkeyform->show();
}

/**
  * determine which system to show
  */
void MainWindow::on_actionSolar_triggered()
{
    ui->widget_2->changeModel = true;
}

/**
  * determine which system to show
  */
void MainWindow::on_actionSun_Earth_Moon_triggered()
{
    ui->widget_2->changeModel = false;
}

/**
  * determine if eclipse notice will be raised.
  */
void MainWindow::on_actionEclipse_triggered()
{
    ui->widget_2->watchEclipse = !ui->widget_2->watchEclipse;
    if(ui->widget_2->watchEclipse)
    {
        showMessage->setText("We will stop when eclipse happen.");
        showMessage->show();
    }
    else
    {
        showMessage->setText("Eclipse notice has been concelled.");
        showMessage->show();
    }
}

/**
  * determine if planetary aligments notice will be raised.
  */
void MainWindow::on_actionPlanetary_Alignments_triggered()
{
    ui->widget_2->watchStars = !ui->widget_2->watchStars;
    if(ui->widget_2->watchStars)
    {
        showMessage->setText("We will stop when planetary alignments happen.");
        showMessage->show();
    }
    else
    {
        showMessage->setText("Planetary alignment notice has been concelled.");
        showMessage->show();
    }
}

/**
  * determine if notice the next message.
  */
void MainWindow::on_actionNext_Notice_triggered()
{
    ui->widget_2->flag = false;
}
