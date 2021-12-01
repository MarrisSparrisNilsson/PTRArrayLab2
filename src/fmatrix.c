#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "fmatrix.h"

fMatrix* createMatrix(float f) {
    fMatrix *mPtr = (fMatrix*) malloc(sizeof(fMatrix));

    float *mp = (float *)mPtr;
    if (mPtr == NULL) return NULL;

    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t col = 0; col < COLS; ++col) {
                *(mp+row*COLS+col) = f;
                // printf("%17s%d%s%d %p %s%d%s %-3d\n","mp+", row, "*COLS+", col, mp+row*COLS+col, "*(mp+", row,"*COLS+", col,":", *(mp+row*COLS+col));
        }
    }    
    return mPtr;
}
// void destroyMatrix(fMatrix* m) {
    
//     if (m != NULL) {
//         for (size_t row = 0; row < ROWS; ++row) {
//                 free(m[row]);
//         }
//         free(m);
//         m = NULL;
//     }
// }
void destroyMatrix(fMatrix* m) {
        if(m != NULL) {
        free(m);
    
    }
    m = NULL;
}

void printMatrix(fMatrix* m) {
    float *mp = (float *)m;

    for(size_t row=0; row<ROWS; ++row) {
        printf("\n");
        for(size_t col=0; col<COLS; ++col) {
            // printf("%.2f ", *m[row][col]);
            printf("%.2f ", *(mp+row*COLS+col));

        }
    }
    printf("\n");
}

bool getMatrix(fMatrix* m) {
    char *endPtr;
    char input[SIZE];
    float *mp = (float *)m;

    printf("Please enter a comma-separated list of 9 floats: ");
    fflush(stdin);
    fgets(input, SIZE, stdin);

    if (
        input[0] == ',' 
        || *(strchr(input, '\n')-1) == ',' 
        || input[0] == ' '
    ) return false;

    for (size_t i = 0, row = 0, col = 0; input[i] != '\n'; i++) {

        float init = strtod(input + i, &endPtr);

        if (input[i] == ',' && input[i+1]== ',') return false;

        if (init != 0) {
            while (row < ROWS) {
                while (col < COLS) {
                    *(mp+row*COLS+col) = init;
                    // *m[row][col] = init;
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
    float *mp1 = (float *)m1;
    float *mp2 = (float *)m2;
    // fMatrix* sum;
    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t col = 0; col < COLS; ++col) {
            *(mp1+row*COLS+col) = (*(mp1+row*COLS+col) + *(mp2+row*COLS+col));
            // *m1[row][col] = *m1[row][col] + *m2[row][col];

            // m1[row][col] = m1[row][col] + m2[row][col];
            // printf("\n%.2f ", *(mp1+2*COLS+2));
            // printf("\n%.2f ", *(mp2+2*COLS+2));
        }
    }
    // m1[row][col] = sum;
    // for(size_t row=0; row<ROWS; ++row) {
    //     printf("\n");
    //     for(size_t col=0; col<COLS; ++col) {
    //         printf("%7.2f", m1[row][col]);
    //     }
    // }
    // printf("\n");


//     // memcpy(buffer, *m1, SIZE);
//     // return m1;
}
// void matMul(float m1[3][3], float m2[3][3]) {
//     float sum = 0;
//     float i, row, col;
// // void matMul(fMatrix* m1, fMatrix* m2) {
//     for (size_t i = 0; i < ROWS; i++)
//     {
//         for (size_t col = 0; col < COLS; ++col) {
//             for (size_t row = 0; row < ROWS; ++row) {
//                 // m1[row][col] = m1[row][col] + m2[row][col];
//                 sum = sum + m1[i][row]*m2[row][col];

//             }
//         }
//     }
//     m1[i][col] = sum;
    
//      for(size_t row=0; row<ROWS; ++row) {
//         printf("\n");
//         for(size_t col=0; col<COLS; ++col) {
//             printf("%7.2f", m1[row][col]);
//         }
//     }
//     printf("\n");

// }