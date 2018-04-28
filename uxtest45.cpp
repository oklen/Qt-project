#include "uxtest45.h"

UXTEST45::UXTEST45(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1024,768);
}

void UXTEST45::mousePressEvent(QMouseEvent *event)
{
    if(Isupdate)
    {
        update();
        cver->convert_images(pointers,1024,768);
        qDebug() << " Convert Done";
    }
  else
     dotest();
}

void UXTEST45::dotest()
{
    UXCCDPERX* pers = (UXCCDPERX*)per;
    pers->ReadCCD(width(),height(),&pointers);
    Isupdate = true;
}

void UXTEST45::save()
{
    QImage(pointers,1392,1040,QImage::Format_RGB888).save(QString("t1.jpg"));
    Isupdate = false;
}

void UXTEST45::paintEvent(QPaintEvent *event)
{
    if(Isupdate){
        QPainter* mpainter = new QPainter;
        mpainter->begin(this);
        mpainter->drawPixmap(rect(),QPixmap::fromImage(QImage(std::move(pointers),1392,1040,QImage::Format_RGB888))/*.scaled(width(),height())*/,rect());
        mpainter->end();
        Isupdate = false;
    }
}

