#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int floor, rooms;
    int minIndexFloor, minIndexRoom, minIndexSizeRoom;

    int size_room = 2;

    cout << "Введите количество этажей: ";
    cin >> floor;

    while (floor < 1)
    {
        cout << "Ошибка! Количество этажей должно быть больше нуля.\n";
        cout << "Введите количество этажей еще раз: ";
        cin >> floor;
    }

    cout << "Введите количество комнат на этаже: ";
    cin >> rooms;

    while (rooms < 1)
    {
        cout << "Ошибка! Количество комнат должно быть больше нуля.\n";
        cout << "Введите количество комнат еще раз: ";
        cin >> rooms;
    }

    cout << "Введите минимальный индекс этажей: ";
    cin >> minIndexFloor;

    cout << "Введите минимальный индекс комнат: ";
    cin >> minIndexRoom;

    cout << "Введите минимальный индекс размера комнаты: ";
    cin >> minIndexSizeRoom;


    // -------------------------------------------------
    // 1. Вычисляем необходимые смещения
    // -------------------------------------------------

    int floorOffset = (minIndexFloor < 0) ? -minIndexFloor : 0;
    int roomOffset = (minIndexRoom < 0) ? -minIndexRoom : 0;
    int sizeOffset = (minIndexSizeRoom < 0) ? -minIndexSizeRoom : 0;


    // -------------------------------------------------
    // 2. Выделяем REAL
    // -------------------------------------------------

    int*** real = new int**[floor + floorOffset];

    for (int i = 0; i < floor + floorOffset; i++)
    {
        real[i] = new int*[rooms + roomOffset];

        for (int j = 0; j < rooms + roomOffset; j++)
        {
            real[i][j] = new int[size_room + sizeOffset];
        }
    }


    // -------------------------------------------------
    // 3. Создаём TEMP
    // -------------------------------------------------

    int*** temp = real + floorOffset;

    for (int i = 0; i < floor + floorOffset; i++)
    {
        temp[i] = real[i] + roomOffset;

        for (int j = 0; j < rooms + roomOffset; j++)
        {
            temp[i][j] = real[i][j] + sizeOffset;
        }
    }


    // -------------------------------------------------
    // 4. ARR
    // -------------------------------------------------

    int*** arr = temp;


    // -------------------------------------------------
    // 5. Заполняем
    // -------------------------------------------------

    srand(time(0));

    for (int i = minIndexFloor;
         i < minIndexFloor + floor;
         i++)
    {
        for (int j = minIndexRoom;
             j < minIndexRoom + rooms;
             j++)
        {
            for (int k = minIndexSizeRoom;
                 k < minIndexSizeRoom + size_room;
                 k++)
            {
                arr[i][j][k] = rand() % 5 + 1;
            }
        }
    }


    // -------------------------------------------------
    // 6. Ищем этаж с минимальной площадью
    // -------------------------------------------------

    unsigned long long min_square = ~0ULL;
    unsigned long long temp_square;

    int floor_number = minIndexFloor;

    for (int i = minIndexFloor;
         i < minIndexFloor + floor;
         i++)
    {
        temp_square = 0;

        for (int j = minIndexRoom;
             j < minIndexRoom + rooms;
             j++)
        {
            temp_square +=
                arr[i][j][minIndexSizeRoom] *
                arr[i][j][minIndexSizeRoom + 1];
        }

        if (temp_square < min_square)
        {
            min_square = temp_square;
            floor_number = i;
        }
    }


    cout << "\nМинимальная площадь: "
         << min_square << endl;

    cout << "Номер этажа: "
         << floor_number << "\n\n";


    // -------------------------------------------------
    // 7. Вывод
    // -------------------------------------------------

    for (int i = minIndexFloor;
         i < minIndexFloor + floor;
         i++)
    {
        cout << "Этаж номер " << i << ":\n";

        for (int j = minIndexRoom;
             j < minIndexRoom + rooms;
             j++)
        {
            cout << "Комната " << j << ": ";

            for (int k = minIndexSizeRoom;
                 k < minIndexSizeRoom + size_room;
                 k++)
            {
                cout << arr[i][j][k] << " ";
            }

            cout << "\n";
        }

        cout << "\n";
    }


    // -------------------------------------------------
    // 8. Освобождение
    // -------------------------------------------------

    for (int i = 0; i < floor + floorOffset; i++)
    {
        for (int j = 0; j < rooms + roomOffset; j++)
        {
            delete[] real[i][j];
        }

        delete[] real[i];
    }

    delete[] real;

    return 0;
}