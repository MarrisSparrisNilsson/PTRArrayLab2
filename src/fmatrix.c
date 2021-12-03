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

    puts("\nResult:");
    printf("=============================");
    for(size_t row=0; row<ROWS; ++row) {
        printf("\n");
        for(size_t col=0; col<COLS; ++col) {
            // printf("%.2f ", *m[row][col]);
            printf("%9.2f", *(mp+row*COLS+col));
        }
    }
    puts("\n=============================");
}

bool getMatrix(fMatrix* m) {
    char *endPtr;
    char input[SIZE];
    float *mp = (float *)m; // Declares a new pointer that points to the m matrix.

    scanf("%s", &input);

    // If first or last character is (,)
    if (input[0] == ',' || (input[strlen(input) - 1]) == ',') return false;

    char *tokenPtr = strtok(input, ",");

    char *lastDigitPtr = NULL; // Pointer that points to the last position of the each token string
    int memdiff;

    int row = 0;
    int col = 0;

    while(tokenPtr != NULL) {
        int lastDigitIndex = strlen(tokenPtr) - 1; // Gets the index of the last digit in the string token

        // Loops to check if the token string contains any other character that isn't used for float values.
        for (size_t i = 0; i < strlen(tokenPtr); i++) {
            if (!isdigit(*(tokenPtr+i)) && *(tokenPtr+i) != '.') 
                return false;
        }

        if (lastDigitPtr != NULL) {
            memdiff = tokenPtr - lastDigitPtr; // If the position difference (in memory) of the last digit of the previous number and
            if (memdiff > 2) return false;     // the start of the next number is greater than 2 bytes, that means its not formatted correctly.
        }

        if (col == COLS) { // Goes to next row and resets column at the end of each row.
            col=0;
            row++;
        }

        float floatValue = strtod(tokenPtr, &endPtr); // Converts string to float value.
        *(mp+row*COLS+col) = floatValue; // Placing the float value in the correct slot in the matrix.
        col++;

        lastDigitPtr = *(&tokenPtr) + lastDigitIndex; // Points the pointer to the last position of the token string.
        tokenPtr = strtok(NULL, ","); // Continues to search the rest of the string. 
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
