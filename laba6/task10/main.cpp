//Дан двумерный массив из N строк и M столбцов. Определить,
//какая строка массива имеет максимальную сумму элементов (считать,
//что строк с одинаковой суммой нет).

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    const int n = 5;
    const int m = 5;
    long long max_sum = 0, sum;
    int number_line;
    int arr[n][m];

    srand(time(0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            arr[i][j] = rand() % 10 -5;
        }
    }

    for (int i = 0; i < n; i++){

        sum = 0;
        
        for (int j = 0; j < m; j++){
            sum += arr[i][j];
        }

        if (sum > max_sum){
            max_sum = sum;
            number_line = i;
        }
    }

    printf("Максимальная сумма: %lld\nНомер строки: %d\n", max_sum, number_line + 1);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

            printf("%-12d ", arr[i][j]);

        }

        printf("\n");

    }

    return 0;

}