#include "dragchart.h"
#include "/media/root/LENOVO/WpSystem/qt_project/Select_Area/fc.h"
#include <QDebug>

DRAGCHART::DRAGCHART(QWidget *parent) : QChartView(parent),
    hotpot{QPoint(0,0)},savedrag{new QDrag(this)}
{

}

void DRAGCHART::mousePressEvent(QMouseEvent *event)
{

    FC *myparent = static_cast<FC*>(parent());
    myparent->getchild(this);
    myparent->mychartchild->move(this->pos());
    QPixmap *pix = new QPixmap;
    qDebug() << "Finding " << this->pos() << " " << this->size();
    this->raise();
    *pix = QWidget::grab(QRect(QPoint(0,0),this->size()));

    QMimeData *mime = new QMimeData;
    mime->setImageData(pix->toImage());

    this->setVisible(false);
    QDrag *drag = new QDrag(this);
    drag->setPixmap(*pix);
    drag->setMimeData(mime);
    drag->setHotSpot(event->pos());
    hotpot = drag->hotSpot();
    this->move(this->pos());
    this->show();
    savedrag = drag;

    qDebug() << "Size:" << size();
    if(size()!=QSize(1,1))
    {
        resize(1,1);
        qDebug() << "Size:" << size();
    }
    else{
        resize(QSize(300,300));
    }
    drag->exec(Qt::MoveAction);
    qDebug() << "Drag!";
    resize(QSize(300,300));

}

void DRAGCHART::mouseReleaseEvent(QMouseEvent *event)
{

    qDebug() << "Child Release";
    if(size() == QSize(1,1))
        resize(300,300);
    chart()->show();
}

void DRAGCHART::mouseMoveEvent(QMouseEvent *event)
{

}

void DRAGCHART::move(QPoint point)
{
    setGeometry(QRect(point,this->size()));
}

void DRAGCHART::canceldrag()
{
    savedrag->cancel();
}

QDrag* DRAGCHART::setdrag()
{
    return savedrag;
}
