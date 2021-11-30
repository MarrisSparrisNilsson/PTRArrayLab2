#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fmatrix.h"

fMatrix* createMatrix(float f) {
    fMatrix* mPtr = (fMatrix*) malloc(sizeof(fMatrix));

    if (mPtr != NULL) {
        return NULL;
    }

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
    for(size_t row=0; row<ROWS; ++row) {
        printf("\n");
        for(size_t col=0; col<COLS; ++col) {
            printf("%.2f ", m);
        }
    }
    printf("\n");
}
