#include "uxdlc.h"

UXDLC::UXDLC(QWidget *parent) : QChartView(parent)
//    ,gpix{new QGraphicsPixmapItem(this)}
{
    UXDL *chart = new UXDL;
    chart->setTitle("Dynamic spline chart");
    chart->legend();
    chart->axisX()->setLabelsFont(QFont("Arial Unicode MS",9));
    chart->axisY()->setLabelsFont(QFont("Arial Unicode MS",9));
    chart->axisX()->setTitleText("Time");
    chart->axisY()->setTitleText("futer");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    setChart(chart);
    setRenderHint(QPainter::Antialiasing);
    setAutoFillBackground(true);

}

void UXDLC::mousePressEvent(QMouseEvent *event)
{
    emit bepressed();
    raise();
        mousedown = true;
        hotpot = event->pos();
}

void UXDLC::mouseReleaseEvent(QMouseEvent *event)
{

    qDebug() << "Child Release";
    mousedown = false;

}

void UXDLC::mouseMoveEvent(QMouseEvent *event)
{
    if (mousedown && QRect(0,0,1000,800).contains(this->pos()+event->pos()-hotpot)){
        qDebug() << "Move!";
        this->move(this->pos()+event->pos()-hotpot);
    }
    else
    {
        if(mousedown && QRect(0,0,1000,800).contains(this->pos()
                                                     +QPoint((event->pos()-hotpot).x(),0)))
            this->move(this->pos()+QPoint((event->pos()-hotpot).x(),0));
        if(mousedown && QRect(0,0,1000,800).contains(this->pos()
                                                     +QPoint(0,(event->pos()-hotpot).y())))
            this->move(this->pos()+QPoint(0,(event->pos()-hotpot).y()));
    }
    qDebug() << "this pos:" << this->pos() << " "
             << "event pos:" << event->pos() << " "
             << "hotpot:" << hotpot;
}
