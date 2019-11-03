#ifndef SECRETKEYFORM_H
#define SECRETKEYFORM_H

#include <QWidget>
#include "totpauthy.h"

class TotpAuthy;

namespace Ui {
class SecretKeyForm;
}

class SecretKeyForm : public QWidget
{
    Q_OBJECT

public:
    explicit SecretKeyForm(TotpAuthy *totpAuthyParent);
    ~SecretKeyForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    TotpAuthy * totpAuthyParentWidget;
    Ui::SecretKeyForm *ui;
};

#endif // SECRETKEYFORM_H
