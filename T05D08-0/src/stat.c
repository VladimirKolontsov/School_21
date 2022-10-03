#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
  int n, data[NMAX];
  if (!input(data, &n)) {
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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

void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", *(a + i));
  }
}

int max(int *a, int n) {
  int tmp = *a;
  for (int *i = a; i - a < n; i++) {
    tmp = tmp > *i ? tmp : *i;
  }
  return tmp;
}

int min(int *a, int n) {
  int tmp = *a;
  // for (int i = 0; i < n; i++) {
  //   if (*(a + i) < *a) {
  //     tmp = *(a + i);
  //   } else {
  //     tmp = *a;
  //   }
  // }
  for (int *i = a; i - a < n; i++) {
    tmp = tmp < *i ? tmp : *i;
  }
  return tmp;
}

double mean(int *a, int n) {
  double tmp = 0;
  for (int *i = a; i - a < n; i++) {
    tmp += *i;
  }
  return (double)tmp / (n);
}

double variance(int *a, int n) {
  double tmp = 0;
  if (n == 1)
    return 0;
  for (int *i = a; i - a < n; i++) {
    tmp += (*i - mean(a, n)) * (*i - mean(a, n));
  }
  return tmp / (n);
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
  printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
