#include "exam.h"

Exam::Exam()
{
    initGradeList();
}

void Exam::initGradeList()
{
    const QString gradeNames[] = { "1.0", "1.3", "1.7", "2.0", "2.3", "2.7", "3.0", "3.3", "3.7", "4.0", "5.0", "NE" };

    for(size_t i = 0; i < sizeof(gradeNames); i++)
    {
        Grade tempGrade;
        tempGrade.value = gradeNames[i];
        tempGrade.count = 0;
        gradeList.append(tempGrade);
    }
}

void setExamResults()
{

}
