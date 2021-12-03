#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "fmatrix.h"

// Start of function createMatrix.
fMatrix* createMatrix(float f) {
    fMatrix *mPtr = (fMatrix*) malloc(sizeof(fMatrix)); // Allocates memory on the heap for a fMatrix.
    if (mPtr == NULL) return NULL;

    float *mp = (float *)mPtr;
    // Initialzies the created fMatrix's values to 0.00
    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t col = 0; col < COLS; ++col) {
            *(mp+row*COLS+col) = f;
        }
    }
    return mPtr;
} // End of function createMatrix.

// Start of function destroyMatrix.
void destroyMatrix(fMatrix* m) {
    if(m != NULL) {
        free(m); // Deallocates the memory for the fMatrix on the heap.
    }
    m = NULL; // Sets the fMatrix to NULL.
} // End of function destroyMatrix.

// Start of function printMatrix.
void printMatrix(fMatrix* m) { // Prints a fMatrix and a result of matAdd and matMul.
    float *mp = (float *)m;

    puts("\nResult:");
    printf("=============================");
    for(size_t row=0; row<ROWS; ++row) {
        printf("\n");
        for(size_t col=0; col<COLS; ++col) {
            printf("%9.2f", *(mp+row*COLS+col));
        }
    }
    puts("\n=============================");
} // End of function printMatrix.

// Start of function getMatrix.
bool getMatrix(fMatrix* m) { //Takes a string with numbers and commas form the user and creates a 2-dimensional array if the string has the correct format.
    char *endPtr;
    char input[SIZE];
    float *mp = (float *)m; // Declares a new pointer mp that points to the matrix m.

    fflush(stdin);
    fgets(input, SIZE, stdin);
    input[strlen(input)-1] = '\0'; // Removes '\n' character that was added by fgets.

    // If first or last character is (,) string is invalid.
    if (input[0] == ',' || (input[strlen(input) - 1]) == ',') return false;

    char *tokenPtr = strtok(input, ",");
    char *lastDigitPtr = NULL; // Pointer that points to the last position of each token string.
    int memdiff;
    int row = 0;
    int col = 0;

    while(tokenPtr != NULL) {
        int lastDigitIndex = strlen(tokenPtr) - 1; // Gets the index of the last digit in the string token.
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
    return true; // Returns true if the string entered has the correct format.
} // End of function getMatrix.

// Start of function matAdd.
void matAdd(fMatrix* m1, fMatrix* m2) { // Adds the values of 2 fMatrixes and then puts the value in the first fMatrix.
    float *mp1 = (float *)m1;
    float *mp2 = (float *)m2;
    for (size_t row = 0; row < ROWS; ++row) { 
        for (size_t col = 0; col < COLS; ++col) { // Puts the value after an addition was made into correct slot of the first fMatrix.
            *(mp1+row*COLS+col) = (*(mp1+row*COLS+col) + *(mp2+row*COLS+col));
        }
    }
} // End of function matAdd.

// Start of function matMul.
void matMul(fMatrix* m1, fMatrix* m2) { // Preforms matrix multiplication.
    fMatrix* m3 = createMatrix(0.00); // Creates a buffert fMatrix to store values from the matrix multiplication.
    float *mPtr1 = (float *)m1;
    float *mPtr2 = (float *)m2;
    float *mPtr3 = (float *)m3;

    float sum = 0;
    for (size_t i = 0; i < ROWS; ++i) {
        for (size_t j = 0; j < COLS; ++j) {
            for (size_t k = 0; k < ROWS; ++k) { // Preforms matrix multiplication and allocates the value to the sum variable.
                sum = sum + *(mPtr1+i*COLS+k) * *(mPtr2+k*COLS+j);
            }
            *(mPtr3+i*COLS+j) = sum; // Puts the value from sum into the correct slot in our buffert fMatrix.
            sum = 0;
        }
    }
    for (size_t row = 0; row < ROWS; ++row) { // Changes values in m1 to the same values as our buffert Matrix.
        for (size_t col = 0; col < COLS; ++col) {
            *(mPtr1+row*COLS+col) = *(mPtr3+row*COLS+col);
        }
    }
    destroyMatrix(m3);
} // End of function matMul.
