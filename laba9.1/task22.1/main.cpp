// Дан одномерный массив из N натуральных чисел не больших 10.
// Найти наибольший участок массива, состоящий из одинаковых чисел.
// Вывести длину этого участка.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int N, min_idN;
    int counter_numbers = 1, fin_counter = 1;

    srand(time(0));

    cout << "Введите количество элементов массива: ";
    cin >> N;

    while (N < 1)
    {
        cout << "Ошибка! Количество элементов должно быть больше нуля!" << endl;

        cout << "Введите количество элементов еще раз: ";
        cin >> N;
    }

    int* real_ptr = (int*)malloc(N * sizeof(int));

    if (real_ptr == NULL)
    {
        cout << "Ошибка выделения памяти!" << endl;
        return 1;
    }

    cout << "Введите начальный индекс массива: ";
    cin >> min_idN;

    int* arr = real_ptr - min_idN;

    int max_idN = N + min_idN;

    // Заполнение массива случайными числами от 1 до 10
    for (int i = min_idN; i < max_idN; i++)
    {
        arr[i] = rand() % 10 + 1;
    }

    // Поиск самого длинного участка одинаковых чисел
    for (int i = min_idN; i < max_idN - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            counter_numbers++;
        }
        else
        {
            counter_numbers = 1;
        }

        if (counter_numbers > fin_counter)
        {
            fin_counter = counter_numbers;
        }
    }

    cout << "Длина наибольшего участка: " << fin_counter << endl;

    cout << "Элементы массива:" << endl;

    for (int i = min_idN; i < max_idN; i++)
    {
        cout << "Индекс элемента: " << i
             << " Значение элемента: " << arr[i] << endl;
    }

    cout << endl;

    free(real_ptr);

    return 0;
}