#include <stdio.h>
#include <stdlib.h>
#define MATRIX_H 100
#define MATRIX_W 100

int main() {

  int h, w;
  h = scanf("%d ", &h);
  w = scanf("%d\n", &w);
  int array[MATRIX_H][MATRIX_W];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%d ", &array[i][j]);
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  return 0;
}

void arrayD2(int **array, h, w) {
    int h, w;
    

    int **pointer_array = malloc(h * sizeof(int)); //выделилась память
    for (int i=0; i<h; i++) {
        pointer_array[i] = malloc(w * sizeof(int));
    }

    for (int i=0;i<h;i++) {
        for (int j=0;j<w; j++) {

        }
    }

}
