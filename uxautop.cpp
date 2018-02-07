#include "uxautop.h"

UXAUTOP::UXAUTOP(QWidget *parent) : QFrame(parent),
    h2layout{new QHBoxLayout},
    warning{new QtMaterialRaisedButton}
{

//    construct the widget and layout
    QHBoxLayout *hlayout = new QHBoxLayout;
    QLabel *autotitle = new QLabel;
    autotitle->setText("Current Scan Area");
    autotitle->setObjectName("autotitle");
    QtMaterialIconButton *max = new QtMaterialIconButton(
                QIcon("./components/icons/navigation/svg/production/ic_expand_more_24px.svg"));
    QtMaterialIconButton *close = new QtMaterialIconButton(
                QIcon("./components/icons/navigation/svg/production/ic_expand_more_24px.svg"));
    hlayout->addWidget(autotitle);
    hlayout->addStretch();
    hlayout->addWidget(max);
    hlayout->addWidget(close);

    //Foucs Adjust Interface Constuction
    QHBoxLayout *h11layout = new QHBoxLayout;
    QLabel *foucsadjust = new QLabel;
    foucsadjust->setText("Focus Adjust");
    foucsadjust->setObjectName("foucslabel");

    QLCDNumber *lcd = new QLCDNumber; //the LCD format number show
    lcd->setDigitCount(10);
    lcd->display("9611122412");
    lcd->setFixedHeight(50);
    h11layout->addWidget(foucsadjust);
    h11layout->addWidget(lcd);

    QLabel *currentprocess = new QLabel;
    currentprocess->setText("Current Progress");
    QtMaterialProgress *progress = new QtMaterialProgress;
    progress->setInvertedAppearance(true);
    progress->setProgressType(Material::DeterminateProgress);
    progress->setMinimum(0);
    progress->setMaximum(100);
    progress->setValue(75);
   QVBoxLayout  *v4layout = new QVBoxLayout;
//    v4layout->addWidget(currentvalue);
//    v4layout->addWidget(lcd);
    QHBoxLayout *h5layout = new QHBoxLayout;
    currentprocess->setAlignment(Qt::AlignCenter);
    h5layout->addWidget(currentprocess);
    h5layout->addWidget(progress);
    UXTUMBLER *tumbler = new UXTUMBLER;
    tumbler->setFixedSize(300,55);
    h2layout->addLayout(v4layout);
//    h2layout->addLayout(v5layout);

    //Finsh

    QVBoxLayout *v1layout = new QVBoxLayout;
//    QLabel *feedback = new QLabel;
//    feedback->setText("Set Feedback");

    // construct auto-complete widget
    QtMaterialAutoComplete *autoc = new QtMaterialAutoComplete;
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

    autoc->setDataSource(mydata);


    //configure the color and font
    autoc->setLabelColor(QColor("white"));
    autoc->setLabel("Input Feed Back");
    autoc->setLabelFontSize(8);
    autoc->setInputLineColor(QColor("#d7f6f6"));
    autoc->setInkColor(QColor("white"));
    autoc->setLabelColor(QColor("white"));
    autoc->setTextColor(Qt::white);


//    v1layout->addWidget(feedback);
    approache->setText("进针");
    approache->setCheckable(false);
    approache->setHaloVisible(false);
    approache->setBackgroundColor(QColor(76,76,76));
    approache->setFixedWidth(160);
    QHBoxLayout *h12layout = new QHBoxLayout;
    h12layout->addWidget(autoc);
    h12layout->addWidget(approache);
    v1layout->addLayout(h12layout);

    QVBoxLayout *v2layout = new QVBoxLayout;
    begin->setCheckable(false);
    begin->setText("开始扫描");
    begin->setHaloVisible(false);
    begin->setBackgroundColor(QColor(76,76,76));
    warning = end;
    end->setCheckable(false);
    end->setText("退针");
    end->setHaloVisible(false);
    end->setBackgroundColor(QColor(76,76,76));

    v2layout->addLayout(h11layout);
    v2layout->addWidget(tumbler);
    v2layout->addLayout(h2layout);
    v2layout->addLayout(v1layout);
    v2layout->addWidget(begin);
    v2layout->addWidget(end);

    QHBoxLayout *h1layout = new QHBoxLayout;
    QPixmap *pix = new QPixmap(400,300);
    pix->fill(Qt::darkCyan);
    QLabel *ccd = new QLabel;
    ccd->setPixmap(*pix);
    QVBoxLayout *v11layout = new QVBoxLayout;
    v11layout->addWidget(ccd);
    v11layout->addLayout(h5layout);
//    h1layout->addWidget(ccd);
    h1layout->addLayout(v11layout);
    h1layout->addLayout(v2layout);

    QVBoxLayout *v3layout = new QVBoxLayout;
    v3layout->addLayout(hlayout);
    v3layout->addLayout(h1layout);
    setStyleSheet("*{background:#4c4c4c }"
                  "Frame{border:3px}"
                  "QLabel{color:white}"
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
    invoker->start(1000);

}

void UXAUTOP::closeEvent(QCloseEvent *event) //used to show waring when click close but the probe not backward
{
    if(warning->text() == QString("退针完成"))
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

    if(warning->text() != QString("退针完成"))
        event->ignore();
    connect(confrom,SIGNAL(clicked(bool)),pleaseend,SLOT(hide()));
}

void UXAUTOP::approchestart()
{
    if(!approchbegin){
        approache->setEnabled(true);
        approache->setText("正在进针");
        connect(invoker,SIGNAL(timeout()),approache,SLOT(invokeriddle()));
        approchbegin = true;

    }
    else{
        disconnect(invoker,SIGNAL(timeout()),approache,SLOT(invokeriddle()));
        approache->setEnabled(false);
        approache->setText("进针完成");
        approchbegin = false;

        begin->setEnabled(true);
        begin->setText("开始扫描");
    }
}

void UXAUTOP::beginstart()
{
    if(!beginbegin){
        begin->setEnabled(true);
        begin->setText("正在扫描");
        connect(invoker,SIGNAL(timeout()),begin,SLOT(invokeriddle()));
        beginbegin = true;

    }
    else{
        disconnect(invoker,SIGNAL(timeout()),begin,SLOT(invokeriddle()));
        begin->setEnabled(false);
        begin->setText("扫描完成");
        beginbegin = false;
        end->setEnabled(true);
        end->setText("退针");
    }
}

void UXAUTOP::endstart()
{
    if(!endbegin){
        end->setEnabled(true);
        end->setText("正在退针");
        connect(invoker,SIGNAL(timeout()),end,SLOT(invokeriddle()));
        endbegin = true;

    }
    else{
        disconnect(invoker,SIGNAL(timeout()),end,SLOT(invokeriddle()));
        end->setEnabled(false);
        end->setText("退针完成");
        endbegin = false;
        approache->setEnabled(true);
        approache->setText("进针");
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
