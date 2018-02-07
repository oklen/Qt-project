/*******************************
 * This class contain the
 * menu button generate and layout
 * configure
 * *****************************/

#ifndef UXMENU_H
#define UXMENU_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QImage>
#include <QIcon>
#include <components/qtmaterialiconbutton.h>
#include <components/qtmaterialraisedbutton.h>
#include <components/qtmaterialflatbutton.h>
#include <QPainter>
#include <QHoverEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QPainter>
#include <QTimer>
#include "uxmenubutton.h"

class UXMENU : public QWidget
{
    Q_OBJECT
public:
    explicit UXMENU(QWidget *parent = nullptr);
    QtMaterialRaisedButton *build = new QtMaterialRaisedButton;
    void paintEvent(QPaintEvent *event);
//    void mousePressEvent(QMouseEvent *event);


    // construct buttons in menu
    UXMENUBUTTON *open = new UXMENUBUTTON;
    UXMENUBUTTON *load = new UXMENUBUTTON;
    UXMENUBUTTON *print = new UXMENUBUTTON;
    UXMENUBUTTON *optical = new UXMENUBUTTON(this);
    UXMENUBUTTON *force = new UXMENUBUTTON(this);
    UXMENUBUTTON *d3 = new UXMENUBUTTON(this);
    UXMENUBUTTON *cubic = new UXMENUBUTTON(this);
    UXMENUBUTTON *yang = new UXMENUBUTTON(this);
    UXMENUBUTTON *help = new UXMENUBUTTON(this);
    UXMENUBUTTON *copyright = new UXMENUBUTTON(this);

    // this 4 animate implement the whole menu moving
    QPropertyAnimation *animate = new QPropertyAnimation(this,"pos");
    QPropertyAnimation *animate2 = new QPropertyAnimation(this,"pos");
    QPropertyAnimation *animate3 = new QPropertyAnimation(this,"pos");
    QPropertyAnimation *animate4 = new QPropertyAnimation(this,"pos");
    QTimer *mtimer = new QTimer;

signals:

public slots:
    void showoff(); // show menu
    void hidein(); // hide menu

};

#endif // UXMENU_H
