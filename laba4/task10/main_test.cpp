//Дан одномерный массив из 1000 элементов, состоящий из
//случайных целых чисел в диапазоне от 0 до 9. Найти произведение
//элементов массива, с конца массива до первого элемента, равного нулю.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int a, b;
    b = rand();
    a = rand();
    printf("%d\n", b * b);
    printf("%d\n", a);
    
    srand(16807);
    a = rand();
    printf("%d\n", a);
    
    srand(2);
    a = rand();
    printf("%d\n", a);

    srand(4);
    a = rand();
    printf("%d\n", a/b);

    return 0;
}