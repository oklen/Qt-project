#ifndef UXAVA_H
#define UXAVA_H

#include <QWidget>
#include "components/qtmaterialraisedbutton.h"
#include <QPropertyAnimation>
#include "uxmenu.h"

/*****************************************
 * This is the class for MENU BUTTON on the left top
 * *************************************/

class UXAVA : public QtMaterialRaisedButton
{
    Q_OBJECT
public:
    explicit UXAVA(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event); // contain the dynamic icon change animate function
    void mouseReleaseEvent(QMouseEvent *event); //contain the dynamic icon change animate function
    void setinitsize(QSize size); //store the origin size

    QSize  initsize;  //store the Icon origin size
    UXMENU *menu;

signals:
    void signalp() const; //signal to tell the icon size begin smaller

public slots:
    void bepressed();
};

#endif // UXAVA_H
