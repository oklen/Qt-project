/************************************
 * The container of the zoom chart
 * **********************************/

#ifndef ZOOMCHARTVIEW_H
#define ZOOMCHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>
#include "uxzoomchart.h"

QT_CHARTS_USE_NAMESPACE

class UXZOOMCHARTVIEW : public QChartView
{
    Q_OBJECT
public:
    explicit UXZOOMCHARTVIEW(UXZOOMCHART *chart,QWidget *parent = nullptr);
    QVector<qreal>* yvalue;

    //Enable levis is used to show the data cursor,be sure to it on.

    void enablevis(); //bool to determine whether to show cursor

protected:
    bool viewportEvent(QEvent *event); // unused
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void keyPressEvent(QKeyEvent *event); // catch key pressed


//    QGraphicsSimpleTextItem *debugtext;
    QGraphicsSimpleTextItem *debugtext2; // moing text to show current data
    QPixmap *pix; //red pix used in cursor
    QGraphicsPixmapItem *gpix; // pix container (cursor)
//    QGraphicsPixmapItem *gpix;


private:
    bool m_isTouching; // not used
    bool datacursor = false; //ineral bool to tell whether should show cursor
};

#endif // ZOOMCHARTVIEW_H
