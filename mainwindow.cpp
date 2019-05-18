#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include "exam.h"
#include "examdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), m_exam(new ExamDialog)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete m_exam;
    delete ui;
}

void MainWindow::showExamDialog()
{
    m_exam->show();
}

bool MainWindow::openStoredExams()
{
    // To be implemented...
}

bool MainWindow::saveStoredExams()
{
    // To be implemented...
}
