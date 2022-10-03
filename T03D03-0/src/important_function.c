#include <math.h>
#include <stdio.h>

int main() {
    double x;
    char c;
    scanf("%lf%c", &x, &c);
    if (c != '\n') {
        printf("n/a");
        return 0;
    }
    double y = 7e-3 * powl(x, 4) + ((22.8 * powl(x, (1 / 3)) - 1e3) * x + 3) / (x * x / 2) -
               x * powl((10 + x), (2 / x)) - 1.01;
    printf("%.1lf\n", y);
    return 0;
}