#include "grade_school.h"

void init_roster(roster_t *roster)
{
    roster->count = 0;
}

static int qsortCompare(const void *elem0, const void *elem1) // https://beej.us/guide/bgc/html/split/stdlib.html#man-qsort
{
    const student_t *x = elem0, *y = elem1;

    if (x->grade > y->grade)
        return 1;
    if (x->grade < y->grade)
        return -1;
    return strcmp(x->name, y->name);
}
bool add_student(roster_t *roster, char name[], uint8_t grade)
{
    if (roster->count >= MAX_STUDENTS)
    {
        fprintf(stderr, "Error. The roster is already full\n");
        return false;
    }
    if (strlen(name) >= MAX_NAME_LENGTH)
    {
        fprintf(stderr, "Error, the name is too long\n");
        return false;
    }
    for (size_t j = 0; j < roster->count; j++)
    {
        if (strcmp(roster->students[j].name, name) == 0)
        {
            fprintf(stderr, "Error, the student already exists\n");
            return false;
        }
    }
    strcpy(roster->students[roster->count].name, name);
    roster->students[roster->count].grade = grade;
    roster->count++;
    qsort(roster->students, roster->count, sizeof(student_t), qsortCompare);

    return true;
}

roster_t get_grade(const roster_t *roster, uint8_t desired_grade)
{
    roster_t rosterForGrade;

    int count = 0;
    for (size_t i = 0; i < roster->count; i++)
    {
        if (roster->students[i].grade == desired_grade)
        {
            rosterForGrade.students[count++] = roster->students[i];
        }
    }
    rosterForGrade.count = count;

    return rosterForGrade;
}
