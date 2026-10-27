// Дан одномерный массив из N (N=150) случайных целых чисел
// в диапазоне от 14 до 37 включительно.
// Вывести те числа, которые наиболее редко встречаются
// в массиве и количество их повторений.
// Подсчет количества повторений для числа оформить в виде функции.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    int N;
    int start_of_the_arr;
    int end_of_the_arr;

    printf("Введите количество элементов массива (1-%d): ", MAX_N);
    scanf("%d", &N);

    while (N < 1 || N > MAX_N)
    {
        printf("Ошибка! Количество элементов должно быть "
               "от 1 до %d.\n", MAX_N);

        printf("Введите количество элементов еще раз: ");
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
        printf("Ошибка! Конец диапазона должен быть "
               "больше или равен началу!\n");

        printf("Введите конец диапазона еще раз: ");
        scanf("%d", &end_of_the_arr);
    }

    int rangeSize = end_of_the_arr - start_of_the_arr + 1;

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % rangeSize + start_of_the_arr;
    }

    printf("\nИсходный массив:\n");

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    int minCount = N;

    for (int number = start_of_the_arr;
         number <= end_of_the_arr;
         number++)
    {
        int count = countNumber(arr, N, number);

        if (count > 0 && count < minCount)
        {
            minCount = count;
        }
    }

    printf("\nНаиболее редко встречающиеся числа:\n");

    for (int number = start_of_the_arr;
         number <= end_of_the_arr;
         number++)
    {
        int count = countNumber(arr, N, number);

        if (count == minCount)
        {
            printf("Число: %-5d Количество повторений: %d\n",
                   number, count);
        }
    }

    return 0;
}