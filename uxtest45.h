#ifndef UXTEST45_H
#define UXTEST45_H

#include <QWidget>
#include <QDebug>

#include "uxcb.h"
#include "uxccdper.h"
#include "cver.h"

//#include "highgui/highgui.hpp"





class UXTEST45 : public QWidget
{
    Q_OBJECT
public:
    explicit UXTEST45(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent* event);
    uchar* pointers = new uchar(1392*1040*3);
    void* per;
    QPixmap *map = new QPixmap(1392,1040);
    bool Isupdate =false;
    CVER *cver = new CVER;

//    inline uchar* convert_images(uchar* data, int width, int height);
signals:

public slots:
    void dotest();
    void save();
};

#endif // UXTEST45_H
