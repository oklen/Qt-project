#include "uxmenu.h"
#include <QDebug>

UXMENU::UXMENU(QWidget *parent) : QWidget(parent)
{

    setMouseTracking(true);

    open->usesize(100,120);
    open->setParent(this);
    load->usesize(100,120);
    load->setParent(this);
    print->usesize(100,60);
    print->setParent(this);
    optical->usesize(100,155);
    force->usesize(100,155);
    d3->usesize(100,100);
    cubic->usesize(100,100);
    yang->usesize(100,100);
    help->usesize(100,250);
    copyright->usesize(100,60);

    open->move(30,10);
    load->move(30,140);
    print->move(30,270);
    optical->move(150,10);
    force->move(150,175);
    d3->move(270,10);
    cubic->move(270,120);
    yang->move(270,230);
    help->move(390,10);
    copyright->move(390,270);
    setFixedSize(520,360);
    hide();
    move(0,100);

    animate->setStartValue(pos());
    animate->setEndValue(pos() + QPoint(0,10));
    animate->setDuration(10);
    animate2->setStartValue(pos()+ QPoint(0,10));
    animate2->setEndValue(pos() + QPoint(0,20));
    animate2->setDuration(20);
    animate3->setStartValue(pos()+ QPoint(0,20));
    animate3->setEndValue(pos() + QPoint(0,30));
    animate3->setDuration(90);
    animate4->setStartValue(pos()+ QPoint(0,30));
    animate4->setEndValue(pos() + QPoint(0,50));
    animate4->setDuration(192);

}

void UXMENU::paintEvent(QPaintEvent *event)
{
    QPainter *mpainter = new QPainter;
    mpainter->begin(this);
    mpainter->setBrush(QBrush(QColor(74,74,74,100)));
    mpainter->drawRect(QRect(QPoint(0,0),this->size()));
    mpainter->end();
}


void UXMENU::showoff()
{
    qDebug() << this->size();
    if(isVisible())
    {
       open->move(open->pos() + QPoint( 0,-10));
       load->move(load->pos() + QPoint( 0,-10));
       d3->move(d3->pos() + QPoint( 0,-10));
       force->move(force->pos() + QPoint( 0,-10));
       cubic->move(cubic->pos() + QPoint( 0,-10));
       yang->move(yang->pos() + QPoint( 0,-10));
       help->move(help->pos() + QPoint( 0,-10));
       copyright->move(copyright->pos() + QPoint( 0,-10));
       optical->move(optical->pos() + QPoint( 0,-10));
       print->move(print->pos() + QPoint( 0,-10));
       hide();
       return;
    }
    show();
    raise();
    animate->start();
    mtimer->singleShot(4,animate2,SLOT(start()));
    mtimer->singleShot(16,animate3,SLOT(start()));


    mtimer->singleShot(120,open,SLOT(doanimate1()));
    mtimer->singleShot(120,load,SLOT(doanimate1()));
    mtimer->singleShot(120,print,SLOT(doanimate1()));
    mtimer->singleShot(120,d3,SLOT(doanimate1()));
    mtimer->singleShot(120,force,SLOT(doanimate1()));
    mtimer->singleShot(120,cubic,SLOT(doanimate1()));
    mtimer->singleShot(120,yang,SLOT(doanimate1()));
    mtimer->singleShot(120,help,SLOT(doanimate1()));
    mtimer->singleShot(120,copyright,SLOT(doanimate1()));
    mtimer->singleShot(120,optical,SLOT(doanimate1()));


//    mtimer->singleShot(40,animate4,SLOT(start()));

}

void UXMENU::hidein()
{
    if(isVisible()){
        open->move(open->pos() + QPoint( 0,-10));
        load->move(load->pos() + QPoint( 0,-10));
        d3->move(d3->pos() + QPoint( 0,-10));
        force->move(force->pos() + QPoint( 0,-10));
        cubic->move(cubic->pos() + QPoint( 0,-10));
        yang->move(yang->pos() + QPoint( 0,-10));
        help->move(help->pos() + QPoint( 0,-10));
        copyright->move(copyright->pos() + QPoint( 0,-10));
        optical->move(optical->pos() + QPoint( 0,-10));
        print->move(print->pos() + QPoint( 0,-10));
        hide();
    }
}
