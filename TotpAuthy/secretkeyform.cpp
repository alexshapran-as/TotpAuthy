#include "secretkeyform.h"
#include "ui_secretkeyform.h"

SecretKeyForm::SecretKeyForm(TotpAuthy *totpAuthyParent) :
    totpAuthyParentWidget(totpAuthyParent),
    ui(new Ui::SecretKeyForm)
{
    ui->setupUi(this);
}

SecretKeyForm::~SecretKeyForm()
{
    delete ui;
}

void SecretKeyForm::on_pushButton_clicked()
{
    totpAuthyParentWidget->setSecretKey(ui->secretKeyLineEdit->text());
    this->hide();
    totpAuthyParentWidget->refreshAccounts();
    totpAuthyParentWidget->show();
}

void SecretKeyForm::on_pushButton_2_clicked()
{
    this->hide();
    totpAuthyParentWidget->show();
}
