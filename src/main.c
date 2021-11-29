#include <stdio.h>
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
    intArray a = {2,6,8,4,5,SENTINEL};
    intArray b = {3,4,6,7,9,SENTINEL};
    intArray c;

    printArray(a); 

    intArray arr = {0};
    bool y;

    y = getIntArray(arr);
    printf("%s\n", y == 1 ? "True" : "False");

    appendIntArray(a,b,c);
    interleaveIntArray(a,b,c);
    sortIntArray(a);
    // createMatrix(float);
    // destroyMatrix(m);
    // printMatrix(m);
    return 0;
}