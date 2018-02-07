#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "uxava.h"
#include "ux3dw.h"
#include "uxforcew.h"
#include "uxautop.h"

static bool optMultipleSample = false;
static bool optCoreProfile = false;

class UXMainWindow : public QMainWindow {
    Q_OBJECT
public:
    UXMainWindow();
//    void closeEvent(QCloseEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    UXAVA *menubutton = new UXAVA; // Menu button
    UX3DW *my3d = new UX3DW; //Menu
    UXAUTOP *autop = new UXAUTOP; //CCD container
    UXFORCEW *forw = new UXFORCEW; // force imaging


//    bool toclose = false;


private:


public slots:
    void showoptical(); // show CCD window
    void showforcew(); // show force window
    void showd3(); // show 3d window

};
#endif // MAINWINDOW_H
