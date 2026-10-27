#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Students {
    char Surname[50];
    char Name[50];

    int day;
    int month;
    int year;

    int Ball[3];
};

bool isLeapYear(int year)
{
    return (year % 400 == 0) ||
           (year % 4 == 0 && year % 100 != 0);
}

bool isValidDate(int day, int month, int year)
{
    if (month < 1 || month > 12)
        return false;
    
    if (year < 1970 || year > 2008)
        return false;

    bool leapYear = isLeapYear(year);

    int daysInMonth =
        (month == 2)
        ? (leapYear ? 29 : 28)
        : ((month == 4 ||
            month == 6 ||
            month == 9 ||
            month == 11)
            ? 30
            : 31);

    return day >= 1 && day <= daysInMonth;
}

bool hasNoThrees(const Students& student)
{
    for (int i = 0; i < 3; i++) {
        if (student.Ball[i] == 3) {
            return false;
        }
    }

    return true;
}

bool hasGoodOrExcellentPhysicsChemistry(const Students& student)
{
    if (student.Ball[1] >= 4 &&
        student.Ball[2] >= 4) {
        return true;
    }

    return false;
}

int main()
{
    const int N = 3;
    Students student[N];

    for (int i = 0; i < N; i++) {

        printf("\nСтудент №%d\n", i + 1);

        printf("Введите фамилию и имя: ");

        if (scanf("%49s %49s",
                  student[i].Surname,
                  student[i].Name) != 2) {

            printf("Ошибка ввода!\n");
            return 1;
        }

        bool dateCorrect = false;

        while (!dateCorrect) {

            printf("Введите дату рождения (день месяц год): ");

            if (scanf("%d %d %d",
                      &student[i].day,
                      &student[i].month,
                      &student[i].year) != 3) {

                printf("Ошибка ввода! Введите три числа.\n");

                while (getchar() != '\n');

                continue;
            }

            if (!isValidDate(student[i].day,
                             student[i].month,
                             student[i].year)) {

                printf("Ошибка! Некорректная дата. "
                       "Попробуйте ещё раз.\n");
            }
            else {
                dateCorrect = true;
            }
        }
    }

    srand(time(0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            student[i].Ball[j] = rand() % 4 + 2;
        }
    }

    printf("\nСПИСОК СТУДЕНТОВ\n\n");

    printf("%-4s %-18s %-18s %-15s %-12s %-8s %-8s\n",
           "№",
           "Фамилия",
           "Имя",
           "Дата рождения",
           "Математика",
           "Физика",
           "Химия");

    for (int i = 0; i < N; i++) {

        printf("%-4d %-18s %-18s %02d.%02d.%04d   %-12d %-8d %-8d\n",
               i + 1,
               student[i].Surname,
               student[i].Name,
               student[i].day,
               student[i].month,
               student[i].year,
               student[i].Ball[0],
               student[i].Ball[1],
               student[i].Ball[2]);
    }

    printf("\nСТУДЕНТЫ, НЕ ПОЛУЧИВШИЕ НИ ОДНОЙ ТРОЙКИ\n\n");

    int count = 0;

    printf("%-18s %-18s %-15s\n",
           "Фамилия",
           "Имя",
           "Дата рождения");

    for (int i = 0; i < N; i++) {

        if (hasNoThrees(student[i])) {

            printf("%-18s %-18s %02d.%02d.%04d\n",
                   student[i].Surname,
                   student[i].Name,
                   student[i].day,
                   student[i].month,
                   student[i].year);

            count++;
        }
    }

    if (count == 0) {
        printf("Таких студентов нет.\n");
    }

    printf("\nСТУДЕНТЫ С ОЦЕНКАМИ 4 ИЛИ 5 ПО ФИЗИКЕ И ХИМИИ\n\n");

    count = 0;

    for (int i = 0; i < N; i++) {

        if (hasGoodOrExcellentPhysicsChemistry(student[i])) {

            printf("%s %s, дата рождения: %02d.%02d.%04d\n",
                   student[i].Surname,
                   student[i].Name,
                   student[i].day,
                   student[i].month,
                   student[i].year);

            count++;
        }
    }

    if (count == 0) {
        printf("Таких студентов нет.\n");
    }

    printf("\n");

    return 0;
}