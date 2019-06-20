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

public slots:
    void inputDone();
    void resetInput();

signals:
    void inputFinished();

private:
    Ui::ExamDialog *ui;
    QVector<unsigned int> m_gradeAmountList;

    void handleInputError();
};

#endif // EDITEXAMDIALOG_H
