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
    if (year < 1970 || year > 2008)
        return false;

    if (month < 1 || month > 12)
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

        if (student.Ball[i] == 3)
            return false;
    }

    return true;
}

bool hasGoodOrExcellentPhysicsChemistry(
    const Students& student)
{
    return student.Ball[1] >= 4 &&
           student.Ball[2] >= 4;
}

int utf8Length(const char* text)
{
    int length = 0;

    for (int i = 0; text[i] != '\0'; i++) {

        unsigned char c = (unsigned char)text[i];

        if ((c & 0xC0) != 0x80)
            length++;
    }

    return length;
}

void printField(const char* text, int width)
{
    int length = utf8Length(text);

    printf("%s", text);

    for (int i = length; i < width; i++) {
        printf(" ");
    }
}

int main()
{
    const int N = 3;

    Students student[N];

    int SIZE = sizeof(Students);

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

            printf("Введите дату рождения "
                   "(день месяц год): ");


            if (scanf("%d %d %d",
                      &student[i].day,
                      &student[i].month,
                      &student[i].year) != 3) {

                printf("Ошибка ввода! "
                       "Введите три числа.\n");

                while (getchar() != '\n');

                continue;
            }


            if (!isValidDate(student[i].day,
                             student[i].month,
                             student[i].year)) {

                printf("Ошибка! Некорректная дата. "
                       "Проверьте день, месяц и год "
                       "(1970-2008).\n");
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

    printf("\n\nСПИСОК СТУДЕНТОВ\n\n");

    printField("№", 4);
    printField("Фамилия", 18);
    printField("Имя", 18);
    printField("Дата рождения", 18);
    printField("Математика", 14);
    printField("Физика", 10);
    printField("Химия", 10);

    printf("\n");

    for (int i = 0; i < N; i++) {

        printf("%-4d", i + 1);

        printField(student[i].Surname, 18);
        printField(student[i].Name, 18);

        printf("%02d.%02d.%04d",
               student[i].day,
               student[i].month,
               student[i].year);

        printf("%-4s", "");

        printf("%14d",
               student[i].Ball[0]);

        printf("%10d",
               student[i].Ball[1]);

        printf("%9d",
               student[i].Ball[2]);

        printf("\n");
    }

    printf("\n\n");
    printf("СТУДЕНТЫ, НЕ ПОЛУЧИВШИЕ НИ ОДНОЙ ТРОЙКИ\n\n");


    printField("Фамилия", 18);
    printField("Имя", 18);
    printField("Дата рождения", 18);

    printf("\n");


    int count = 0;


    for (int i = 0; i < N; i++) {

        if (hasNoThrees(student[i])) {

            printField(student[i].Surname, 18);
            printField(student[i].Name, 18);

            printf("%02d.%02d.%04d",
                   student[i].day,
                   student[i].month,
                   student[i].year);

            printf("\n");

            count++;
        }
    }


    if (count == 0) {

        printf("Таких студентов нет.\n");
    }

    printf("\n\n");

    printf("СТУДЕНТЫ С ОЦЕНКАМИ 4 ИЛИ 5 "
           "ПО ФИЗИКЕ И ХИМИИ\n\n");


    count = 0;


    for (int i = 0; i < N; i++) {

        if (hasGoodOrExcellentPhysicsChemistry(
                student[i])) {

            printField(student[i].Surname, 18);
            printField(student[i].Name, 18);

            printf("дата рождения: ");

            printf("%02d.%02d.%04d\n",
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