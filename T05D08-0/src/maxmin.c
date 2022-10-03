#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

/* Find a max & min probabilities */
int main() {
  int x, y, z;
  int count;
  char c, d;
  count = scanf("%d%c%d%c%d%c", &x, &c, &y, &c, &z, &d);

  int max, min;
  if (count != 6 || c != ' ' || d != '\n') {
    printf("n/a");
  } else {
    maxmin(x, y, z, &max, &min);
    printf("%d %d", max, min);
  }
  return 0;
}

/* This function should be kept !!! (Your AI) */
/* But errors & bugs should be fixed         */
void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
  *max = *min = prob1;

  if (prob2 > *max)
    *max = prob2;
  if (prob2 < *min)
    *min = prob2;

  if (prob3 > *max)
    *max = prob3;
  if (prob3 < *min)
    *min = prob3;
}
