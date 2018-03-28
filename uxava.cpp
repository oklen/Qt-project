#include "uxava.h"
#include <QDebug>
#include <cmath>

UXAVA::UXAVA(QWidget *parent) : QtMaterialRaisedButton(parent),
    menu{new UXMENU}
{
    setborder(false);
    setIconSize(QSize(100,100));
    setBackgroundColor(QColor(255,255,255,1));
    initsize = iconSize();

    menu->hide();


}

void UXAVA::mousePressEvent(QMouseEvent *event)
{
    if( std::sqrt((event->pos().x() - width()/2)*(event->pos().x() - width()/2)
                  + (event->pos().y() - height()/2) * (event->pos().y() - height()/2)
                  ) < 50)
    {
        QPropertyAnimation *animate = new QPropertyAnimation(this,"iconSize");
        animate->setDuration(50);
        animate->setStartValue(iconSize());
        animate->setEndValue(initsize/1.1);
        animate->start();
        emit signalp();
}
}

void UXAVA::mouseReleaseEvent(QMouseEvent *event)
{
    if( std::sqrt((event->pos().x() - width()/2)*(event->pos().x() - width()/2)
                  + (event->pos().y() - height()/2) * (event->pos().y() - height()/2)
                  ) < 50)
    {
        QPropertyAnimation *animate = new QPropertyAnimation(this,"iconSize");
        animate->setDuration(100);
        animate->setStartValue(iconSize());
        animate->setEndValue(initsize);
        animate->start();
    }

}

void UXAVA::setinitsize(QSize size)
{
    initsize = size;
}

void UXAVA::bepressed()
{
//    qDebug() << "pressed!";
}

//bool UXAVA::signalp()
//{

//}
