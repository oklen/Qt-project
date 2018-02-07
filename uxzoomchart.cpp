#include "uxzoomchart.h"
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGestureEvent>
#include <QtWidgets/QGraphicsView>
#include <QCategoryAxis>
#include <QDebug>

UXZOOMCHART::UXZOOMCHART(QGraphicsItem *parent ,Qt::WindowFlags wFlags) :
    QChart(QChart::ChartTypeCartesian,parent,wFlags),
    mytext{new QGraphicsSimpleTextItem(this)}
{
    grabGesture(Qt::PanGesture);
    grabGesture(Qt::PinchGesture);
    setPlotAreaBackgroundBrush(QBrush(QColor("#4a484d")));
    setPlotAreaBackgroundVisible(true);

    setBackgroundBrush(QBrush(QColor("#4c4c4c")));

//    QCategoryAxis *axisX = new QCategoryAxis;
//    QCategoryAxis *axisY = new QCategoryAxis;

//    QFont labelsFont;
//    labelsFont.setPixelSize(12);


//    axisX->setLabelsFont(labelsFont);
//    axisY->setLabelsFont(labelsFont);


//    // Customize axis colors
//    QPen axisPen(QColor(255,255,255,70));
//    axisPen.setWidth(2);
//    axisX->setLinePen(axisPen);
//    axisY->setLinePen(axisPen);

//    // Customize axis label colors
//    QBrush axisBrush(Qt::white);
////    axisX()->setLabelsBrush(axisBrush);
////    axisY()->setLabelsBrush(axisBrush);

//    // Customize grid lines and shades
//    axisX->setGridLineVisible(true);
//    axisY->setGridLineVisible(true);
//    axisX->setGridLineColor(QColor(255,255,255,70));
//    axisY->setGridLineColor(QColor(255,255,255,70));

//    setAxisX(axisX);
//    setAxisY(axisY);
}

UXZOOMCHART::~UXZOOMCHART()
{

}

bool UXZOOMCHART::sceneEvent(QEvent *event)
{
    if(event->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent*>(event));
    return QChart::event(event);
}

bool UXZOOMCHART::gestureEvent(QGestureEvent *event)
{
    if(QGesture *gesture = event->gesture(Qt::PanGesture)){
        QPanGesture *pan = static_cast<QPanGesture*>(gesture);
        QChart::scroll(-(pan->delta().x()),pan->delta().y());
    }

    if (QGesture *gesture = event->gesture(Qt::PinchGesture)) {
        QPinchGesture *pinch = static_cast<QPinchGesture *>(gesture);
        if (pinch->changeFlags() & QPinchGesture::ScaleFactorChanged)
            QChart::zoom(pinch->scaleFactor());
    }

    return true;
}

void UXZOOMCHART::mouseMoveEvent(QMouseEvent *event)
{

}
