#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a);
void output(int *a);

int main() {
  int data[NMAX];
  if (input(data)) {
    sort(data);
    output(data);
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
    for (int j = 0; j < NMAX; j++) {
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
