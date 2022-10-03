#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);

int main() {
  int n, data[NMAX];
  if (!input(data, &n)) {
    squaring(data, &n);
    output(data, &n);
  } else {
    printf("n/a");
  }
  return 0;
}

int input(int *a, int *n) {
  if (scanf("%d", n) && (*n > 0 && *n <= 10)) {
    for (int p = 0; p < *n; p++) {
      if (!scanf("%d", a + p)) {
        return 1;
      }
    }
    return 0;
  } else {
    return 1;
  }
}

void output(int *a, int *n) {
  for (int i = 0; i < *n; i++) {
    printf("%d ", *(a + i));
  }
}

void squaring(int *a, int *n) {
  for (int j = 0; j < *n; j++) {
    *(a + j) *= *(a + j);
  }
}
