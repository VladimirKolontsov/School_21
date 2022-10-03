#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *steps);
void shift(int *buffer, int length, int steps);
void output(int *buffer, int length);

int main() {
  int length;
  int array[NMAX];
  //int arrayShift[NMAX];
  int steps;
  if (!input(array, &length, &steps)) {
    printf("n/a");
  } else {
    shift(array, length, steps);
    output(array, length);
  }
}

int input(int *buffer, int *length, int *steps) {
  int rtn = 1;
  if (scanf("%d", length) && (*length > 0) && (*length <= 10)) {
    for (int i = 0; i < *length; i++) {
      if (buffer + i <= length) {
        scanf("%d", buffer + i);
      } else {
        rtn = 0;
      }
    }
    scanf("%d", steps);
  } else {
    rtn = 0;
  }
  return rtn;
}

void shift(int *buffer, int length, int steps) {
    int tmp;
    if (steps > 0) {
        while (steps > 0) {
            steps--;
            tmp = *buffer;
            for (int i = 1; i < length; i++) {
                *(buffer + i -1) = *(buffer + i);
            }
            *(buffer + length - 1) = tmp;
        }
    } else {
        while (steps < 0) {
            steps++;
            tmp = *(buffer + length - 1);
            for (int i = length - 1; i > 0; i--) {
                *(buffer + i) = *(buffer + i - 1);
            }
            *buffer = tmp;
        }
    }
//   int tmp;
//   for (int i = 0; i < length; i++) {
//     tmp = buffer[i];
   
//     buffer[i] = buffer[i + steps];
    
//     buffer[length] = tmp;
    
//   }
}

void output(int *buffer, int length) {
  for (int i = 0; i < length; i++) {
    if (i < (length - 1)) {
      printf("%d ", buffer[i]);
    } else {
      printf("%d", buffer[i]);
    }
  }
}
