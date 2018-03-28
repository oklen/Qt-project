#include "uxcdrawhelper.h"


UXCDRAWHELPER::UXCDRAWHELPER(QWidget *parent) : QWidget(parent),
    pix2{new QPixmap(512,512)},vector{new QVector<float>(288)}
{
    pix2->fill(QColor(Qt::white));
}

void UXCDRAWHELPER::paintEvent(QPaintEvent *event)
{
    qDebug() << "update";
    QPainter *mypainter = new QPainter;
    mypainter->setRenderHint(QPainter::Antialiasing);
    mypainter->begin(pix2);
    QPen mpen;
    mpen.setWidth(2);
    //begin 56 0 0 to 4/1_pos 114 0 0 to  4/3_pos  170 170 0 to end 228 176 196

    float r,g,b = 10;
    for (auto i: *vector)
    {
        if(i<256/4.0)
        {
            r = i/(256.0/4)*(114-56)+56;
            g = 0;
            b = 0;
        }
        if(i>=256/4.0 && i<=256*3.0/4.0)
        {
            r = 114+(i-256.0/4)/(256/2.0)*(170-114);
            g = ((i-256.0/4)/(256/2.0)*(170));
            b = 0;
        }
        if(i>256/4.0*3)
        {
            r = 170 + (i-256*0.75)/(256/4.0)*(228-170);
            g = 172;
            b = (i-0.75*256)*196/(0.25*256);
        }
        mpen.setColor(QColor(r,g,b));
        mypainter->setPen(mpen);
        mypainter->drawPoint(i*2,y*2);
        qDebug() << i;
    }
    mypainter->end();
}

void UXCDRAWHELPER::setpix(QPixmap *pix)
{
    pix2 = pix;
}

void UXCDRAWHELPER::setlinedata(QVector<float> *cache_vector)
{
    vector = cache_vector;
}
