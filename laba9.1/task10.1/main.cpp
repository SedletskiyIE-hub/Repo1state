#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int N, min_idN;
    float x, temp;

    srand(time(0));

    cout << "Введите количество элементов массива: ";
    cin >> N;

    while (N < 1)
    {
        cout << "Ошибка! Количество элементов должно быть больше нуля!" << endl;
        cout << "Введите количество элементов еще раз: ";
        cin >> N;
    }

    float* real_ptr = new float[N];

    cout << "Введите начальный индекс массива: ";
    cin >> min_idN;

    float* arr = real_ptr - min_idN;
    int max_idN = N + min_idN;

    cout << "Введите отрицательное число X (-45 < X < 0): ";
    cin >> x;

    while (x <= -45 || x >= 0)
    {
        cout << "Неверно введено число, повторите попытку: ";
        cin >> x;
    }

    for (int i = min_idN; i < max_idN; i++)
    {
        arr[i] = (float)rand() / RAND_MAX * 70 - 45;
    }

    for (int i = min_idN; i < max_idN; i++)
    {
        for (int j = min_idN; j < max_idN - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nОтрицательные элементы, большие X:\n";

    for (int i = min_idN; i < max_idN; i++)
    {
        if (arr[i] > x && arr[i] < 0)
        {
            cout << "Индекс элемента: " << i
                 << " Значение элемента: " << arr[i] << endl;
        }
    }

    delete[] real_ptr;
    real_ptr = nullptr;
    arr = nullptr;

    return 0;
}