#ifndef ACCOUNTITEM_H
#define ACCOUNTITEM_H

#include <QLabel>
#include <QWidget>
#include "totpauthy.h"

class TotpAuthy;

namespace Ui {
class AccountItem;
}

class AccountItem : public QWidget
{
    Q_OBJECT

public:
    explicit AccountItem(TotpAuthy * totpAuthyParent);
    ~AccountItem();
    QLabel * getAccountTotpKeyLabel();

private slots:
    void on_refreshTOTPKeyPushButton_clicked();

private:
    TotpAuthy * totpAuthyParentWidget;
    Ui::AccountItem *ui;
};

#endif // ACCOUNTITEM_H
