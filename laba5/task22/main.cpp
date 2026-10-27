//22. Дан одномерный массив из N натуральных чисел не больших 10.
//Найти наибольший участок массива, состоящий из одинаковых чисел.
//Вывести длину этого участка.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    const int n = 10;
    int counter_numbers = 1, fin_counter = 1;
    int arr[n];
    srand(time(0));

    for (int i = 0; i < n; i++) arr[i] = rand() % 10 + 1;

    for (int i = 0; i < n - 1; i++){

        if (arr[i] == arr[i + 1]) counter_numbers++;

        else counter_numbers = 1;

        if (counter_numbers > fin_counter) fin_counter = counter_numbers;

    }

    printf("Длина наибольшего участка: %d\n", fin_counter);

    printf("Элементы массива: ");

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

     printf("\n");

    return 0;
}