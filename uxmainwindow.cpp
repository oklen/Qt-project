#include "uxmainwindow.h"

void UXMainWindow::showd3()
{
        my3d->move(1000,200);
        my3d->setWindowTitle("UX3D");
        my3d->setParent(centralWidget());
        my3d->show();
        my3d->pointer->show();
        my3d->adjustSize();

        menubutton->menu->hidein();
}

void UXMainWindow::showoptical()
{
        autop->setParent(centralWidget());
        autop->setWindowTitle("Auto");
        autop->show();
        autop->adjustSize();
        menubutton->menu->hidein();
}

void UXMainWindow::showforcew()
{
    qDebug() << "should show force window";
        forw->setParent(centralWidget());
        forw->move(700,0);
        forw->show();
        forw->adjustSize();
        menubutton->menu->hidein();
}

UXMainWindow::UXMainWindow()
{
    QSurfaceFormat format;
    if (optCoreProfile) {
        format.setVersion(4, 4);
        format.setProfile(QSurfaceFormat::CoreProfile);
    }
    if (optMultipleSample)
        format.setSamples(4);


    QFrame *centralWidget = new QFrame(this);
    centralWidget->setStyleSheet("*{background:white}");

    centralWidget->resize(1220,1000);
    installEventFilter(this);

    setCentralWidget(centralWidget);
    resize(1820,980);

    forw->hide();

    my3d->mainwindowid = winId(); // used in screen-shot for 3d window

    connect(menubutton->menu->force,SIGNAL(myclick()),this,SLOT(showforcew()));
    connect(menubutton->menu->optical,SIGNAL(myclick()),this,SLOT(showoptical()));
    connect(menubutton->menu->d3,SIGNAL(myclick()),this,SLOT(showd3()));

    connect(forw,SIGNAL(bepressed()),my3d,SLOT(windowswap())); //tell 3d to swap to screen-shot
    connect(autop,SIGNAL(bepressed()),my3d,SLOT(windowswap())); //tell 3d to swap to screen-shot

}








bool UXMainWindow::eventFilter(QObject *watched, QEvent *event)
{
//
    if(event->type() == QEvent::MouseButtonPress && watched != menubutton->menu)
    {
        menubutton->menu->hidein();
    }
    return false;
}
