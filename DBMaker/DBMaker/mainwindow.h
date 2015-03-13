#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QFile>
#include <stdio.h>
#if defined(WIN32)
#include <Qtimer>
#else
#include <QTimer>
#endif

#include "const.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString path_of_current;
    QString m_dbname;

    bool _do_make_database(QString m_name,QString m_srcname,QString m_sqlname);
    void get_path(QString &path_of_current);

private:
    Ui::MainWindow *ui;


    QString m_name;
    QString m_srcname;
    QString m_sqlname;

public slots:
    bool on_Make_OTP_Database(void);
    bool on_Make_KEY_Database(void);
};

#endif // MAINWINDOW_H
