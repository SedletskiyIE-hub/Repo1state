//На каждом этаже трехэтажного дома жилых N комнат, каждая из
//которых имеет форму прямоугольника. Длина и ширина каждой комнаты
//известны. Определить, какой из этажей дома имеет минимальную жилую
//площадь. Если таких несколько, то вывести хотя бы одного из них.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    const int floor = 3;
    const int MAX_N = 100;
    const int size_room = 2;

    int n;

    printf("Введите количество комнат на этаже (1-%d): ", MAX_N);
    scanf("%d", &n);
    
    while (n < 1 || n > MAX_N) {
        printf("Ошибка! Количество комнат должно быть от 1 до %d. Введите количество комнат еще раз: ", MAX_N);
        scanf("%d", &n);
    }

    int arr[floor][MAX_N][size_room];

    unsigned long long min_square = ~0ULL, temp_square;
    int floor_number = 0;

    srand(time(0));

    for (int i = 0; i < floor; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < size_room; k++) {
                arr[i][j][k] = rand() % 10 + 1;
            }
        }
    }

    for (int i = 0; i < floor; i++) {
        temp_square = 0;

        for (int j = 0; j < n; j++) {
            temp_square += arr[i][j][0] * arr[i][j][1];
        }

        if (temp_square < min_square) {
            min_square = temp_square;
            floor_number = i;
        }
    }

    printf("\nМинимальная площадь: %llu\nНомер этажа: %d\n\n",
           min_square, floor_number + 1);

    for (int i = 0; i < floor; i++) {
        printf("Этаж номер %d:\n", i + 1);

        for (int j = 0; j < n; j++) {
            printf("Комната %d:   ", j + 1);

            for (int k = 0; k < size_room; k++) {
                printf("%-5d ", arr[i][j][k]);
            }

            printf("\n");
        }

        printf("\n");
    }

    return 0;
}