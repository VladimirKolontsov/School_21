#include <stdio.h>

int main() {
    int a, x, y, z;
    scanf("%d", &a);
    x = a % 10;
    y = (a / 10) % 10;
    z = a / 100;
    if(a < 0) {
        y = y * -1;
        z = z * -1;
        x = x * -1;
        printf("-%d%d%d", x, y, z);
    }
    else {
        printf("%d%d%d", x, y, z);
    }
    return 0;
}