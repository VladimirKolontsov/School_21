#include <stdio.h>
#include <math.h>

int main() {
    double P = 21500;
    double r, res;
    scanf("%lf", &r);
    res = P * (4.0 / 3.0) * M_PI  * r * r * r;
    printf("%.0lf", round(res));
    return 0;
}