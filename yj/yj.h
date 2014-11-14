#ifndef YJ_H
#define YJ_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QImage>
#include <QTimer>

namespace Ui {
class yj;
}

class yj : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit yj(QWidget *parent = 0);
    ~yj();
    
private:
    Ui::yj *ui;
    QImage img;
    QTimer* timer;
    QString names[21];
    bool pFlag;
public:
    void paintEvent(QPaintEvent *);
public slots:
    void changePflag();
};

#endif // YJ_H
