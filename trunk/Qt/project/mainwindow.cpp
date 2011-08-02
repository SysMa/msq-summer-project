#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(showPlanet(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

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
