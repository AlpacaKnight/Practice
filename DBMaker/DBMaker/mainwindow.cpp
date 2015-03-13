#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->OTP,SIGNAL(clicked()),this,SLOT(on_Make_OTP_Database()));
    connect(ui->KEY,SIGNAL(clicked()),this,SLOT(on_Make_KEY_Database()));
    //ui->lblMsg->setText(QString::fromUtf8("结果显示"));

    get_path(path_of_current);
    qDebug()<<"当前位置为："<<path_of_current;
#if defined(WIN32)
#ifdef QT_DEBUG
    m_dbname = path_of_current + "/.." + DATABASE_PATH;
#else
    m_dbname = path_of_current + DATABASE_PATH;
#endif
#elif defined(linux)
    m_dbname = path_of_current +DATABASE_PATH;
#endif
    if(QFile ::exists(m_dbname))
    {
        qDebug()<<"发现文件:"<<m_dbname;
        QFile::remove(m_dbname);
        qDebug()<<"文件"<<m_dbname<<"已删除！";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::on_Make_OTP_Database()
{
    qDebug()<<"start making OTP Database";

    m_name = "seeds";
//设置txt文件路径
#if defined(WIN32)
#ifdef QT_DEBUG
    m_srcname = path_of_current + "/../" + SEED_TEXT_PATH;
#else
    m_srcname = SEED_TEXT_PATH;
#endif
#elif defined(linux)
    m_srcname = SEED_TEXT_PATH;
#endif

//删除已有的数据库
#if defined(WIN32)
#ifdef QT_DEBUG
    m_dbname = path_of_current + "/.." + DATABASE_PATH;
#else
    m_dbname = path_of_current + DATABASE_PATH;
#endif
#elif defined(linux)
    m_dbname = path_of_current +DATABASE_PATH;
#endif
    if(QFile ::exists(m_dbname))
    {
        qDebug()<<"发现文件:"<<m_dbname;
        QFile::remove(m_dbname);
        qDebug()<<"文件"<<m_dbname<<"已删除！";
    }
//删除已有的sql文件
#if defined(WIN32)
#ifdef QT_DEBUG
    m_sqlname = path_of_current +"/.." + SEED_SQL_PATH;
#else
    m_sqlname = path_of_current +SEED_SQL_PATH;
#endif
#elif defined(linux)
    m_sqlname = path_of_current +SEED_SQL_PATH;
#endif
    if (QFile ::exists(m_sqlname))
    {
        qDebug()<<"发现文件:"<<m_sqlname;
        QFile::remove(m_sqlname);// 刪除文件
        qDebug()<<"文件"<<m_sqlname<<"已删除！";
    }
    if(!_do_make_database(m_name,m_srcname,m_sqlname))
    {
        ui->lblMsg->setStyleSheet("QLabel { background-color:#ff0000; color:#ffffff; }");
        ui->lblMsg->setText(QString::fromUtf8("Database for OTP make failed"));
    }
    else
    {
        ui->lblMsg->setStyleSheet("QLabel { background-color:#00ff00; color:#ffffff; }");
        ui->lblMsg->setText(QString::fromUtf8("Database for OTP make success"));
    }

    return true;
}

bool MainWindow::on_Make_KEY_Database()
{
    qDebug()<<"start making KEY Database";

    m_name = "sn";
    //设置txt文件路径
#if defined(WIN32)
    #ifdef QT_DEBUG
        m_srcname = path_of_current + "/../" + SN_TEXT_PATH;
    #else
        m_srcname = SN_TEXT_PATH;
    #endif
#elif defined(linux)
        m_srcname = SN_TEXT_PATH;
#endif

//删除已有的数据库
#if defined(WIN32)
#ifdef QT_DEBUG
    m_dbname = path_of_current + "/.." + DATABASE_PATH;
#else
    m_dbname = path_of_current + DATABASE_PATH;
#endif
#elif defined(linux)
    m_dbname = path_of_current +DATABASE_PATH;
#endif
    if(QFile ::exists(m_dbname))
    {
        qDebug()<<"发现文件:"<<m_dbname;
        QFile::remove(m_dbname);
        qDebug()<<"文件"<<m_dbname<<"已删除！";
    }

//删除已有的sql文件
#if defined(WIN32)
#ifdef QT_DEBUG
    m_sqlname = path_of_current +"/.." + SN_SQL_PATH;
#else
    m_sqlname = path_of_current + SN_SQL_PATH;
#endif
#elif defined(linux)
    m_sqlname = path_of_current +SN_SQL_PATH;
#endif
    if (QFile ::exists(m_sqlname))
    {
        qDebug()<<"发现文件:"<<m_sqlname;
        QFile::remove(m_sqlname);// 刪除文件
        qDebug()<<"文件"<<m_sqlname<<"已删除！";
    }
    if(!_do_make_database(m_name,m_srcname,m_sqlname))
    {
        ui->lblMsg->setStyleSheet("QLabel { background-color:#ff0000; color:#ffffff; }");
        ui->lblMsg->setText(QString::fromUtf8("Database for USB-Key make failed"));
    }
    else
    {
        ui->lblMsg->setStyleSheet("QLabel { background-color:#00ff00; color:#ffffff; }");
        ui->lblMsg->setText(QString::fromUtf8("Database for USB-Key make success"));
    }
    return true;
}

bool MainWindow::_do_make_database(QString name,QString srcname, QString sqlname)
{
    QFile file_c(srcname);
    if (!file_c.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"打开 .txt 文件失败 !";
        //ui->lblMsg->setStyleSheet("QLabel { background-color:#ff0000; color:#ffffff; }");
        if("sn" == name)
        {
            ui->lblMsg_2->setText(QString::fromUtf8("there is no file [sn.txt]"));
        }
        else if("seeds" == name)
        {
            ui->lblMsg_2->setText(QString::fromUtf8("there is no file [seeds.txt]"));
        }
        return false;
    }
    int num = 0;
    QTextStream count(&file_c);
    while (!count.readLine().isNull())
    { num ++; }
    qDebug()<<"open "<<num<<" log data";
    //qDebug()<<"打开源文件,共找到"<<num<<"条记录...";
    file_c.close();

    QFile file_s(srcname);
    if (!file_s.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"打开 .txt 文件失败 !";
        if("sn" == name)
        {
            ui->lblMsg_2->setText(QString::fromUtf8("there is no file [sn.txt]"));
        }
        else if("seeds" == name)
        {
            ui->lblMsg_2->setText(QString::fromUtf8("there is no file [seeds.txt]"));
        }
        return false;
    }
    QTextStream in(&file_s);
    qDebug()<<"正在准备生成 .sql 文件...";
    QFile file_d(sqlname);
    if (!file_d.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug()<<"创建 .sql 文件失败 !";
        ui->lblMsg_2->setText(QString::fromUtf8("creat .sql file failed"));
        return false;
    }
    QTextStream out(&file_d);
    qDebug()<<"生成表头...";
    out << "PRAGMA foreign_keys=OFF;\nBEGIN TRANSACTION;\n";
    out << "-- ----------------------------\n";
    out << "-- Table structure for SN_SEED\n";
    out << "-- ----------------------------\n";
    out << "CREATE TABLE SN_SEED(\n";
    out << "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL ON CONFLICT ABORT COLLATE NOCASE  DEFAULT 1,\n";
    out << "SN varchar2(32)NOT NULL ON CONFLICT ABORT COLLATE NOCASE ,\n";
    out << "SEED varchar2(128) NOT NULL ON CONFLICT ABORT COLLATE NOCASE ,\n";
    out << "FLAG INTEGER NOT NULL ON CONFLICT ABORT COLLATE NOCASE  DEFAULT 0\n";
    out << ");\n";
    out << "-- ----------------------------\n";
    out << "-- Records of SN_SEED\n";
    out << "-- ----------------------------\n";
    qDebug()<<"开始转换...";
    int i= 1;
    QString line = in.readLine();
    while (!line.isNull())
    {
        num --;
        if ("sn"==name)
        {
            out << "INSERT INTO SN_SEED VALUES ("<<i<<",'"<<line<<"','', 0);\n";
        }
        else if ("seeds" == name)
        {
            QStringList sections = line.split(" ");
            out << "INSERT INTO SN_SEED VALUES ("<<i<<",'"<<sections.at(0)<<"','"<<sections.at(1)<<"', 0);\n";
        }
        else
        {
            qDebug()<<"【error!!】:there is no sn/seeds.txt file.";
        }
        //qDebug()<<"转换第"<<i<<"条记录，剩余"<<num<<"条记录...";
        fflush(stdout);


        //usleep(100);
        line = in.readLine();
        i ++;
    }
    out << "COMMIT;\n";
    printf("\n");
    file_d.close();
    file_s.close();
    qDebug()<<".SQL文件生成完毕";

    qDebug()<<"正在准备生成 .db 文件...";
    ui->lblMsg_2->setText(QString::fromUtf8("make .db now..."));
#if defined(WIN32)
#ifdef QT_DEBUG
    QString cmd = path_of_current + "/sqlite3.exe " + path_of_current + "/../../data/database.db \".read "+sqlname+"\"";
#else
    QString cmd = path_of_current + "/sqlite3.exe " + path_of_current + "/../data/database.db \".read "+sqlname+"\"";
#endif
    if (-1 == system(cmd.toLatin1()))
    {
        qDebug()<<"生成.db文件失败!";
        ui->lblMsg_2->setText(QString::fromUtf8("make .db file failed"));
        return false;
    }
    else
    {
        qDebug()<<"生成 .db 文件完毕!";
    }
#elif defined(linux)
    qDebug()<<"sqlname :"<<sqlname;
    QString cmd = "sqlite3 ../data/database.db \".read "+sqlname+"\"";
    if (-1 == system(cmd.toLatin1()))
    {
        qDebug()<<"生成.db文件失败!";
        ui->lblMsg_2->setText(QString::fromUtf8("make .db file failed"));
        return false;
    }
    else
    {
        qDebug()<<"生成 .db 文件完毕!";
    }
#endif
    qDebug()<<"全部转换完成!";
    ui->lblMsg_2->setText(QString::fromUtf8("all things is over"));

    return true;
}

void MainWindow::get_path(QString &strfile)
{
    strfile = QCoreApplication::applicationDirPath();
    qDebug()<<strfile;
}
