#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float a = 0.5, b = 0.5, y;

    y = sqrt(
        (pow(a, pow(sin(b), 2) + cos(pow(b, 3))) + pow(b, 2.0 / 3.0))
        /
        pow(
            fabs(a * tan(b) / (1 - exp(sqrt(a)))),
            1.0 / 4.0
        )
    );

    printf("y = %.3f\n", y);

    return 0;
}