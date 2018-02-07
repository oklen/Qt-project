#ifndef UXFORCEW_H
#define UXFORCEW_H
/*************************
 * Used to contain force imaging
 * *******/
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

#include "components/qtmaterialiconbutton.h"
#include "components/qtmaterialprogress.h"
#include "components/qtmaterialraisedbutton.h"
#include "components/qtmaterialtoggle.h"
#include "/media/root/LENOVO/WpSystem/Qt_project/painters/uxwidget.h"
#include "uxzoomchart.h"
#include "uxzoomchartview.h"

class UXFORCEW : public QFrame
{
    Q_OBJECT
public:
    explicit UXFORCEW(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);    //empty event
    QtMaterialToggle *toggle;               //toggler to expand the chart analysis
    UXZOOMCHARTVIEW *childchart;            //chart container
    QHBoxLayout *h2layoutr;
    QLabel *colorbar;

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    //below two are same as
    //and explain in other class
    QPoint hotpot;
    bool mousedown = false;

signals:
    void bepressed();
public slots:
    void changetoggle(bool checked);
    void hidechart();
    void enablechart();
};

#endif // UXFORCEW_H
