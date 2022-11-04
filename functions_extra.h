#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int avg(int n1, int n2) {
    return round((float)n1/n2);
}

int average_grayscale(int row_begin, int row_end, int column_begin, int column_end, int array_rows, int array_columns, int array[array_rows][array_columns]) {
    int sum = 0;
    int counter = 0;
    for(int r = row_begin; r < row_end; r++) {
        for(int c = column_begin; c < column_end; c++) {
            sum += array[r][c];
            counter++;
        }
    }
    return avg(sum, counter);
}

int grayscale_to_index(int grayscale, int grayscale_max, int characters_len, bool reverse) {
    float g = (float)grayscale_max / characters_len;
    float value = 0;
    int index = 0;
    if(!reverse) index = characters_len;
    for(int i = 0; i < characters_len; i++) {
        value += g;
        if(!reverse) index--;
        if (grayscale <= round(value)) {
            return index;
        }
        if(reverse) index++;
    }
}

void cyan() {
    printf("\033[0;36m");
}
void green() {
    printf("\033[0;32m");
}
void red() {
    printf("\033[0;31m");
}
void reset() {
    printf("\033[0m");
}

void random_color() {
    srand(time(NULL));
    int color = rand() % 3;
    switch (color) {
        case 0:
            cyan();
            break;
        case 1:
            green();
            break;
        case 2:
            red();
            break;
    }
}

void txt_to_array(char *filename, int array_rows, int array_columns, int grayscale_array[array_rows][array_columns]) {
    int row;
    int column;
    int grayscale;
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file: %s", filename);
    }
    else {
        while((fscanf(fptr, "%d %d %d", &row, &column, &grayscale)) == 3) {
            grayscale_array[row][column] = grayscale;
        }
    }
    fclose(fptr);
}