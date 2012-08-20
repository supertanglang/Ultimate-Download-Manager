#ifndef MISCFUNCTIONS_H
#define MISCFUNCTIONS_H

#include "wgetprocess.h"
#include <QMainWindow>
#include "ui_mainwindow.h"

class MiscFunctions
{
public:
    inline static void connectWgetAndMainWindow(const WgetProcess *wp, QMainWindow *mw)
    {
        QObject::connect(wp, SIGNAL(lengthChanged(WgetProgressObject *const)), mw, SLOT(setLength(WgetProgressObject* const)));
        QObject::connect(wp, SIGNAL(wgetStatusChanged(WgetProgressObject *const)), mw, SLOT(setStatus(WgetProgressObject *const)));
        QObject::connect(wp, SIGNAL(progressChanged(WgetProgressObject *const)), mw, SLOT(setProgress(WgetProgressObject* const)));
        QObject::connect(wp, SIGNAL(speedChanged(WgetProgressObject* const)), mw, SLOT(setSpeed(WgetProgressObject* const)));
        QObject::connect(wp, SIGNAL(timeChanged(WgetProgressObject* const)), mw, SLOT(setTime(WgetProgressObject* const)));
    }
    inline static void stopButtonChange(bool enable, Ui::MainWindow *ui)
    {
        ui->pushButton_2->setEnabled(enable);
        ui->btnStartPause->setEnabled(enable);
        ui->btnDelete->setEnabled(!enable);
    }
};

#endif // MISCFUNCTIONS_H
