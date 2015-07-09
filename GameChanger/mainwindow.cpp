#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    * set background image
    */
#if 1
    QPixmap bgImages(":/background.jpg");
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background,bgImages);
    this->setPalette(bgPalette);

    setMask(bgImages.mask());// set background mask attribute same as background's image
#endif

    label =new QLabel;

    qsrand(QTime::currentTime().msec());
    timer=new QTimer();
    timer->setInterval(50);
    timer->start();
    //链接
    connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
    //初始化服务器名字列表
    for(int i=0;i<7;i++)
    {
        QString str = "网通"+ QString::number(i+1, 10) + "区";
        Netcom[i] = str;
        //Netcom[i] = QString("网通一区");
        //qDebug()<<Netcom[i];
    }
    for(int i=0;i<18;i++)
    {
        QString str = "电信"+ QString::number(i+1, 10) + "区";
        Netcom[i] = str;
        //qDebug()<<Netcom[i];
    }
    edu = "教育网专区";
    testserver = "试炼之地";
    other[0] = "虚空之地";
    other[1] = "强者世界";
    other[2] = "移动网专区";

    pFlag = false;

    connect(ui->Btn,SIGNAL(clicked()),this,SLOT(changePflag()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter logo(this);
    if(pFlag){
        QString imgpath;
        if(0 == index)//如果选择网通
        {
            int ind=qrand()%6+1;
            imgpath=":/Image/Netcom0";
            imgpath+=QString::number(ind);
            imgpath+=".png";
        }
        else if(1 == index)//如果是电信区
        {
            int ind=qrand()%18+1;
            if(ind<10)
            {
                imgpath=":/Image/Chinanet0";
            }else{
                imgpath=":/Image/Chinanet";
            }
            imgpath+=QString::number(ind);
            imgpath+=".png";
        }
        else if(2 == index)//教育网专区
        {
            //弹窗打印提示信息
            imgpath=":/Image/edu.png";
        }
        else if(3 == index)//体验服
        {
            //弹窗打印提示信息
            imgpath=":/Image/test1.png";
        }
        else//其他服务器
        {
            //随机其他服务器
            int ind=qrand()%3+1;
            imgpath=":/Image/other";
            imgpath+=QString::number(ind);
            imgpath+=".png";
        }
        img.load(imgpath);
#if 0
        QByteArray byte=names[ind-1].toLatin1();
        const char* name=byte.data();
        ui->name->setText(QString::fromLocal8Bit(name));
#elif 0
        ui->name->setText(QString::fromUtf8(names[ind-1]));
#else
        //ui->name->setText(QString::fromLocal8Bit("测试"));
        //ui->name->setText(names[ind-1]);
#endif
        logo.drawImage(150,100,img);
        //qDebug()<<"filename:"<<imgpath;
    }
    logo.drawImage(150,100,img);
}

void MainWindow::changePflag(){
//    if(((QPushButton*)sender())->objectName()=="begin"){
//        pFlag=true;
//    }
//    if(((QPushButton*)sender())->objectName()=="end"){
//        pFlag=false;
//    }
    index= ui->comboBox->currentIndex();
    if(2 == index||3 == index)
    {
        showMsg();
    }
    pFlag = !pFlag;
    if(!pFlag)
    {
        servername = ui->comboBox->currentText();
        qDebug()<<servername;
    }

}

void MainWindow::showMsg()
{
    label->setText(tr("Critical Message Box"));
    //QMessageBox::critical(this,tr("Are you SB?"),tr("there is the only one server which we can choose,Are you TMD dou wo?"));
    QMessageBox::critical(this,tr("Are you SB?"),tr("这个分类只有一个区,Are you TMD逗我?"));
    return;
}
