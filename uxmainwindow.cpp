#include "uxmainwindow.h"
UXMainWindow::UXMainWindow()
{
    QSurfaceFormat format;
    if (optCoreProfile) {
        format.setVersion(4, 4);
        format.setProfile(QSurfaceFormat::CoreProfile);
    }
    if (optMultipleSample)
        format.setSamples(4);



//    centralWidget->setStyleSheet("*{background:white}");

    bg->resize(1366,768);
    installEventFilter(this);

    setCentralWidget(bg);
    resize(1366,768);

    forw->hide();

    my3d->mainwindowid = winId(); // used in screen-shot for 3d window

    bg->show();
//      UXCCDPERX per; //CCD display window

//    autop.v11layout->addWidget(per.uxCCD); // add display window


    connect(menubutton.menu->force,SIGNAL(myclick()),this,SLOT(showforcew()));
    connect(menubutton.menu->optical,SIGNAL(myclick()),this,SLOT(showoptical()));
    connect(menubutton.menu->d3,SIGNAL(myclick()),this,SLOT(showd3()));
    connect(menubutton.menu->copyright,SIGNAL(myclick()),this,SLOT(showdlc()));
//    connect(&server.emiter,SIGNAL(m1(float,float,float)),per->uxCCD,SLOT(set4window(float,float,float)));//Connect message1


    connect(forw,SIGNAL(bepressed()),my3d,SLOT(windowswap())); //tell 3d to swap to screen-shot
    connect(&autop,SIGNAL(bepressed()),my3d,SLOT(windowswap())); //tell 3d to swap to screen-shot
    repaint();

}

void UXMainWindow::showd3()
{
    if(!my3d->showed)
        {
        my3d->move(100,200);
        my3d->setWindowTitle("UX3D");
        my3d->setParent(centralWidget());
        my3d->show();
        my3d->qwpointer->show();
        my3d->adjustSize();
        my3d->showed = true;
        }
    else
    {
        my3d->show();
    }

        menubutton.menu->hidein();
}

void UXMainWindow::showoptical()
{
    if(!autop.showed)
    {
        autop.setParent(centralWidget());
        autop.setWindowTitle("Auto");
        autop.show();
        autop.adjustSize();
        autop.showed = true;
    }
    else
    {
        autop.show();
    }
        menubutton.menu->hidein();
}

void UXMainWindow::showforcew()
{
    qDebug() << "should show force window";
    if(!forw->showed)
    {

        forw->setParent(centralWidget());
        forw->move(700,0);
        forw->show();
        forw->adjustSize();
        forw->showed =true;
    }
    else
    {
        forw->show();
    }
        menubutton.menu->hidein();
}

void UXMainWindow::showdlc()
{
    if(!dlcshowed){
        dl->setParent(centralWidget());
        dl->move(400,400);
        dl->show();
        dlcshowed = true;
    }
    else
        dl->show();
    menubutton.menu->hidein();
}


void UXMainWindow::hidedlc()
{
    dl->hide();
    dlcshowed = false;
}



bool UXMainWindow::eventFilter(QObject *watched, QEvent *event)
{
//
    if(event->type() == QEvent::MouseButtonPress && watched != menubutton.menu)
    {
        menubutton.menu->hidein();
    }
    return false;
}

void UXMainWindow::initCCD()
{
    per = new UXCCDPERX;
}
