#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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