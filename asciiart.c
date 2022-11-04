#include "lenaArray.h"
#include "functions.h"

//int array[][];
int array_rows = 512;           // specify amount of rows in the 2D array
int array_columns = 512;        // specify amount of columns int he 2D array

int grayscale_max = 255;        // specify the highest value that the grayscale can be in the 2D array
char grayscale_characters[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
int characters_len = sizeof(grayscale_characters)/sizeof(grayscale_characters[0]) - 1;
bool invert = false;           // set to 'true' to invert ASCII art (useful for white background terminals)

int row_begin = 100;            // specify which row (2D array) to begin printing (default: 0)
int row_end = 400;              // specify which row (2D array) to stop printing (default: array_rows value)
int column_begin = 100;         // specify which column (2D array) to begin printing (default: 0)
int column_end = 400;           // specify which column (2D array) to stop printing (default: array_columns value)

int pixel_height = 2;           // specify the height of each pixel that gets printed (default: 2)
int pixel_width = 1;            // specify the width of each pixel that gets printed (default: 1)

int main() {
    // prints out the ASCII art in specified size of pixels
    int grayscale_value = 0;
    for(int r = row_begin; r < row_end; r+= pixel_height) {
        for(int c = column_begin; c < column_end; c+= pixel_width) {
            grayscale_value = average_grayscale(r, r + pixel_height, c, c + pixel_width, array_rows, array_columns, lena);  // specify 2D array with grayscale values here
            printf("%c", grayscale_characters[grayscale_to_index(grayscale_value, grayscale_max, characters_len, invert)]);
        }
        printf("\n");
    }
    // average grayscale value of the ASCII art
    int avg = average_grayscale(row_begin, row_end, column_begin, column_end, array_rows, array_columns, lena);
    char avg_char = grayscale_characters[grayscale_to_index(avg, grayscale_max, characters_len, invert)];
    printf("\nAverage grayscale value of printed image: %d (%c)", avg, avg_char);
}