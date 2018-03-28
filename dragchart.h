#ifndef DRAGCHART_H
#define DRAGCHART_H
//***************************************************************
//Decrepted class don't use it!
//***************************************************************
#include <QObject>
#include <QDrag>
#include <QMouseEvent>
#include <QLabel>
#include <QPixmap>
#include <QMimeData>
#include <QChartView>
#include <QBoxPlotSeries>
#include <QLayout>


QT_CHARTS_USE_NAMESPACE

class DRAGCHART : public QChartView
{
    Q_OBJECT
public:
    explicit DRAGCHART(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void move(QPoint point);
    void canceldrag();
    QDrag* setdrag();
    bool ondrag = false;
    QPoint hotpot;
    QDrag *savedrag;

signals:

public slots:
};

#endif // DRAGCHART_H
