#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct minNumber
{
    int Number;
    int number_of_repetitions;
};

int countNumber(int arr[], int size, int number)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == number)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    const int MAX_N = 150;

    int start_of_the_arr;
    int end_of_the_arr;
    int N;

    printf("Введите количество элементов массива (1-%d): ", MAX_N);
    scanf("%d", &N);

    while (N < 1 || N > MAX_N)
    {
        printf("Ошибка! Количество элементов должно быть от 1 до %d. "
               "Введите количество элементов еще раз: ", MAX_N);
        scanf("%d", &N);
    }

    int arr[MAX_N];

    srand(time(0));

    printf("Введите начало диапазона: ");
    scanf("%d", &start_of_the_arr);

    printf("Введите конец диапазона: ");
    scanf("%d", &end_of_the_arr);

    while (end_of_the_arr < start_of_the_arr)
    {
        printf("Ошибка! Конец диапазона должен быть больше начала! "
               "Введите конец диапазона еще раз: ");
        scanf("%d", &end_of_the_arr);
    }

    int rangeSize = end_of_the_arr - start_of_the_arr + 1;

    minNumber minNumbers[150];

    // Заполняем исходный массив
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % rangeSize + start_of_the_arr;
    }

    // Считаем количество повторений каждого числа
    for (int i = 0; i < rangeSize; i++)
    {
        minNumbers[i].Number = start_of_the_arr + i;

        minNumbers[i].number_of_repetitions =
            countNumber(arr, N, start_of_the_arr + i);
    }

    // Ищем минимальное количество повторений
    int minCount = N;

    for (int i = 0; i < rangeSize; i++)
    {
        if (minNumbers[i].number_of_repetitions > 0 &&
            minNumbers[i].number_of_repetitions < minCount)
        {
            minCount = minNumbers[i].number_of_repetitions;
        }
    }

    printf("\nНаиболее редко встречающиеся числа:\n");

    // Выводим все числа с минимальным количеством повторений
    for (int i = 0; i < rangeSize; i++)
    {
        if (minNumbers[i].number_of_repetitions == minCount)
        {
            printf("Число: %-8d Кол-во повторений: %-8d\n",
                   minNumbers[i].Number,
                   minNumbers[i].number_of_repetitions);
        }
    }

    printf("\nМассив:\n");

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}