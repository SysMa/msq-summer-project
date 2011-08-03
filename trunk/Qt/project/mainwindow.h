#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
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

};

#endif // MAINWINDOW_H
