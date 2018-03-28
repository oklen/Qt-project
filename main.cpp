/****************************************************************************
**
** Copyright (C) 2018 The HuaYong Company Ltd.
**
**
** This file is part of the HUAYONG scan driver software.
**
** BSD License
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
**
**                                      writen by CaiZeFeng
****************************************************************************/


#include <QQuickWidget>
#include <QQuickItem>
//#include <QQmlErFror>
#include <QtWidgets>
#include <QDebug>
#include <QPalette>
#include <QCloseEvent>

//#include "/root/menu/fileio.h"
//#include "/root/menu/fileio2.h"
//#include "/media/root/LENOVO/WpSystem/qt_project/Select_Area/drag.h"
//#include "/media/root/LENOVO/WpSystem/qt_project/Select_Area/fc.h"
#include "components/qtmaterialraisedbutton.h"
#include "uxava.h"
//#include "stackwidget.h"
#include "uxforcew.h"
#include "ux3dw.h"
#include "uxautop.h"
#include "uxmenu.h"
#include "uxmainwindow.h"
#include "uxfile.h"
#include "uxcdraw.h"
#include "timehelper.h"
#include "uxccdper.h"





int main(int argc, char **argv)
{


/********************************************************************
 * Used to do the QML File IO,but now it not used
 *
//    qmlRegisterType<FileIO2, 1>("FileIO2", 1, 0, "FileIyO2");
//    qmlRegisterType<FileIO, 1>("FileIO", 1, 0, "FileIO");
************************************************************************/





    QApplication app(argc, argv);

    QCoreApplication::setApplicationName("Hua Yong Scan software");
    QCoreApplication::setOrganizationName("Hua Yong .Inc");
    QCoreApplication::setApplicationVersion("1.0.0");
    app.setFont(QFont("黑体",13));

//    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);
    UXCCDPERX per;
    UXMainWindow mainWindow;
    /**************************/
    mainWindow.centralWidget()->setAcceptDrops(true);


//    UXFORCEW *forw = new UXFORCEW;
////    forw->setParent(mainWindow.centralWidget());
//    forw->move(700,0);
//    forw->show();

//    UX3DW *my3d = new UX3DW;
//    my3d->move(1000,200);
//    my3d->setWindowTitle("UX3D");
////    my3d->setParent(mainWindow.centralWidget());
//    my3d->show();



    mainWindow.menubutton.setFixedSize(100,100);
    mainWindow.menubutton.menu->setParent(mainWindow.centralWidget());
    mainWindow.menubutton.menu->move(0,200);


    mainWindow.menubutton.setIcon(QIcon("F:/Qt-project/picture/Brand.png"));
    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->setAlignment(Qt::AlignLeft);
    vlayout->addWidget(&mainWindow.menubutton);
    vlayout->addStretch();

    mainWindow.centralWidget()->setLayout(vlayout);


    mainWindow.connect(&mainWindow.menubutton,SIGNAL(signalp()),mainWindow.menubutton.menu,SLOT(showoff())); //show the menu
    mainWindow.connect(&mainWindow.menubutton,SIGNAL(signalp()),mainWindow.my3d,SLOT(windowswap())); //swap 3d windows
    mainWindow.connect(&mainWindow.menubutton,SIGNAL(signalp()),&mainWindow.menubutton,SLOT(bepressed())); //invoke click effect
    mainWindow.show();
    mainWindow.autop.v11layout->addWidget(per.uxCCD);
    mainWindow.connect(&mainWindow.server.emiter,SIGNAL(m1(float,float,float)),per.uxCCD,SLOT(set4window(float,float,float)));//Connect message1

//        UXAUTOP autop;
//        autop.v11layout->addWidget(per.uxCCD);
//    autop.show();


//   QLabel *currentprocess = new QLabel;
//   currentprocess->setText("Current Progress");
//   currentprocess->setAlignment(Qt::AlignCenter);
//   QHBoxLayout *h5layout = new QHBoxLayout;
//   h5layout->addWidget(currentprocess);
////   h5layout->addWidget(progress);
//   autop.v11layout->addLayout(h5layout);

    return app.exec();
}
/*******************************************************************************************
 * Used to produce two chart .However these is decrepted now.
 *
//    UXZOOMCHART *chart = new UXZOOMCHART();
//    UXZOOMCHARTVIEW *chartView = new UXZOOMCHARTVIEW(chart);
//    QSplineSeries *series = new QSplineSeries();
//    series->setName("spline chart");
//    series->append(0, 6);
//    series->append(2, 4);
//    series->append(3, 8);
//    series->append(7, 4);
//    series->append(10, 5);
//    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);


//    chart->addSeries(series);
//    chart->setTitle("Simple spline chart example");
//    chart->createDefaultAxes();
//    chart->axisY()->setRange(0, 10);
//    chart->setAcceptDrops(true);
//    chart->setMinimumSize(1,1);
//    chart->resize(300,300);
//    chart->setAnimationOptions(QChart::SeriesAnimations);
//    chartView->setChart(chart);

//    chartView->setParent(mainWindow.centralWidget());
//    chartView->setRenderHint(QPainter::Antialiasing);
//    mainWindow.centralWidget()->grabGesture(Qt::PinchGesture);
//    mainWindow.centralWidget()->grabGesture(Qt::PanGesture);
//    chartView->move(QPoint(800,400));

//    UXZOOMCHART *boxchart = new UXZOOMCHART();
//    QBoxPlotSeries *boxseries = new QBoxPlotSeries();
//    QList<qreal> doublelist {4.0,1.0,2.0,3.0};
//    qSort(doublelist.begin(),doublelist.end());
//    QBoxSet *myset = new QBoxSet("Testing Data Sample");
//    myset->setValue(QBoxSet::UpperExtreme,8.0);
//    myset->setValue(QBoxSet::UpperQuartile,doublelist.at(int(doublelist.length()*3/4)));
//    boxseries->append(myset);
//    boxseries->setName("Box Plot");
//    boxchart->addSeries(boxseries);
//    boxchart->setTitle("My Small Box");
//    boxchart->setAnimationOptions(QChart::SeriesAnimations);
//    boxchart->setMinimumSize(1,1);
//    boxchart->resize(300,300);
//    boxchart->createDefaultAxes();
//    boxchart->legend()->setVisible(true);
//    boxchart->legend()->setAlignment(Qt::AlignBottom);

//    chart->createDefaultAxes();

//    chart->legend()->setVisible(true);
//    chart->legend()->setAlignment(Qt::AlignBottom);
//    UXZOOMCHARTVIEW *boxView = new UXZOOMCHARTVIEW(boxchart);
//    boxView->setChart(boxchart);
//    boxView->setRenderHint(QPainter::Antialiasing);
//    boxView->move(QPoint(1200,400));
//    boxView->setParent(mainWindow.centralWidget());
//    boxView->grabGesture(Qt::PinchGesture);
//    boxView->grabGesture(Qt::PanGesture);
//    boxView->show();

//    raisebutton->setParent(mainWindow.centralWidgeSetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);t());
//    raisebutton->setText("Great Raise Button!");
//    raisebutton->setRole(Material::Default);
//    raisebutton->setOverlayStyle(Material::TintedOverlay);
//    raisebutton->setHaloVisible(false);
//    raisebutton->setIcon(QIcon("/media/root/LENOVO/WpSystem/Qt5/Examples/Qt-5.10.0/quick/quickwidgets/quickwidget/components/icons/action/svg/production/ic_3d_rotation_24px.svg"));
//    raisebutton->move(800,800);
 * ****************************************************************************************/
