//Дан одномерный массив из 100 элементов, состоящий из
//случайных вещественных чисел в диапазоне от -45 до 25. Вывести в
//порядке невозрастания (убывания) те отрицательные элементы этого
//массива, которые больше заданного числа Х (-45<X<0).

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int n = 100;
    float arr[n];
    float x, temp;

    srand(time(0));

    printf("Введите отрицательное число Х (-45 < X < 0): ");
    scanf("%f", &x);

    while (-45 >= x || x >= 0) {
        printf("Неверно введено число, повторите попытку: ");
        scanf("%f", &x);
    }

     for (int i = 0; i < n; i++){

        arr[i] = (double)rand() / RAND_MAX * 70 - 45;

    } 

    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){

            if (arr[j] < arr[j + 1]){

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }

    for(int i = 0; i < n - 1; i++){

        if (x < arr[i] && arr[i] < 0){

             printf("%10.3f", arr[i]);

        }
    }

    return 0;
}