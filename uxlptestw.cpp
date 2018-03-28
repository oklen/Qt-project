#include "uxlptestw.h"

UXLPTESTW::UXLPTESTW(QWidget *parent) : QWidget(parent),
    ok{new QtMaterialRaisedButton}
{
    ok->setCheckable(false);

    v2layout.addWidget(&a1);
    v2layout.addWidget(&a2);
    v2layout.addWidget(ok);
    ok->setText("OK!");
    lp.length = 200;
    lp.potr = 10;
    lp.update();
    hlayout.addWidget(&lp);
    hlayout.addLayout(&v2layout);
    setLayout(&hlayout);
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(updatelp()));
}

void UXLPTESTW::updatelp()
{
    qDebug() << "Do update!";
    lp.inputx = a1.text().toFloat();
    lp.inputy = a2.text().toFloat();
    lp.update();
}

void UXLPTESTW::paintEvent(QPaintEvent *event)
{
    QPainter mpainter;
    mpainter.begin(this);
    mpainter.setBrush(QBrush(QColor(74,74,74)));
    mpainter.drawRect(rect());
    mpainter.end();
}

UXLPTESTW::~UXLPTESTW()
{
    delete ok;
}
