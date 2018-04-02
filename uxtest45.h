#ifndef UXTEST45_H
#define UXTEST45_H

#include <QWidget>

#include "uxcb.h"

class UXTEST45 : public UXCB
{
    Q_OBJECT
public:
    explicit UXTEST45(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:
};

#endif // UXTEST45_H
