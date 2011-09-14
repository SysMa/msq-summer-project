#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QMessageBox>
#include "about.h"
#include "hotkey.h"
#include "advice.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    About* aboutform;
    Hotkey* hotkeyform;
    Advice* adviceform;
    QMessageBox* showMessage;

public slots:
    /**
     * deal with which palnet to show
     */
    void showPlanet(int i);

    /**
      * make the time and the widget time the same
      */
    void refreshTime(int);
    void keepTime();

    /**
     * deal with camera positon
     */
    void cameraPosition(int);

    /**
      * deal with the center position
      */
    void viewPositon(int);

    /**
      * show about form
      */
    void showAbout();

    /**
      * show the hot keys
      */
    void showHotkey();

    /**
      * show suggestions
      */
    void showAdvice();

    /**
      * SHOW HELP
      */
    void showHelp();

private slots:
    void on_actionToogle_Mercury_triggered();
    void on_actionVenus_triggered();
    void on_actionEarth_triggered();
    void on_actionMoon_triggered();
    void on_actionMars_triggered();
    void on_actionJupiter_triggered();
    void on_actionNeptune_triggered();
    void on_actionSaturn_triggered();
    void on_actionUranus_triggered();
    void on_actionMercury_triggered();
    void on_actionVenus_2_triggered();
    void on_actionEarth_2_triggered();
    void on_actionMoon_2_triggered();
    void on_actionMars_2_triggered();
    void on_actionJupiter_2_triggered();
    void on_actionSaturn_2_triggered();
    void on_actionNeptune_2_triggered();
    void on_actionUranus_2_triggered();
    void on_actionAbout_triggered();
    void on_actionHelp_triggered();
    void on_actionHot_Key_List_triggered();
    void on_actionSolar_triggered();
    void on_actionSun_Earth_Moon_triggered();
    void on_actionEclipse_triggered();
    void on_actionPlanetary_Alignments_triggered();
    void on_actionNext_Notice_triggered();
};

#endif // MAINWINDOW_H
