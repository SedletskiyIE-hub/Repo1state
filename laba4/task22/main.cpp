//Дано произвольное целое положительное число K ( K  109 ).
//Вывести новое число, полученное из K вычеркиванием всех четных цифр
//2.
//(например, 234653=>353). Процедуры и функции работы со строками не
//использовать.

#include <stdio.h>

int main() {
    long long K;
    int temp, result = 0;
    int pos = 1;

    printf("Введите целое положительное число K (K <= 1e9): ");
    scanf("%lld", &K);

    while (K <= 0 || K > 1e9) {
        printf("Неверно введено число, повторите попытку: ");
        scanf("%lld", &K);
    }

    temp = K;

    while (temp > 0) {
        int digit = temp % 10;

        if (digit % 2 != 0) {
            result += digit * pos;
            pos *= 10;
        }

        temp /= 10;
    }

    printf("Получившееся число: %d\n", result);

    temp = K;
    pos = 1;
    result = 0;

    for(; temp > 0;){
        int digit = temp % 10;

        if (digit % 2 != 0) {
            result += digit * pos;
            pos *= 10;
        }

        temp /= 10;
    }

    printf("Получившееся число: %d\n", result);

    temp = K;
    pos = 1;
    result = 0;

    do{
        int digit = temp % 10;

        if (digit % 2 != 0) {
            result += digit * pos;
            pos *= 10;
        }

        temp /= 10;

    }

    while(temp > 0);

    printf("Получившееся число: %d\n", result);

    return 0;
}