#ifndef TOTPAUTHY_H
#define TOTPAUTHY_H

#include <QMainWindow>
#include <QMap>
#include "secretkeyform.h"
#include "accountitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TotpAuthy; }
QT_END_NAMESPACE

class AccountItem;

class TotpAuthy : public QMainWindow
{
    Q_OBJECT

public:
    TotpAuthy(QWidget *parent = nullptr);
    ~TotpAuthy();
    void setSecretKey(QString key);

private slots:
    void on_generateTotpCodePushButton_clicked();

public:
    QMap<AccountItem *, QString> secretKeys;

private:
    Ui::TotpAuthy *ui;
};
#endif // TOTPAUTHY_H
