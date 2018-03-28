#include "uxautop.h"

UXAUTOP::UXAUTOP(QWidget *parent) : QFrame(parent),
    h2layout{new QHBoxLayout},
    warning{new QtMaterialRaisedButton}
{
//    begin->setborder(false);


//    QLabel currentp;
//    QLabel remaintime;
//    currentp.setParent(this);
//    remaintime.setParent(this);
//    currentp.setText("75% (256 of 192)");
//    remaintime.setText("~ 00:15:00");
//    currentp.move(20,460);
//    remaintime.move(440,460);

//    construct the widget and layout
    QHBoxLayout *hlayout = new QHBoxLayout;
    QLabel *autotitle = new QLabel;
    autotitle->setText("Current Scan Area");
    autotitle->setObjectName("autotitle");
    QtMaterialIconButton *max = new QtMaterialIconButton(
                QIcon("./components/icons/navigation/svg/production/ic_expand_more_24px.svg"));
//    QtMaterialIconButton *close = new QtMaterialIconButton(
//                QIcon("./components/icons/navigation/svg/production/ic_expand_more_24px.svg"));
    UXCB *close = new UXCB(this);
    hlayout->addWidget(autotitle);
    hlayout->addStretch();
    hlayout->addWidget(max);
    hlayout->addWidget(close);

    //Foucs Adjust Interface Constuction
//    QHBoxLayout *h11layout = new QHBoxLayout;
//    QLabel *foucsadjust = new QLabel;
//    foucsadjust->setText("Focus Adjust");
//    foucsadjust->setObjectName("foucslabel");

//    QLCDNumber *lcd = new QLCDNumber; //the LCD format number show
//    lcd->setDigitCount(10);
//    lcd->display("9611122412");
//    lcd->setFixedHeight(50);
//    h11layout->addWidget(foucsadjust);
//    h11layout->addWidget(lcd);


   QVBoxLayout  *v4layout = new QVBoxLayout;
//    v4layout->addWidget(currentvalue);
//    v4layout->addWidget(lcd);

//    UXTUMBLER *tumbler = new UXTUMBLER;
//    tumbler->setFixedSize(300,55);
    h2layout->addLayout(v4layout);
//    h2layout->addLayout(v5layout);

    //Finsh

//    QVBoxLayout *v1layout = new QVBoxLayout;
//    QLabel *feedback = new QLabel;
//    feedback->setText("Set Feedback");

    // construct auto-complete widget

//    QtMaterialAutoComplete *autoc = new QtMaterialAutoComplete;

    // add data
    QStringList mydata = QStringList(QString("12,32"));
    mydata.append("22,32");
    mydata.append("32,32");
    mydata.append("42,32");
    mydata.append("52,32");
    mydata.append("13,32");
    mydata.append("1v,32");
    mydata.append("16,32");
    mydata.append("123,32");
    mydata.append("12,32");
    mydata.append("156,32");
    mydata.append("1112,32");
    mydata.append("12,32");
    mydata.append("1ad,32");
    mydata.append("2cv,32");
    mydata.append("12,32");
    mydata.append("26,32");

//    autoc->setDataSource(mydata);


//    //configure the color and font
//    autoc->setLabelColor(QColor("white"));
//    autoc->setLabel("Input Feed Back");
//    autoc->setLabelFontSize(8);
//    autoc->setInputLineColor(QColor("#d7f6f6"));
//    autoc->setInkColor(QColor("white"));
//    autoc->setLabelColor(QColor("white"));
//    autoc->setTextColor(Qt::white);



//    v1layout->addWidget(feedback);
    if(ch)
    approache->setText(QString::fromLocal8Bit("开始进针"));
    else
        approache->setText("Position");
    approache->setCheckable(false);
    approache->setHaloVisible(false);
    approache->setBackgroundColor(QColor(27,117,188));
//    h12layout->addWidget(autoc);

    QVBoxLayout *v2layout = new QVBoxLayout;
    begin->setCheckable(false);
    if(ch)
    begin->setText(QString::fromLocal8Bit("开始扫描"));
    else
        begin->setText("Begin Scan");
    begin->setHaloVisible(false);
    begin->setBackgroundColor(QColor(27,117,188));
    warning = end;
    end->setCheckable(false);
    if(ch)
    end->setText(QString::fromLocal8Bit("开始退针"));
    else
        end->setText("Finish");
    end->setHaloVisible(false);
    end->setBackgroundColor(QColor(27,117,188));

//    v2layout->addLayout(h11layout);
//    v2layout->addWidget(tumbler);
//    v2layout->addWidget(&lp);
    v2layout->addLayout(h2layout);
//    v2layout->addLayout(v1layout);


    QHBoxLayout *h1layout = new QHBoxLayout;
//    v11layout->addWidget(ccdper.uxCCD);
//    v11layout->addLayout(h5layout);
//    h1layout->addWidget(ccd);
    h1layout->addLayout(v11layout);
//    h1layout->addWidget(&ccdper.uxCCD);

    h1layout->addLayout(v2layout);

    QHBoxLayout *h2layout = new QHBoxLayout;
    h2layout->addWidget(approache);
    h2layout->addWidget(begin);
    h2layout->addWidget(end);

    v3layout->addLayout(hlayout);
    v3layout->addLayout(h1layout);
    v3layout->addLayout(h2layout);
    setStyleSheet("*{background:#4c4c4c }"
                  "Frame{border:3px}"
                  "QtMaterialRaisedButton{color:white;font-size:20px;font-weight:15px}"
                  "QLabel#autotitle{color:white;font-size:25px;}"
                  "QLabel#analysizelabel{color:white;font-size:15px;}"
                  "QLabel#foucslabel{color:white;font-size:20px;}");

    setLayout(v3layout);

    begin->setEnabled(false);
    end->setEnabled(false);
    approache->setCheckable(false);
    approache->setHaloVisible(false);

//   add signal and slots


    connect(approache,SIGNAL(clicked(bool)),this,SLOT(approchestart()));
    connect(begin,SIGNAL(clicked(bool)),this,SLOT(beginstart()));
    connect(end,SIGNAL(clicked(bool)),this,SLOT(endstart()));
    connect(close,SIGNAL(myclick()),this,SLOT(closehide()));

    invoker->start(1000);

}

void UXAUTOP::closeEvent(QCloseEvent *event) //used to show waring when click close but the probe not backward
{
    if(warning->text() == QString(QString::fromLocal8Bit("退针完成")))
        return;
    QtMaterialDialog *pleaseend = new QtMaterialDialog;

    QLayout *vboxlayout = new QVBoxLayout;
    vboxlayout = pleaseend->layout();
    QtMaterialRaisedButton *confrom = new QtMaterialRaisedButton;
    confrom->setText("Conform");
    QLabel *meg = new QLabel;
    meg->setText("Please check if end");
    vboxlayout->addWidget(meg);
    vboxlayout->addWidget(confrom);
    pleaseend->show();

    if(warning->text() != QString(QString::fromLocal8Bit("退针完成")))
        event->ignore();
    connect(confrom,SIGNAL(clicked(bool)),pleaseend,SLOT(hide()));
}

void UXAUTOP::approchestart()
{
    if(!approchbegin){
        approache->setEnabled(true);
        approache->setText(QString::fromLocal8Bit("正在进针"));
        connect(invoker,SIGNAL(timeout()),approache,SLOT(invokeriddle()));
        approchbegin = true;

    }
    else{
        disconnect(invoker,SIGNAL(timeout()),approache,SLOT(invokeriddle()));
        approache->setEnabled(false);

        approache->setText(QString::fromLocal8Bit("进针完成"));
        approchbegin = false;

        begin->setEnabled(true);
        begin->setText(QString::fromLocal8Bit("开始扫描"));
    }
}

void UXAUTOP::beginstart()
{
    if(!beginbegin){
        begin->setEnabled(true);
        begin->setText(QString::fromLocal8Bit("正在扫描"));
        connect(invoker,SIGNAL(timeout()),begin,SLOT(invokeriddle()));
        beginbegin = true;

    }
    else{
        disconnect(invoker,SIGNAL(timeout()),begin,SLOT(invokeriddle()));
        begin->setEnabled(false);
        begin->setText(QString::fromLocal8Bit("扫描完成"));
        beginbegin = false;
        end->setEnabled(true);
        end->setText(QString::fromLocal8Bit("退针"));
    }
}

void UXAUTOP::endstart()
{
    if(!endbegin){
        end->setEnabled(true);
        end->setText(QString::fromLocal8Bit("正在退针"));
        connect(invoker,SIGNAL(timeout()),end,SLOT(invokeriddle()));
        endbegin = true;

    }
    else{
        disconnect(invoker,SIGNAL(timeout()),end,SLOT(invokeriddle()));
        end->setEnabled(false);
        end->setText(QString::fromLocal8Bit("退针完成"));
        endbegin = false;
        approache->setEnabled(true);
        approache->setText(QString::fromLocal8Bit("进针"));
    }
}

void UXAUTOP::mousePressEvent(QMouseEvent *event)
{
    emit bepressed();
    raise();
    mousedown = true;
    hotpot = event->pos();
}

void UXAUTOP::mouseReleaseEvent(QMouseEvent *event)
{

    mousedown = false;


}

void UXAUTOP::mouseMoveEvent(QMouseEvent *event)
{
    if (mousedown && QRect(0,0,1000,800).contains(this->pos()+event->pos()-hotpot)){
        this->move(this->pos()+event->pos()-hotpot);
    }
    else
    {
        if(mousedown && QRect(0,0,1000,800).contains(this->pos()
                                                     +QPoint((event->pos()-hotpot).x(),0)))
            this->move(this->pos()+QPoint((event->pos()-hotpot).x(),0));
        if(mousedown && QRect(0,0,1000,800).contains(this->pos()
                                                     +QPoint(0,(event->pos()-hotpot).y())))
            this->move(this->pos()+QPoint(0,(event->pos()-hotpot).y()));
    }
//    qDebug() << "this pos:" << this->pos() << " "
//             << "event pos:" << event->pos() << " "
//             << "hotpot:" << hotpot;
}

void UXAUTOP::closehide()
{
    hide();
    showed = false;
}
