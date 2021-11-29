#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fmatrix.h"

// fMatrix *m = createMatrix(0.0f);
// float* createMatrix(float f) {
//     float (*mPtr)[ROWS][COLS] = malloc(sizeof(float) * 3 * 3);

//     float *fPtr;

//     fPtr = *mPtr;

//     for (int r = 0; r < ROWS; r++) {
//         for (int c = 0; c < COLS; c++) {
//             fPtr[r][c] = f;
//         }        
//     }
    
//     return fPtr;
// }

void destroyMatrix(m) {
    if (m != NULL)
    {
        free(m);
        m = NULL;
    }
}
// printMatrix(m) {
//     for (size_t i = 0; i < COLS; i++)
//     {
//         for (size_t j = 0; j < ROWS; j++)
//         {
//             /* code */
//         }
        
//     }
// }

void printMatrix(m) {
    for(size_t row=0; row<ROWS; ++row) {
        printf("\n");
        for(size_t col=0; col<COLS; ++col) {
            printf("%f ", m);
        }
    }
    printf("\n");
}
