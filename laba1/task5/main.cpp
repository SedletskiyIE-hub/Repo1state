#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int h = 21, m = 10;

    h = h % 12;

    float hourAngle = h * 30.0 + m * 0.5;

    float minuteAngle = m * 6.0;

    float angle = fabs(hourAngle - minuteAngle);

    angle = (angle > 180) ? 360 - angle : angle;

    printf("Угол: %.2f\n", angle);

    return 0;
}