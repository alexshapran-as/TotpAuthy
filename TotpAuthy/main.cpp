#include "totpauthy.h"
#include <QApplication>
#include <QDateTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/icons/icon.ico"));
    TotpAuthy w;
    w.show();
    return a.exec();
}
