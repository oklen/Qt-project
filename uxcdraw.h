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

    QPixmap *pix;
    int y=0;
signals:
    void drawComplete();
public slots:
    void doupdate();
private:
    QTimer *timer;
    bool drawpix;
    UXCDRAWHELPER *helper;
};


#endif // UXCDRAW_H
