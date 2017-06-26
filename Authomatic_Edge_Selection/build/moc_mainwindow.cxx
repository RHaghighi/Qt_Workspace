/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../EdgeSelection/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      58,   11,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,
     114,   11,  110,   11, 0x08,
     144,   11,   11,   11, 0x08,
     182,  170,   11,   11, 0x08,
     261,  247,   11,   11, 0x08,
     324,   11,   11,   11, 0x08,
     365,   11,   11,   11, 0x08,
     406,   11,   11,   11, 0x08,
     429,   11,   11,   11, 0x08,
     459,  454,   11,   11, 0x08,
     496,  454,   11,   11, 0x08,
     533,  454,   11,   11, 0x08,
     570,  454,   11,   11, 0x08,
     607,  454,   11,   11, 0x08,
     644,  454,   11,   11, 0x08,
     681,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_Load_PCD_clicked()\0"
    "on_Clear_List_clicked()\0on_Compute_clicked()\0"
    "on_Start_Live_Stream_clicked()\0int\0"
    "on_Stop_Live_Stream_clicked()\0"
    "on_actionOpen_triggered()\0eventp,args\0"
    "pointPickingOccured(pcl::visualization::PointPickingEvent,void*)\0"
    "event,nothing\0"
    "keyboardEventOccurred(pcl::visualization::KeyboardEvent,void*)\0"
    "on_pushButton_Quaternion2Euler_clicked()\0"
    "on_pushButton_Euler2Quaternion_clicked()\0"
    "on_Update_SB_clicked()\0on_Edge_Detect_clicked()\0"
    "arg1\0on_Filter_x_pos_valueChanged(double)\0"
    "on_Filter_x_neg_valueChanged(double)\0"
    "on_Filter_y_pos_valueChanged(double)\0"
    "on_Filter_y_neg_valueChanged(double)\0"
    "on_Filter_z_pos_valueChanged(double)\0"
    "on_Filter_z_neg_valueChanged(double)\0"
    "on_Filter_Edge_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_Load_PCD_clicked(); break;
        case 1: _t->on_Clear_List_clicked(); break;
        case 2: _t->on_Compute_clicked(); break;
        case 3: _t->on_Start_Live_Stream_clicked(); break;
        case 4: { int _r = _t->on_Stop_Live_Stream_clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: _t->on_actionOpen_triggered(); break;
        case 6: _t->pointPickingOccured((*reinterpret_cast< const pcl::visualization::PointPickingEvent(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2]))); break;
        case 7: _t->keyboardEventOccurred((*reinterpret_cast< const pcl::visualization::KeyboardEvent(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2]))); break;
        case 8: _t->on_pushButton_Quaternion2Euler_clicked(); break;
        case 9: _t->on_pushButton_Euler2Quaternion_clicked(); break;
        case 10: _t->on_Update_SB_clicked(); break;
        case 11: _t->on_Edge_Detect_clicked(); break;
        case 12: _t->on_Filter_x_pos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->on_Filter_x_neg_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->on_Filter_y_pos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->on_Filter_y_neg_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->on_Filter_z_pos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->on_Filter_z_neg_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->on_Filter_Edge_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
