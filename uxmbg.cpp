#include "uxmbg.h"

UXMBG::UXMBG(QWidget *parent) : QFrame(parent)
{
}

void UXMBG::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    painter->setRenderHints(QPainter::Antialiasing);
    QRect source(0.0,0.0,1366.0,768.0);
    QImage background("F:/Qt-project/picture/background_pro.png");
    painter->drawImage(this->rect(),background,source);
    painter->end();
}
