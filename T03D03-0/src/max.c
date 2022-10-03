#include <stdio.h>

int max(int a, int b);

int main() {
    int a;
    int b;
    int x;
    char c, d;
    x = scanf("%d%c%d%c", &a, &c, &b, &d);
    if (x != 4 || c != ' ' || d != '\n') {
        printf("n/a");
        return 0;
    }
    printf("%d", max(a, b));
    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}