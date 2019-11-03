#include "accountitem.h"
#include "ui_accountitem.h"
#include "qgoogleauth.h"

AccountItem::AccountItem(TotpAuthy *totpAuthyParent) :
    totpAuthyParentWidget(totpAuthyParent),
    ui(new Ui::AccountItem)
{
    ui->setupUi(this);
}

AccountItem::~AccountItem()
{
    delete ui;
}

QLabel *AccountItem::getAccountTotpKeyLabel()
{
    return ui->accountTOTPKeyLabel;
}

void AccountItem::on_refreshTOTPKeyPushButton_clicked()
{
    ui->accountTOTPKeyLabel->clear();
    ui->accountTOTPKeyLabel->setText(QGoogleAuth::generatePin(totpAuthyParentWidget->secretKey.toUtf8()));
//    QGoogleAuth::generatePin(totpParentWidget->getSecretKey().toUtf8())
}
