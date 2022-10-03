#include <stdio.h>

int sum(int a, int b);
int min(int a, int b);
int mul(int a, int b);
int div(int a, int b);

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
    if (b != 0) {
        printf("%d %d %d %d\n", sum(a, b), min(a, b), mul(a, b), div(a, b));
    } else {
        printf("%d %d %d n/a\n", sum(a, b), min(a, b), mul(a, b));
    }
    return 0;
}

int sum(int a, int b) { return (a + b); }

int min(int a, int b) { return (a - b); }

int mul(int a, int b) { return (a * b); }

int div(int a, int b) { return (a / b); }