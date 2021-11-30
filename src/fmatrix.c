#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "fmatrix.h"

fMatrix* createMatrix(float f) {
    fMatrix *mPtr = (fMatrix*) malloc(sizeof(fMatrix));

    if (mPtr == NULL) return NULL;

    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            *mPtr[r][c] = f;
        }
    }    
    return mPtr;
}

void destroyMatrix(fMatrix* m) {
    if (m != NULL) {
        free(m);
        m = NULL;
    }
}

void printMatrix(fMatrix* m) {
    for(size_t r=0; r<ROWS; ++r) {
        printf("\n");
        for(size_t c=0; c<COLS; ++c) {
            printf("%.2f ", *m[r][c]);
        }
    }
    printf("\n");
}

bool getMatrix(fMatrix* m) {
    char input[19];
    char *endPtr;
    
    printf("Please enter a comma-separated list of 9 floats: ");
    fflush(stdin);
    fgets(input, 20, stdin);

    if (
        input[0] == ',' 
        || *(strrchr(input, '\n')-1) == ',' 
        || input[0] == ' '
    ) return false;

    for (size_t i = 0, row = 0, col = 0; input[i] != '\n'; i++) {

        float init = strtod(input + i, &endPtr);

        if (input[i] == ',' && input[i+1]== ',') return false;

        if (init != 0) {
            while (row < ROWS) {
                while (col < COLS) {
                    *m[row][col] = init;
                    col++;
                    if (col == 3) {
                        row++;
                        col = 0;
                    }
                    break;
                }
                break;
            }
        }
    }
    printMatrix(m);
    return true;
}

// float m1[3][3] = {
//     {1.00, 3.00, 5.40},
//     {1.70, 9.10, 8.20},
//     {6.30, 4.70, 52.00}
// };

// float m2[3][3] = {
//     {1.00, 3.90, 5.00},
//     {8.10, 2.50, 9.80},
//     {6.00, 3.70, 1.10}
// };

void matAdd(fMatrix* m1, fMatrix* m2) {
// void matAdd(float m1[][3], float m2[][3]) {

    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            // m1[r][c] = m1[r][c] + m2[r][c];
            *m1[r][c] = *m1[r][c] + *m2[r][c];
        }
    }

    // for(size_t r=0; r<ROWS; ++r) {
    //     printf("\n");
    //     for(size_t c=0; c<COLS; ++c) {
    //         printf("%7.2f", m1[r][c]);
    //     }
    // }
    // printf("\n");


    // memcpy(buffer, *m1, 100);
    // return m1;
}
