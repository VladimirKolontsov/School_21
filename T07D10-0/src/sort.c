#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

int input(int *a);
void sort(int *);
void output(int *a);
// void free(int *a);

int main() {
  int *data[NMAX];
  int n = scanf("%d", &n);
  *data = (int *)calloc(n, sizeof(int));
  if (NULL == data) {
    exit(1);
  }
  if (input(*data)) {
    sort(*data);
    output(*data);
    free(*data);
  } else {
    printf("n/a");
  }
  return 0;
}

int input(int *a) {
  for (int p = 0; p < NMAX; p++) {
    if (!scanf("%d", a + p)) {
      return 0;
    }
  }
  return 1;
}

void sort(int *a) {
  int temp;
  for (int i = 0; i < NMAX; i++) {
    for (int j = 0; j < NMAX - i - 1; j++) {
      if (*(a + j) > *(a + j + 1)) {
        temp = *(a + j);
        *(a + j) = *(a + j + 1);
        *(a + j + 1) = temp;
      }
    }
  }
}

void output(int *a) {
  for (int i = 0; i < NMAX; i++) {
    printf("%d ", *(a + i));
  }
}
