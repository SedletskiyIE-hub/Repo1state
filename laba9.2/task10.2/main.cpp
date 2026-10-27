//Дан двумерный массив из N строк и M столбцов. Определить, какая строка массива
//имеет максимальную сумму элементов (считать, что строк с одинаковой суммой нет).

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){

    int rows, cols, minRow, minCol;
    long long max_sum = 0, sum;
    int number_line;

    srand(time(0));

    cout << "Введите количество строк массива: ";
    cin >> rows;

    while (rows < 1)
    {
        cout << "Ошибка! Количество строк должно быть больше нуля!" << endl;

        cout << "Введите количество строк еще раз: ";
        cin >> rows;
    }

    cout << "Введите количество столбцов массива: ";
    cin >> cols;

    while (cols < 1)
    {
        cout << "Ошибка! Количество столбцов должно быть больше нуля!" << endl;

        cout << "Введите количество столбцов еще раз: ";
        cin >> cols;
    }

    int** real = (int**)malloc(rows*sizeof(int*));

    for (int i = 0; i < rows; i++){

        real[i] = (int*)malloc(cols*sizeof(int));

    }

    cout << "Введите начало индексации строк: ";
    cin >> minRow;

    cout << "Введите начало индексации столбцов: ";
    cin >> minCol;

    int** temp = (int**)malloc(rows*sizeof(int*));

    for (int i = 0; i < rows; i++){

        temp[i] = real[i] - minCol;
    }

    int** arr = temp - minRow;

    for (int i = minRow; i < minRow + rows; i++){
        for (int j = minCol; j < minCol + cols; j++){
            arr[i][j] = rand() % 10 - 5;
        }
    }

    for (int i = minRow; i < minRow + rows; i++){

        sum = 0;
        
        for (int j = minCol; j < minCol + cols; j++){
            sum += arr[i][j];
        }

        if (sum > max_sum){
            max_sum = sum;
            number_line = i;
        }
    }

    cout << "Максимальная сумма: " << max_sum << endl;
    cout << "Номер строки: " << number_line + 1 << endl;

    for (int i = minRow; i < minRow + rows; i++){
        for (int j = minCol; j < minCol + cols; j++){

            cout << arr[i][j] << "  ";

        }

        cout << endl;

    }

    for ( int i = 0; i < rows; i++){

        free(real[i]);

    }

    free(real);

    free(temp);

    return 0;

}

