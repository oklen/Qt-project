#include "uxcdraw.h"

UXCDRAW::UXCDRAW(QWidget *parent) : QWidget(parent),
    pix{new QPixmap(512,512)},timer{new QTimer(this)},
    helper{new UXCDRAWHELPER(this)}
{
    setFixedSize(512,512);
    connect(timer,SIGNAL(timeout()),this,SLOT(doupdate()));
    timer->start(100);
    pix->fill(QColor(Qt::white));
}

void UXCDRAW::paintEvent(QPaintEvent *event)
{
    if(y==256)
    {
        emit drawComplete();
        timer->stop();
    }
    QPainter *mypainter = new QPainter;
    mypainter->begin(this);
    mypainter->drawPixmap(QRect(QPoint(0,0),QPoint(512,512)),*helper->pix2,helper->pix2->rect());
    drawpix = true;
    mypainter->end();
    y++;
    helper->y = y;
    qDebug() << "Do draw";
}

QVector<float>* UXCDRAW::getlinedata()
{
    // ... Get Data somewhere
    QVector<float> *vector = new QVector<float>(280);
    for(int i=0;i<256;i++)
    {
        vector->push_back(i);
    }
    return vector;
}

void UXCDRAW::sety(int value)
{
    helper->y = value;
}

void UXCDRAW::doupdate()
{

    update();
    helper->setlinedata(getlinedata());
    helper->update();
}

