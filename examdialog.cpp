#include "examdialog.h"
#include "ui_examdialog.h"

ExamDialog::ExamDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::ExamDialog)
{
    ui->setupUi(this);
}

ExamDialog::~ExamDialog()
{
    delete ui;
}
