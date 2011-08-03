#include "hotkey.h"
#include "ui_hotkey.h"

Hotkey::Hotkey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hotkey)
{
    ui->setupUi(this);
}

Hotkey::~Hotkey()
{
    delete ui;
}
