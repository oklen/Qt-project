#ifndef UXCCDRIGHTB_H
#define UXCCDRIGHTB_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class uxccdrightb : public QWidget
{
    Q_OBJECT
public:
    explicit uxccdrightb(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    bool lighting = false;

    int leftzoom = 0;
signals:

public slots:
};

#endif // UXCCDRIGHTB_H
