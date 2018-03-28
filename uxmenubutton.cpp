#include "uxmenubutton.h"
#include <QDebug>
#include <cmath>

UXMENUBUTTON::UXMENUBUTTON(QWidget *parent) : QtMaterialRaisedButton(parent),
    initsize(QSize(300,300))
//  ,border{false}
{

    setborder(false);
    installEventFilter(this);
    setUseThemeColors(false);
    animatere->setDuration(196);
    setHaloVisible(false);

    setIcon(QIcon("F:/Qt-project/picture/spm6.pic"));
    setBackgroundColor(QColor("#4c4c4c"));
    setborder(false);

}



bool UXMENUBUTTON::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == this && event->type() == QEnterEvent::Enter)
    {
        setborder(true);
        update();
    }
    if(watched == this && event->type() == QEnterEvent::Leave)
    {
        setborder(false);
        update();

    }
    return false;
}

void UXMENUBUTTON::mousePressEvent(QMouseEvent *event)
{


        QPropertyAnimation *animate = new QPropertyAnimation(this,"iconSize");
        animate->setDuration(50);
        animate->setStartValue(iconSize());
        animate->setEndValue(initsize/1.1);
        animate->start();

}

void UXMENUBUTTON::mouseReleaseEvent(QMouseEvent *event)
{

        QPropertyAnimation *animate = new QPropertyAnimation(this,"iconSize");
        animate->setDuration(100);
        animate->setStartValue(iconSize());
        animate->setEndValue(initsize);
        animate->start();
        emit myclick();

}

void UXMENUBUTTON::setinitsize(QSize size)
{
    initsize = size;
}

void UXMENUBUTTON::usesize(int w, int h)
{
    setFixedSize(w,h);
    setIconSize(QSize(w,h)/1.5);
    initsize = QSize(w,h)/1.5;
}

void UXMENUBUTTON::doanimate1()
{
    animatere->setStartValue(pos());
    animatere->setEndValue(pos() + QPoint(0,10));
    animatere->start();
}


