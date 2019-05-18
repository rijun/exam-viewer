#ifndef EDITEXAMDIALOG_H
#define EDITEXAMDIALOG_H

#include <QDialog>

namespace Ui {
class ExamDialog;
}

class ExamDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExamDialog(QWidget *parent = nullptr);
    ~ExamDialog();

private:
    Ui::ExamDialog *ui;
};

#endif // EDITEXAMDIALOG_H
