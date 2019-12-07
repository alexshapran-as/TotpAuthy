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
    AccountItem * accountItem = new AccountItem(this);
    this->secretKeys.insert(accountItem, key);
    accountItem->getAccountTotpKeyLabel()->setText(QGoogleAuth::generatePin(key.toUtf8()));
    QListWidgetItem * item = new QListWidgetItem(ui->listWidget);
    item->setSizeHint(accountItem->sizeHint());
    ui->listWidget->setItemWidget(item, accountItem);
}

void TotpAuthy::on_generateTotpCodePushButton_clicked()
{
    SecretKeyForm * secretKeyForm = new SecretKeyForm(this);
    secretKeyForm->show();
}
