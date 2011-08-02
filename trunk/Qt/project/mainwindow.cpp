#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    connect(ui->widget_2,SIGNAL(date_updated(int)),this,SLOT(refreshTime(int)));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(keepTime()));
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
        ui->widget_2->solar->neptune_line_color[1] = 0;
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
