/************************
 * This class is the button
 * used in the menu
 * *******************/
#ifndef UXMENUBUTTON_H
#define UXMENUBUTTON_H


#include <QWidget>
#include "components/qtmaterialraisedbutton.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPropertyAnimation>

class UXMENUBUTTON : public QtMaterialRaisedButton
{
    Q_OBJECT
public:
    explicit UXMENUBUTTON(QWidget *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void setinitsize(QSize size); //set initsize
    void usesize(int w,int h);    //set buttion and it icon size

//    void doanimate2();
//    void doanimate3();
//    void doanimate4();

    QPropertyAnimation *animatere = new QPropertyAnimation(this,"pos");
    QSize  initsize;
//    void paintEvent(QPaintEvent *event);

//    bool border;

signals:
    void myclick() const; //define the custome click signal to make the mouse click singal easier to
    // be receive by others

public slots:
    void doanimate1(); // the animate to make button look like have inertia
};

#endif // UXMENUBUTTON_H
