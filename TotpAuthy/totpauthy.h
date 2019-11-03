#ifndef TOTPAUTHY_H
#define TOTPAUTHY_H

#include <QMainWindow>
#include "secretkeyform.h"
#include "accountitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TotpAuthy; }
QT_END_NAMESPACE

class TotpAuthy : public QMainWindow
{
    Q_OBJECT

public:
    TotpAuthy(QWidget *parent = nullptr);
    ~TotpAuthy();
    void setSecretKey(QString key);
    void refreshAccounts();

private slots:
    void on_generateTotpCodePushButton_clicked();

public:
    QString secretKey;

private:
    Ui::TotpAuthy *ui;
};
#endif // TOTPAUTHY_H
