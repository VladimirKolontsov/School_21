#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

int** alloc_memory(int** matrix, int rows, int cols);
void clear_memory(int** matrix, int rows);
void read_file(int** matrix, int size_y, int size_x);
int check_cell(int** field, int pos_x, int pos_y);
void draw(int** field, int rows, int colls);
void play(int** current_field, int** next_field, int size_y, int size_x, int rows, int cols);
void msleep(int milisec);
void input (int* milisec);
int getecho();

int main() {
    const int size_y = 25, size_x = 80, ROWS = size_y - 2, COLS = size_x - 2;
    int** current_field = NULL;
    int** next_field = NULL;
    current_field = alloc_memory(current_field, ROWS, COLS);
    next_field = alloc_memory(next_field, ROWS, COLS);

    read_file(current_field, ROWS, COLS);
    // initscr();
    // noecho();
    play(current_field, next_field, size_y, size_x, ROWS, COLS);
    // draw(current_field, size_y, size_x);
    
    // input(&milisec);

    clear_memory(current_field, ROWS);
    clear_memory(next_field, ROWS);
    return 0;
}

int** alloc_memory(int** matrix, int rows, int cols) {
    matrix = calloc(rows, sizeof(int*));
    for (int r = 0; r < rows; r++) {
        matrix[r] = calloc(cols, sizeof(int));
    }
    return matrix;
}

void clear_memory(int** matrix, int rows) {
    for (int r = 0; r < rows; r++) {
        free(matrix[r]);
    }
    free(matrix);
}

void read_file(int** matrix, int rows, int cols) {
    FILE* file = fopen("file_5.txt", "r");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
}

void play(int** current_field, int** next_field, int size_y, int size_x, int rows, int cols) {
    int isPlaying = 1;
    initscr();
    int milisec = 90;
    while (isPlaying) {
        draw(current_field, size_y, size_x);
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // printw("TEST!!\n");
                next_field[row][col] = check_cell(current_field, row, col);
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                current_field[r][c] = next_field[r][c];
            }
        }
        input(&milisec);
        refresh();`
        // printw("\033c");
        msleep(milisec);
    }
    endwin();
}

int check_cell(int** field, int pos_y, int pos_x) {
    int is_alive = 0, count = 0;
    int row, col;
    // printw("WTF!!!!!! ___ %d ___ %d\n", pos_y, pos_x);
    for (int r = pos_y - 1; r < pos_y + 2; r++) {
        row = r;
        for (int c = pos_x - 1; c < pos_x + 2; c++) {
            col = c;
            if (row == -1) { row = 22; }
            if (row == 23) { row = 0; }
            if (col == -1) { col = 77; }
            if (col == 78) { col = 0; }
            // if (row == -1) { continue; }
            // if (row == 23) { continue; }
            // if (col == -1) { continue; }
            // if (col == 78) { continue; }
            // printw("WTF!!!!!! %d %d\n", row, col);
            if (field[row][col]) {
                count++;
            }
        }
    }

    if (field[pos_y][pos_x]) {
        count--;
        if (count == 2 || count == 3) {
            is_alive = 1;
        } else {
            is_alive = 0;
        }
    } else {
        if (count == 3) {
            is_alive = 1;
        } else {
            is_alive = 0;
        }
    }

    return is_alive;
}

void draw(int** field, int size_y, int size_x) {
    for (int i = 0; i < size_y; i++){
        for (int j = 0; j < size_x; j++) {
            if (i >= 1 && i <= size_y - 2 && j >= 1 && j <= size_x - 2) {
                if (field[i - 1][j - 1] == 1) {
                    printw("#");
                } else {
                    printw(" ");
                }
            } else if ((i == 0 && j == 0) || (i == size_y - 1 && j == size_x - 1) || 
            (i == size_y - 1 && j == 0) || (i == 0 && j == size_x - 1)) {
                printw("+");
            } else if (i == 0 || i == size_y - 1) {
                printw("-");
            } else if (j == 0 || j == size_x - 1) {
                printw("|");
            } 
        }
        printw("\n");
    }
}

void msleep(int milisec) {
    milisec *= 1000;
    usleep(milisec);
}

void input (int* milisec) {
    int key_press = getecho();
    if (key_press == 97) {
        *milisec *= 2;
    } else if (key_press == 122) {
        *milisec /= 2;
    } else if (key_press == 'q') {
        exit(0);
    }
}

int getecho() {
    char c;
    system("stty raw");
    c = getch();
    system("stty -raw");
    return c;
}

/*--------------------------*/
    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS; j++) {
    //         printw("%d", current_field[i][j]);
    //     }
    //     printw("\n");
    // }
