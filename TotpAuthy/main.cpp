#include "totpauthy.h"
#include <QApplication>
#include <QDateTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TotpAuthy w;
    qDebug() << "Local time: " << QDateTime::currentDateTimeUtc();
    w.show();
    return a.exec();
}
