#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <iostream>

using namespace std;

int love=0;
int m_time=0;
const char heart=3;

void Miss()
{
    for(love=0;love<=10;love++)
    {
        if(love==2||love==3||love==7||love==8)
        {
            cout<<heart;
        }
        else cout<<'\0';
    }
    cout<<endl;
    for(m_time=0;m_time<=9;m_time++)
        if(m_time>=1&&m_time!=5)
        {
            cout<<heart;
        }
        else cout<<'\0';
        cout<<endl;
}

void Forget()
{
    love=0;
    m_time=0;
    do
    {
    for(love=0;love<=10;love++)
    if(love>=m_time&&love<=10 - m_time)
    {
        cout<<heart;
    }
    else cout<<'\0';
    m_time++;
    cout<<endl;
    }
    while(m_time<=2);
    do
    {
    for(love=0;love<=10;love++)
    if(love >= m_time + 1 && love <= 9 - m_time)
    {
        cout<<heart;
    }
    else cout<<'\0';
    m_time++;
    cout<<endl;
    }
    while(m_time<=4);
}

int main(int argc, char *argv[])
{
    Miss();
    Forget();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
