/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length, int sum);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
  int length;
  int array[NMAX];
  if (!input(array, &length)) {
    // if ((length > NMAX) && (length == 0)) {
    printf("n/a");
  } else {
    int number = sum_numbers(array, length);
    int numbers[NMAX];
    int lengthNew = find_numbers(array, length, number, numbers);
    output(numbers, lengthNew, number);
  }
}

int input(int *buffer, int *length) {
  int rtn = 1;
  if (scanf("%d", length) && (*length > 0) && (*length <= 10)) {
    for (int i = 0; i < *length; i++) {
      if (buffer + i <= length) {
        scanf("%d", buffer + i);
      } else {
        rtn = 0;
      }
    }
  } else {
    rtn = 0;
  }
  return rtn;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
  int number = 0;
  // int count = 0;
  for (int i = 0; i < length; i++) {
    if (*(buffer + i) % 2 == 0) {
      number = number + *(buffer + i);
    }
    //   count++;
    // } else if (count == 0) {
    //   return -1;
    // }
  }
  return number;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
  int j = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] != 0 && number % buffer[i] == 0) {
      numbers[j] = buffer[i];
      j++;
    }
  }
  return j;
}

void output(int *buffer, int length, int sum) {
  printf("%d\n", sum);
  for (int i = 0; i < length; i++) {
    if (i < (length - 1)) {
      printf("%d ", buffer[i]);
    } else {
      printf("%d", buffer[i]);
    }
  }
}
