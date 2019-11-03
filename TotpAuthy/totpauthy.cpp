#include "totpauthy.h"
#include "ui_totpauthy.h"
#include "qgoogleauth.h"

TotpAuthy::TotpAuthy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TotpAuthy)
{
    ui->setupUi(this);
}

TotpAuthy::~TotpAuthy()
{
    delete ui;
}

void TotpAuthy::setSecretKey(QString key)
{
    this->secretKey = key;
}

void TotpAuthy::refreshAccounts()
{
    AccountItem * accountItem = new AccountItem(this);
    accountItem->getAccountTotpKeyLabel()->setText(QGoogleAuth::generatePin(secretKey.toUtf8()));
    QListWidgetItem * item = new QListWidgetItem(ui->listWidget);
    item->setSizeHint(accountItem->sizeHint());
    ui->listWidget->setItemWidget(item, accountItem);
}

void TotpAuthy::on_generateTotpCodePushButton_clicked()
{
    SecretKeyForm * secretKeyForm = new SecretKeyForm(this);
    secretKeyForm->show();
}
