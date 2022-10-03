#include <math.h>
#include <stdio.h>

int fibo(int a);

int main() {
  int a;
  int x;
  char c;
  x = scanf("%d%c", &a, &c);
  if (x != 2 || c == ' ' || c != '\n' || a < 0) {
    printf("n/a\n");
    return 0;
  } else {
    printf("%d\n", fibo(a));
  }
  return 0;
}

int fibo(int a) {
  if (a == 0) {
    return 0;
  }
  if (a == 1) {
    return 1;
  } else {
    return (fibo(a - 1) + fibo(a - 2));
  }
}
