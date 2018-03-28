#include "uxcb.h"

#include "uxcb.h"

UXCB::UXCB(QWidget *parent) : QWidget(parent)
{
    resize(20,20);
    installEventFilter(this);
    setFixedSize(20,20);
}

void UXCB::paintEvent(QPaintEvent *event)
{
    QPainter *mypainter = new QPainter(this);
    mypainter->setRenderHint(QPainter::Antialiasing);
    if(mouseenter)
    {
        mypainter->setBrush(QBrush(Qt::red));
        mypainter->drawRect(rect());
        QPen mypen;
        mypen.setColor(Qt::white);
        mypen.setWidth(2);
        mypainter->setPen(mypen);
        mypainter->drawLine(QPoint(5,5),QPoint(15,15));
        mypainter->drawLine(QPoint(15,5),QPoint(5,15));
    }
    else
    {
        mypainter->setBrush(QBrush(Qt::white));
        mypainter->drawRect(rect());
        QPen mypen;
        mypen.setColor(Qt::black);
        mypen.setWidth(2);
        mypainter->setPen(mypen);
        mypainter->drawLine(QPoint(5,5),QPoint(15,15));
        mypainter->drawLine(QPoint(15,5),QPoint(5,15));
    }
    mypainter->end();
}

void UXCB::mousePressEvent(QMouseEvent *event)
{
    emit myclick();
}

bool UXCB::eventFilter(QObject *watched, QEvent *event)
{
//    qDebug() << "who:" << watched << "  " << event;
    if (event->type() == QEnterEvent::Enter)
    {
        mouseenter = true;
        update();
    }
    if (event->type() == QEnterEvent::Leave)
    {
        mouseenter = false;
        update();
    }
    return false;
}
