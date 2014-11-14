#include "yj.h"
#include "ui_yj.h"
#include<QPainter>
#include<QTime>
#include<QTimer>
#include<QTextCodec>


yj::yj(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::yj)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    qsrand(QTime::currentTime().msec());
    timer=new QTimer();
    timer->setInterval(200);
    timer->start();
    //链接
    connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
    //初始化
    names[0]=QString("苍井空");
    names[1]=QString("吉泽明步");
    names[2]=QString("饭岛爱");
    names[3]=QString("松岛枫");
    names[4]=QString("武井咲");
    names[5]=QString("波多野结衣");
    names[6]=QString("大桥未久");
    names[7]=QString("小泽玛利亚");
    names[8]=QString("麻生希");
    names[9]=QString("初美理音");
    names[10]=QString("松岛菜菜子");
    names[11]=QString("并木优");
    names[12]=QString("东月风");
    names[13]=QString("武藤兰");
    names[14]=QString("西野翔");
    names[15]=QString("羽宫琴音");
    names[16]=QString("竹美凉子");
    names[17]=QString("早乙女露依");
    names[18]=QString("名字没查到");
    names[19]=QString("北条麻妃");
    names[20]=QString("樱井莉亚");
    
    pFlag = false;

    connect(ui->begin,SIGNAL(clicked()),this,SLOT(changePflag()));
    connect(ui->end,SIGNAL(clicked()),this,SLOT(changePflag()));
}
yj::~yj()
{
    delete ui;
}

void yj::paintEvent(QPaintEvent *){
    QPainter qp(this);
    if(pFlag){
        int ind=qrand()%21+1;
        QString imgpath=":/";
        imgpath+=QString::number(ind);
        imgpath+=".jpeg";
        img.load(imgpath);
#if 0
        QByteArray byte=names[ind-1].toLatin1();
        const char* name=byte.data();
        ui->name->setText(QString::fromLocal8Bit(name));
#elif 0
        ui->name->setText(QString::fromUtf8(names[ind-1]));
#else
     //   ui->name->setText(QString::fromLocal8Bit("测试"));
        ui->name->setText(names[ind-1]);
#endif
        qp.drawImage(150,100,img);
    }
    qp.drawImage(150,100,img);
}
void yj::changePflag(){
    if(((QPushButton*)sender())->objectName()=="begin"){
        pFlag=true;
    }
    if(((QPushButton*)sender())->objectName()=="end"){
        pFlag=false;
    }
}
