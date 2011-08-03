#include "advice.h"
#include "ui_advice.h"

Advice::Advice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Advice)
{
    ui->setupUi(this);
}

Advice::~Advice()
{
    delete ui;
}
