#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Exam;
class ExamDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showExamDialog();

private:
    // Members
    Ui::MainWindow *ui;
    ExamDialog *m_exam = nullptr;
    QVector<Exam> m_examList;

    // Methods
    bool openStoredExams();
    bool saveStoredExams();
};

#endif // MAINWINDOW_H
