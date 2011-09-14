/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Sep 14 15:29:51 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../project/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x0a,
      30,   11,   11,   11, 0x0a,
      47,   11,   11,   11, 0x0a,
      58,   11,   11,   11, 0x0a,
      78,   11,   11,   11, 0x0a,
      95,   11,   11,   11, 0x0a,
     107,   11,   11,   11, 0x0a,
     120,   11,   11,   11, 0x0a,
     133,   11,   11,   11, 0x0a,
     144,   11,   11,   11, 0x08,
     180,   11,   11,   11, 0x08,
     207,   11,   11,   11, 0x08,
     234,   11,   11,   11, 0x08,
     260,   11,   11,   11, 0x08,
     286,   11,   11,   11, 0x08,
     315,   11,   11,   11, 0x08,
     344,   11,   11,   11, 0x08,
     372,   11,   11,   11, 0x08,
     400,   11,   11,   11, 0x08,
     429,   11,   11,   11, 0x08,
     458,   11,   11,   11, 0x08,
     487,   11,   11,   11, 0x08,
     515,   11,   11,   11, 0x08,
     543,   11,   11,   11, 0x08,
     574,   11,   11,   11, 0x08,
     604,   11,   11,   11, 0x08,
     635,   11,   11,   11, 0x08,
     665,   11,   11,   11, 0x08,
     692,   11,   11,   11, 0x08,
     718,   11,   11,   11, 0x08,
     752,   11,   11,   11, 0x08,
     779,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0i\0showPlanet(int)\0"
    "refreshTime(int)\0keepTime()\0"
    "cameraPosition(int)\0viewPositon(int)\0"
    "showAbout()\0showHotkey()\0showAdvice()\0"
    "showHelp()\0on_actionToogle_Mercury_triggered()\0"
    "on_actionVenus_triggered()\0"
    "on_actionEarth_triggered()\0"
    "on_actionMoon_triggered()\0"
    "on_actionMars_triggered()\0"
    "on_actionJupiter_triggered()\0"
    "on_actionNeptune_triggered()\0"
    "on_actionSaturn_triggered()\0"
    "on_actionUranus_triggered()\0"
    "on_actionMercury_triggered()\0"
    "on_actionVenus_2_triggered()\0"
    "on_actionEarth_2_triggered()\0"
    "on_actionMoon_2_triggered()\0"
    "on_actionMars_2_triggered()\0"
    "on_actionJupiter_2_triggered()\0"
    "on_actionSaturn_2_triggered()\0"
    "on_actionNeptune_2_triggered()\0"
    "on_actionUranus_2_triggered()\0"
    "on_actionAbout_triggered()\0"
    "on_actionHelp_triggered()\0"
    "on_actionHot_Key_List_triggered()\0"
    "on_actionSolar_triggered()\0"
    "on_actionSun_Earth_Moon_triggered()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showPlanet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: refreshTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: keepTime(); break;
        case 3: cameraPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: viewPositon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: showAbout(); break;
        case 6: showHotkey(); break;
        case 7: showAdvice(); break;
        case 8: showHelp(); break;
        case 9: on_actionToogle_Mercury_triggered(); break;
        case 10: on_actionVenus_triggered(); break;
        case 11: on_actionEarth_triggered(); break;
        case 12: on_actionMoon_triggered(); break;
        case 13: on_actionMars_triggered(); break;
        case 14: on_actionJupiter_triggered(); break;
        case 15: on_actionNeptune_triggered(); break;
        case 16: on_actionSaturn_triggered(); break;
        case 17: on_actionUranus_triggered(); break;
        case 18: on_actionMercury_triggered(); break;
        case 19: on_actionVenus_2_triggered(); break;
        case 20: on_actionEarth_2_triggered(); break;
        case 21: on_actionMoon_2_triggered(); break;
        case 22: on_actionMars_2_triggered(); break;
        case 23: on_actionJupiter_2_triggered(); break;
        case 24: on_actionSaturn_2_triggered(); break;
        case 25: on_actionNeptune_2_triggered(); break;
        case 26: on_actionUranus_2_triggered(); break;
        case 27: on_actionAbout_triggered(); break;
        case 28: on_actionHelp_triggered(); break;
        case 29: on_actionHot_Key_List_triggered(); break;
        case 30: on_actionSolar_triggered(); break;
        case 31: on_actionSun_Earth_Moon_triggered(); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
