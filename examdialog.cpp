#include "examdialog.h"
#include "ui_examdialog.h"
#include <QMessageBox>

ExamDialog::ExamDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::ExamDialog)
{
    ui->setupUi(this);
    connect(ui->acceptButton, &QPushButton::clicked, this, &ExamDialog::inputDone);
    connect(ui->resetButton, &QPushButton::clicked, this, &ExamDialog::resetInput);
}

ExamDialog::~ExamDialog()
{
    delete ui;
}

void ExamDialog::inputDone()
{
    // Get all line edits and store them in a list
    QList<QLineEdit *> childLineEdits = this->findChildren<QLineEdit *>(QString(), Qt::FindDirectChildrenOnly);

    // Store all entries in a vector
    foreach (QLineEdit *lineEdit, childLineEdits)
    {
        bool ok;    // Flag for storing conversion success

        uint amount = lineEdit->text().toUInt(&ok);

        if (!ok)
        {
            handleInputError();
            return;
        }

        m_gradeAmountList.append(amount);
    }

    emit inputFinished();
}

void ExamDialog::resetInput()
{
    // Get all line edits and store them in a list
    QList<QLineEdit *> childLineEdits = this->findChildren<QLineEdit *>(QString(), Qt::FindDirectChildrenOnly);

    // Reset all entries
    foreach (QLineEdit *lineEdit, childLineEdits) {
        lineEdit->setText("");
    }
}

void ExamDialog::handleInputError()
{
    QMessageBox msgBox;
    msgBox.setText("There has been an input error.");
    msgBox.setInformativeText("Do you want retry?");
    msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Reset | QMessageBox::Close);
    msgBox.setDefaultButton(QMessageBox::Retry);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Retry:
          msgBox.close();
          break;
      case QMessageBox::Reset:
          resetInput();
          break;
      case QMessageBox::Cancel:
          reject(); // Close dialog via reject
          break;
      default:
          // should never be reached
          break;
    }
}
