/********************************
 * The class used to implement the
 * zoom chart
 * **************************/

#ifndef ZOOMCHART_H
#define ZOOMCHART_H

#include <QtCharts/QChart>
#include <QMouseEvent>
#include <QVector>

QT_USE_NAMESPACE
class QGestureEvent;
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class UXZOOMCHART : public QChart
{
    Q_OBJECT

public:
    explicit UXZOOMCHART(QGraphicsItem *parent = 0,Qt::WindowFlags wFlag=0);
    ~UXZOOMCHART();
    QGraphicsSimpleTextItem *mytext; // the cursor to show where is be selected

    QVector<int> vectory; //vector to store y axis data
    QVector<int> vectorx; //vector to store x axis data

    void mouseMoveEvent(QMouseEvent *event);
protected:
    bool sceneEvent(QEvent *event); // used to catch user opearation and convey it to chart

private:
    bool gestureEvent(QGestureEvent *event); //perform chart move and zoom

signals:

public slots:
};

#endif // ZOOMCHART_H
