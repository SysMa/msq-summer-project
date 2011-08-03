#ifndef HOTKEY_H
#define HOTKEY_H

#include <QDialog>

namespace Ui {
    class Hotkey;
}

class Hotkey : public QDialog
{
    Q_OBJECT

public:
    explicit Hotkey(QWidget *parent = 0);
    ~Hotkey();

private:
    Ui::Hotkey *ui;
};

#endif // HOTKEY_H
