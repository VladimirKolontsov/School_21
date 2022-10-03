#include <stdio.h>

int main() {
    double a;
    double b;
    int x;
    char c, d;
    x = scanf("%lf%c%lf%c", &a, &c, &b, &d);
    if (x != 4 || c != ' ' || d != '\n') {
        printf("n/a");
        return 0;
    }
    double diam = (a * a) + (b * b);
    if (diam < 25) {
        printf("GOTCHA");
    } else {
        printf("MISS");
    }
    return 0;
}