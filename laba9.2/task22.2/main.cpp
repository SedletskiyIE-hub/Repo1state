//На каждом этаже M-этажного дома жилых N комнат, каждая из которых имеет форму
//прямоугольника. Длина и ширина каждой комнаты известны. Определить, какой из
//этажей дома имеет минимальную жилую площадь. Если таких несколько, то вывести
//хотя бы одного из них.

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

    int floor, rooms, minIndexFloor, minIndexRoom, minIndexSizeRoom;
    int size_room = 2;

    cout << "Введите количество этажей: ";
    cin >> floor;

    while (floor < 1) {
        cout << "Ошибка! Количество этажей должно быть больше нуля."
             << "Введите количество этажей еще раз: ";
        cin >> floor;
    }

    cout << "Введите количество комнат на этаже: ";
    cin >> rooms;

    while (rooms < 1) {
        cout << "Ошибка! Количество комнат должно быть больше нуля."
             << "Введите количество комнат еще раз: ";
        cin >> rooms;
    }

    int*** real = (int***)malloc(floor * sizeof(int**));

    for(int i = 0; i < floor; i++){

        real[i] = (int**)malloc(rooms * sizeof(int*));

        for(int j = 0; j < rooms; j++){

            real[i][j] = (int*)malloc(size_room * sizeof(int));

        }

    }

    cout << "Введите минимальный индекс этажей: ";
    cin >> minIndexFloor;

    cout << "Введите минимальный индекс комнат: ";
    cin >> minIndexRoom;

    cout << "Введите минимальный индекс размера комнаты: ";
    cin >> minIndexSizeRoom;

    int*** temp = (int***)malloc(floor*sizeof(int**));

    for (int i = 0; i < floor; i++){

        temp[i] = real[i] - minIndexRoom;

        for (int j = 0; j < rooms; j++){

            temp[i][j] = real[i][j] - minIndexSizeRoom;

        }

    }

    int*** arr = temp - minIndexFloor;

    unsigned long long min_square = ~0ULL, temp_square;
    int floor_number = 0;

    srand(time(0));

    for (int i = minIndexFloor; i < minIndexFloor + floor; i++) {
        for (int j = minIndexRoom; j < minIndexRoom + rooms; j++) {
            for (int k = minIndexSizeRoom; k < minIndexSizeRoom + size_room; k++) {
                arr[i][j][k] = rand() % 5 + 1;
            }
        }
    }

    for (int i = minIndexFloor; i < minIndexFloor + floor; i++) {
        temp_square = 0;

        for (int j = minIndexRoom; j < minIndexRoom + rooms; j++) {
            temp_square += arr[i][j][minIndexSizeRoom] * arr[i][j][minIndexSizeRoom + 1];
        }

        if (temp_square < min_square) {
            min_square = temp_square;
            floor_number = i;
        }
    }

    cout << "\nМинимальная площадь: " << min_square << endl;
    cout << "Номер этажа: " << floor_number  << "\n\n";

    for (int i = minIndexFloor; i < minIndexFloor + floor; i++) {
        cout << "Этаж номер " << i << ":\n";

        for (int j = minIndexRoom; j < minIndexRoom + rooms; j++) {
            cout << "Комната " << j << ":   ";

            for (int k = minIndexSizeRoom; k < minIndexSizeRoom + size_room; k++) {
                cout << arr[i][j][k] << "     ";
            }

            cout << "\n";
        }

        cout << "\n";
    }

    for(int i = 0; i < floor; i++){

        for(int j = 0; j < rooms; j++){

            free(real[i][j]);

        }

        free(real[i]);

    }

    free(real);

    free(temp);

    return 0;
}