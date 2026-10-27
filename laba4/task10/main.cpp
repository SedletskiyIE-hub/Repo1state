//Дан одномерный массив из 1000 элементов, состоящий из
//случайных целых чисел в диапазоне от 0 до 9. Найти произведение
//элементов массива, с конца массива до первого элемента, равного нулю.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    const int n = 10;
    int n1 = n, n2 = n;
    int arr[n];
    unsigned long long product_of_numbers = 1;

    srand(time(0));

    for (int i = 0; i < n; i++){

        arr[i] = rand() % 10;

    }

    if (arr[n - 1] == 0){
       
        product_of_numbers = 0;

        printf("Произведение последних элементов для всех циклов: %llu\n", product_of_numbers);
    }

    else{

        for (int i = n - 1; i >= 0 && arr[i] != 0; i--){
    
            product_of_numbers *= arr[i];
        
        }

        printf("Произведение последних элементов: %llu\n", product_of_numbers);
        product_of_numbers = 1;

        
        
        while(arr[n1 - 1] != 0){

            product_of_numbers *= arr[n1 - 1];
            n1 -= 1;
        }

        printf("Произведение последних элементов: %llu\n", product_of_numbers);
        product_of_numbers = 1;

        do{

           product_of_numbers *= arr[n2 - 1]; 
           n2 -= 1;
        }

        while(arr[n2 - 1] != 0);

        printf("Произведение последних элементов: %llu\n", product_of_numbers);
        product_of_numbers = 1;

    }

    printf("Элементы массива: ");

    for (int i = 0; i < n; i++){

        printf("%d ", arr[i]);

    }

     printf("\n");

    return 0;

}