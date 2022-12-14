#include <stdio.h>
#include <stdlib.h>
#include "decision.h"
#include "../data_libs/data_io.h"

int main() {
    double *data;
    int n;

    scanf("%d", &n);
    data = calloc(n, sizeof(double));
    input(data, n);

    if (make_decision(data, n)) {
        printf("YES");
    } else {
        printf("NO");
    }
    free(data);
    return 0;
}
