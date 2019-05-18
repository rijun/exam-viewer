#ifndef EXAM_H
#define EXAM_H
#include <QString>
#include <QVector>

struct Grade
{
    QString value;
    int count;
};

class Exam
{
public:
    Exam();
    void setExamResults();

private:
    QVector<Grade> gradeList;
    void initGradeList();
};

#endif // EXAM_H
