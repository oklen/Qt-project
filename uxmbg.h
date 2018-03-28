//Whole app background image
#ifndef UXMBG_H
#define UXMBG_H

#include <QWidget>
#include <QFrame>
#include <QPainter>
#include <QPaintEvent>

class UXMBG : public QFrame
{
    Q_OBJECT
public:
    explicit UXMBG(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // UXMBG_H
