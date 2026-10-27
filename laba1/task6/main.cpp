#include <iostream>

using namespace std;

int main()
{
    int n = 6287;

    int money = n;
    int maxMoney = n;
    int bestPass = 0;
    int pass = 0;
    int repass = n;

    do
    {
        money -= 29;

        int rubles = money / 100;
        int kopecks = money % 100;

        money = kopecks * 100 + rubles;

        pass++;

        if (money > maxMoney)
        {
            maxMoney = money;
            bestPass = pass;
        }
    }

    while(money >= 29 && repass != money);

    printf("Максимальное кол-во: %d\nЛучший ход: %d\n", maxMoney, bestPass);

    return 0;
}