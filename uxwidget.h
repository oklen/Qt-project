#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QtCharts>
#include "uxzoomchart.h"
#include "uxzoomchartview.h"
/****************************************************************
 * The Core container of the Algorithm to get the line
 * after select two points.It is use by the 3d and the forcew
 ******/

namespace Ui {
class UXWidget;
}

class UXWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UXWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void manualactive(QPoint xy);
    int getINT(double a);
    UXZOOMCHART* getchart();
    ~UXWidget();


    QVector<int> vectory;
    QVector<int> vectorx;
    QVector<qreal>* vectorz;
private:
//    Ui::UXWidget *ui;
    QPoint pos;
    QPoint pos2;
    UXZOOMCHART *chart;
    int stage;
};

#endif // WIDGET_H
