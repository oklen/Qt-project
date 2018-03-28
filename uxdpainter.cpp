#include "uxdpainter.h"
#include <QPixmapCache>
#include <QTime>
#include <QCoreApplication>

UXDPAINTER::UXDPAINTER(QWidget *parent) : QLabel(parent),
    pix{new QPixmap(600,900)},
    x{600},y{0},help{new PIXPAINTER}
{
    pix->fill(Qt::white);
    setPixmap(*pix);
    help->setpix(pix);

}

void UXDPAINTER::paintEvent(QPaintEvent *event)
{
    if (beginpaint){
        QPainter *mypainter = new QPainter(this);
        QPen *pen = new QPen(QColor("red"));
        mypainter->setClipRect(0,0,600,y+600);
        mypainter->drawPixmap(0,0,500,900,*pix);
        mypainter->setRenderHint(QPainter::Antialiasing,true);
        mypainter->setPen(*pen);
        mypainter->end();
        if(debug)
        qDebug() << x%2 << "  " << x << "  " << y;
        help->paintEvent(event);


    }

//    else{
//        QPainter *pixpainter = new QPainter(pix);
//        if (!QPixmapCache::find("my_big_image", pix)) {
//            pixpainter->drawPoint(x,y);
//            QPixmapCache::insert("my_big_image", *pix);
//        }
//        pixpainter->setPen(Qt::red);
//        pixpainter->setBrush(Qt::red);
//        pixpainter->drawRect(0,0,100+x,100+y);

//        pixpainter->end();
//        qDebug() << "Draw pix!";
//    }
    // 设置画刷颜色

}

void UXDPAINTER::dopainting()
{
//    qDebug() << "DOing";
    if(y<900)
    {
        for(int i=0;i<600;i++)
        {

          help->setpix(pix);
            update();
        }
        x=0;
        y++;
    }
}

PIXPAINTER::PIXPAINTER(QWidget *parent) :QLabel(parent),
    x2{0},y2{0}
{

}

void PIXPAINTER::paintEvent(QPaintEvent *event)
{
    QPainter *dpainter = new QPainter(dpix);
    dpainter->setRenderHint(QPainter::Antialiasing);
    if(debug)
    for (int i =0;i<300;i++){
         dpainter->setPen(QColor((100+x2+i)%150,(x2+i)%150,(x2+i)%150));
//         dpainter->setBrush(QColor((100+x2+i)%150,(x2+i)%150,(x2+i)%150));
        dpainter->drawRect(i*2,y2*3,2,3);
    }
    else
        for(int i =0;i<300;i++){
            dpainter->setPen(QColor(dataarray[i]*50,dataarray[i],dataarray[i]));
            dpainter->drawRect(i*2,y2*3,2,3);
        }
    dpainter->end();
    qDebug() << "Help DRaw " << x2 << "  " << y2;
    x2++;
    y2++;
}

void PIXPAINTER::setxy(int x, int y)
{
    x2 = x;
    y2 = y;
}

void PIXPAINTER::setpix(QPixmap * pix)
{
    dpix = pix;
    qDebug() << "Seting";
}
