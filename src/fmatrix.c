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

// // float m1[3][3] = {
// //     {1.00, 3.00, 5.40},
// //     {1.70, 9.10, 8.20},
// //     {6.30, 4.70, 52.00}
// // };

// // float m2[3][3] = {
// //     {1.00, 3.90, 5.00},
// //     {8.10, 2.50, 9.80},
// //     {6.00, 3.70, 1.10}
// // };

// int m = 3, n = 3, p = 3, q = 3, c, d, k, sum = 0;
//  for (size_t c = 0; c < m; c++) {
//     for (size_t d = 0; d < q; d++) {
//         for (size_t k = 0; k < p; k++) {
//             // m1[row][col] = m1[row][col] + m2[row][col];
//             sum = sum + m1[c][k]*m2[k][d];
//             // sum = sum + m1[i][row]*m2[row][col];

//         }    
//     }    
// }  

//     for(size_t row=0; row<ROWS; ++row) {
//         printf("\n");
//         for(size_t col=0; col<COLS; ++col) {
//             printf("%7.2f", m1[c][d]);
//             // printf("%7.2f", sum[c][d]);

//         }
//     }
//     printf("\n");

//     m1[c][d] = sum;
//     sum = 0;
// }
// void matMul(float m1[3][3], float m2[3][3]) {
void matMul(fMatrix* m1, fMatrix* m2) {
    float f = 0;
    float c, d, k, p, q, m;
    
    float *mp1 = (float *)m1;
    float *mp2 = (float *)m2;
    // float *mp3 = (float *)m1;

    for (size_t c = 0; c < m; c++) {
        for (size_t d = 0; d < q; ++d) {
            for (size_t k = 0; k < p; ++k) {
                // m1[row][col] = m1[row][col] + m2[row][col];
                // *(mp3+row*COLS+col) = *(mp3+i*COLS+row) + *(mp1+i*COLS+row) * *(mp2+row*COLS+col);
                // *(mp1+row*COLS+col) = *(mp1+i*COLS+row) * *(mp2+row*COLS+col);
                f = f + *(mp1+c*COLS+k) * *(mp2+k*COLS+d);

                // sum = sum + m1[i][row]*m2[row][col];

            }
            *(mp1+c*COLS+d) = f;
            f = 0;
        }
    }
    // m1[i][col] = sum;
    
    //  for(size_t row=0; row<ROWS; ++row) {
    //     printf("\n");
    //     for(size_t col=0; col<COLS; ++col) {
    //         printf("%7.2f", m1[row][col]);
    //     }
    // }
    // printf("\n");

}
// void matMul(fMatrix* m1, fMatrix* m2) {
//     float sum = 0;
//     float i, row, col, f;
    
//     float *mp1 = (float *)m1;
//     float *mp2 = (float *)m2;
//     // float *mp3 = (float *)m1;

//     for (size_t i = 0; i < ROWS; i++) {
//         for (size_t col = 0; col < COLS; ++col) {
//             for (size_t row = 0; row < ROWS; ++row) {
//                 // m1[row][col] = m1[row][col] + m2[row][col];
//                 // *(mp3+row*COLS+col) = *(mp3+i*COLS+row) + *(mp1+i*COLS+row) * *(mp2+row*COLS+col);
//                 // *(mp1+row*COLS+col) = *(mp1+i*COLS+row) * *(mp2+row*COLS+col);
//                 f = f + *(mp1+i*COLS+row) * *(mp2+row*COLS+col);

//                 // sum = sum + m1[i][row]*m2[row][col];

//             }
//             *(mp1+i*COLS+col) = f;
//             f = 0;
//         }
//     }
// }