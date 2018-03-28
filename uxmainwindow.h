#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "uxava.h"
#include "ux3dw.h"
#include "uxforcew.h"
#include "uxautop.h"
#include "uxdlc.h"
#include "uxmbg.h"
#include "uxccdper.h"
#include "uxpepiserver.h"

static bool optMultipleSample = true;
static bool optCoreProfile = false;

class UXMainWindow : public QMainWindow {
    Q_OBJECT
public:
    UXMainWindow();
        UXCCDPERX *per; //CCD display window
//    void closeEvent(QCloseEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    UXAVA menubutton; // Menu button
    UX3DW *my3d = new UX3DW; //Menu
    UXAUTOP autop; //CCD container
    UXFORCEW *forw = new UXFORCEW; // force imaging
    UXDLC *dl = new UXDLC; //Dynamic Data Spline chart
    UXMBG *bg = new UXMBG; //MainWindow centeral widget
    UXPIPESERVER server;


//    void paintEvent(QPaintEvent *event);

//    bool toclose = false;


private:
    bool dlcshowed = false;
    QFrame *centralWidget_f;




public slots:
    void showoptical(); // show CCD window
    void showforcew(); // show force window
    void showd3(); // show 3d window
    void showdlc(); // show dynamic line window
    void hidedlc();
    void initCCD();
};
#endif // MAINWINDOW_H
