#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;

    printf("Введите N: ");
    scanf("%d", &n);
    
    int minq = n + 1;
    int mP = 0;
    int mQ = 0;

    if (n < 1 || n > 1e6){
        
        printf("Неправильный ввод\n");
        
        return 0;
    }

    for (int Q = 1; Q <= 1000; Q++)
    {
        for (int P = 1; P <= Q; P++)
        {
            int s = abs(n - P * P - Q * Q);

            if (s < minq)
            {
                minq = s;
                mP = P;
                mQ = Q;
            }
        }
    }

    printf("P = %d\n", mP);
    printf("Q = %d\n", mQ);

    return 0;
}