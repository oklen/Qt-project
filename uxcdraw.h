#ifndef UXCDRAW_H
#define UXCDRAW_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QTimer>
#include <QPaintEvent>
#include <QDebug>
#include "uxcdrawhelper.h"


class UXCDRAW : public QWidget
{
    Q_OBJECT
public:
    explicit UXCDRAW(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    QVector<float>* getlinedata();
    void sety(int value);
    QPixmap getpixmap();

    QPixmap *pix;
    int y=0;
    UXCDRAWHELPER *helper;
signals:
    void drawComplete();
public slots:
    void doupdate();
private:
    QTimer *timer;
    bool drawpix;
};


#endif // UXCDRAW_H
