// По известному радиусу определить:
// длину окружности, площадь круга,
// площадь поверхности сферы и объем шара.

#include <iostream>
#include <cstdio>
#include <math.h>


int main() {
    int r = 2;
    float s, p, sp, v;

    p = 2 * M_PI * r;
    s = M_PI * pow(r, 2);
    sp = 4 * s;
    v = (sp * r ) / 3;   

    printf("Радиус: %d\n", r);
    printf("Длина окружности: %.2f\n", p);
    printf("Площадь круга: %.2f\n", s);
    printf("Площадь поверхности сферы: %.2f\n", sp);
    printf("Объем шара: %.2f\n", v);

    return 0;
}