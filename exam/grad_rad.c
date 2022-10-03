#include <stdio.h>
#include <math.h>

int main() {
    double rad, gr;
    char c;
    if (scanf("%lf%c", &rad, &c) && c == '\n') {
        gr = round (rad * 180.0 / M_PI);
        printf("%.0lf", gr);
    } else {
        printf("n/a");
    }
    return 0;
}