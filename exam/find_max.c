#include <stdio.h>

int main() {
    int num, max  = 0;
    char c;
    while (scanf("%d%c", &num, &c) && num != -1 && c == ' ') {
        if (num > max) {
            max = num;
        } else {
            continue;
        }
    }
    printf("%d", max);
    return 0;
}