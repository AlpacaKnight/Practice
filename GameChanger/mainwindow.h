#pragma warning (disable:4819)
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QImage>
#include <QTimer>
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QBitmap>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPixmap m_Pixmap;
    QImage img;
    QTimer* timer;
    QString Netcom[7];
    QString Chinanet[18];
    QString edu;
    QString testserver;
    QString other[3];

    bool pFlag;
    int index;//大区选择标记
    QString servername;//服务器名称
    QLabel *label;
public:
    void showMsg();
    void paintEvent(QPaintEvent *);
public slots:
    void changePflag();
};

#endif // MAINWINDOW_H
