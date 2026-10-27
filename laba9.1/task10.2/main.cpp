// Дан одномерный массив из N элементов, состоящий из случайных
// вещественных чисел в диапазоне от -45 до 25.
// Вывести в порядке невозрастания те отрицательные элементы
// массива, которые больше заданного числа X (-45 < X < 0).

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

    float* real_ptr = (float*)malloc(N * sizeof(float));

    if (real_ptr == NULL)
    {
        cout << "Ошибка выделения памяти!" << endl;
        return 1;
    }

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

    // Заполнение массива случайными числами от -45 до 25
    for (int i = min_idN; i < max_idN; i++)
    {
        arr[i] = (float)rand() / RAND_MAX * 70 - 45;
    }

    // Сортировка элементов по убыванию
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

    // Вывод отрицательных элементов, которые больше X
    for (int i = min_idN; i < max_idN; i++)
    {
        if (arr[i] > x && arr[i] < 0)
        {
            cout << "Индекс элемента: " << i
                 << " Значение элемента: " << arr[i] << endl;
        }
    }

    free(real_ptr);

    return 0;
}