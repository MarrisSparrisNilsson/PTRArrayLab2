#include <stdio.h> // Fråga
#include <stdbool.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
#include "intarray.h"
#include "fmatrix.h"
/*
// Fråga 
*/

int main() {
    // intArray a = {1,1,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,SENTINEL};
    // intArray a = {2,6,8,4,5,SENTINEL};
    // intArray b = {3,4,6,7,9,SENTINEL};
    // intArray c;

    // printArray(a); 

    intArray arr = {0};
    bool y;

    y = getIntArray(arr); // Fråga
    // printf("%s\n", y == 1 ? "True" : "False");

    // appendIntArray(a,b,c);
    // interleaveIntArray(a,b,c);
    // sortIntArray(a);
    fMatrix *m = createMatrix(0.00);
    printMatrix(m);
    destroyMatrix(m);
    getMatrix(m);


    // fMatrix m1 = {
    //     {1.0, 3.0, 5.4},
    //     {1.7, 9.1, 8.2},
    //     {6.3, 4.7, 52.0}
    // };

    // fMatrix m2 = {
    //     {1.0, 3.9, 5.0},
    //     {8.1, 2.5, 9.8},
    //     {6.0, 3.7, 1.1}
    // };

    // fMatrix *m1 = createMatrix(0.00);
    // fMatrix *m2 = createMatrix(0.00);


    // matAdd(m, m1);

    // printMatrix(matAdd(m1, m2));
    // printMatrix(m1);

    return 0;
}