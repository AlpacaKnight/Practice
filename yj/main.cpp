﻿#include "yj.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

  //  QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

   // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
   // QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
 //  QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
  //  QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb2312"));
    yj w;
    w.show();
    
    return a.exec();
}