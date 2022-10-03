#include <stdio.h>
#include <math.h>
#define NMAX 30
/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

int input(int *a, int *n);
int even(int a);
double mean(int *a, int n);
double variance(int *a, int n);
double sigm(int *a, int n);
int calc(int *a, int n);


int main() {
    int n, data[NMAX];
  if (!input(data, &n)) {
    printf("%d", calc(data, n));
  } else {
    printf("n/a");
  }
  return 0;
}

int input(int *a, int *n) {
  if (scanf("%d", n) && (*n > 0 && *n <= 30)) {
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

int even(int a) {
    if (a % 2 == 0) {
        return 1;
    }
    return 0;
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

double sigm(int *a, int n) {
  double tmp = 0;
  for (int *i = a; i - a < n; i++) {
    tmp += *i;
  }
  return (double) (tmp / (n)) + 3 * sqrt(variance(a, n));
}

int calc(int *a, int n) {
    int res = 0;
    for (int *p=a; p - a < n; p++) {
        if (even(*p) && *p >= mean(a, n) && *p <= sigm(a, n) && *p != 0) {
            return *p;
        }
    }
    return res;
}
