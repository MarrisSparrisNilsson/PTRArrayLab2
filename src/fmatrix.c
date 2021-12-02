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

    fflush(stdin);
    fgets(input, SIZE, stdin);

    if (
        input[0] == ',' 
        || *(strchr(input, '\n')-1) == ',' 
        || input[0] == ' '
    ) return false;
    for (size_t j = 0, i = 0, row = 0, col = 0; input[i] != '\n'; i++, j++) {
        
        int count = 0;
        if (input[i] == ',' && input[i+1]== ',') {
            return false;
        }
        for (; input [j] != ',' && input [j] != '\n'; j++) {
            if (isdigit(input[j]) && isdigit(input[j+1])) count++;
        }
        float init = strtod(input + i, &endPtr);
        i = i + count; 
        j = i;
        if (init != 0) {
            while (row < ROWS) {
                while (col < COLS) {
                    *(mp+row*COLS+col) = init;
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

void matAdd(fMatrix* m1, fMatrix* m2) {
    float *mp1 = (float *)m1;
    float *mp2 = (float *)m2;
    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t col = 0; col < COLS; ++col) {
            *(mp1+row*COLS+col) = (*(mp1+row*COLS+col) + *(mp2+row*COLS+col));
        }
    }
}

// void matMul(float m1[3][3], float m2[3][3]) {
void matMul(fMatrix* m1, fMatrix* m2) {
    float sum = 0;
    fMatrix* m3 = createMatrix(0.00);
    float *mp1 = (float *)m1;
    float *mp2 = (float *)m2;
    float *mp3 = (float *)m3;

    for (size_t c = 0; c < ROWS; ++c) {
        for (size_t d = 0; d < COLS; ++d) {
            for (size_t k = 0; k < ROWS; ++k) {
                sum = sum + *(mp1+c*COLS+k) * *(mp2+k*COLS+d);
                // m1[row][col] = m1[row][col] + m2[row][col];
                // *(mp3+row*COLS+col) = *(mp3+i*COLS+row) + *(mp1+i*COLS+row) * *(mp2+row*COLS+col);
                // *(mp1+row*COLS+col) = *(mp1+i*COLS+row) * *(mp2+row*COLS+col);
                // sum = sum + m1[i][row]*m2[row][col];
            }
            // *m3[c][d] = sum;
            *(mp3+c*COLS+d) = sum;
            sum = 0;
        }
    }
    // memcpy(m1, m3, SIZE);
    // *m1[c][d] = *m3[c][d];
    
    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t col = 0; col < COLS; ++col) {
                *m1[row][col] = *(mp3+row*COLS+col);
                // *m3[row][col];
                // **m1 = *(mp3+row*COLS+col);
                // printf("%17s%d%s%d %p %s%d%s %-3d\n","mp+", row, "*COLS+", col, mp+row*COLS+col, "*(mp+", row,"*COLS+", col,":", *(mp+row*COLS+col));
        }
    }
    destroyMatrix(m3);
}
