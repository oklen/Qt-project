#ifndef DPAINTER_H
#define DPAINTER_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QLabel>

//Usage:use this->help->setdataarray and the call updata()

class PIXPAINTER : public QLabel
{
    Q_OBJECT
public:
    explicit PIXPAINTER(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setxy(int x,int y);
    void setpix(QPixmap* pix);
    void setdataarray(float*);
    bool debug = true;

private:
    int x2;
    int y2;
    QPixmap *dpix;
    float* dataarray;
};

class UXDPAINTER : public QLabel
{
    Q_OBJECT
public:
    explicit UXDPAINTER(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    QPixmap *pix;
    PIXPAINTER *help;
    bool debug = true;

private:
    int x;
    int y;
    bool beginpaint = true;

signals:
    void painting();

public slots:
    void dopainting();
};


#endif // DPAINTER_H
