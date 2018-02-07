#ifndef UX3DW_H
#define UX3DW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QPainter>
#include <QPixmap>
#include <QLinearGradient>
#include <QLabel>
#include <QSpacerItem>
#include <QPaintEvent>
#include <QVector3D>

#include "components/qtmaterialiconbutton.h"
#include "components/qtmaterialprogress.h"
#include "components/qtmaterialraisedbutton.h"
#include "components/qtmaterialtoggle.h"
#include "components/qtmaterialslider.h"
#include "/media/root/LENOVO/WpSystem/Qt_project/OpenGL/uxdatav.h"
#include "/media/root/LENOVO/WpSystem/Qt_project/painters/uxwidget.h"

/******************
 * Provide the 3d window
 * and UI
 * *****/

class UX3DW : public QFrame
{
    Q_OBJECT
public:
    explicit UX3DW(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); //Not Used
    QtMaterialToggle *toggle; //Slice Analysis toggle button
    QLabel *colorbar; // 调色板
    QHBoxLayout *h3layout; //The container to contain or remove the chart


    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void setxyz(); //Acitve the point to Catch Line Data

    QLabel *d3replacer; // screenshot image container to replace the d3 window
    QWidget *pointer; //pointer point to the d3 window
    QPoint hotpot;    // Mouse press position relative the parent widget
    UXDatav *modifier; // Class to modify the 3D model
    UXWidget *selector; //Provide the line data show
    UXZOOMCHART *chart; // the interal chart
    UXZOOMCHARTVIEW *chartview; // the interal chart container
    Q3DSurface *graph = new Q3DSurface(); // Qt Class to show 3D data model

    QHBoxLayout *h1layout = new QHBoxLayout; //3D Window and colorbar horizontal layout

//    QWidget *container = new QWidget;
    bool mousedown = false; // Whether the mouse button is pressed

    int xr = 0; //store x rotation degree
    int yr = 0; //store y rotation degree
    int zoom = 100; // store zoom data
    int mainwindowid; // store mainwindowid
signals:

public slots:
    void changetoggle(bool checked); //set the toggle status
    void hidechart(); // hide the chart
    void windowswap(); //swap the cahce image and d3 window
    void enablechart(); // toggler to expand the chart
    void rotatex(int rotation); //rotate the model x degree
    void rotatey(int rotation); //rotate the model y degree
    void zoomto(int zoom); // zoom to zoom level
    void hided3(); //hide the 3d window

};

#endif // UX3DW_H
