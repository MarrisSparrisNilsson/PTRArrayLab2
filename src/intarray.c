#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "intarray.h"

// Start of function printIntArray.
void printArray(intArray a) { // Prints an intArray.
    printf("[");
    for(size_t i=0; a[i]!=SENTINEL; i++) printf(" %d", a[i]);
    puts(" ]\n");
}// End of function printIntArray.

// Start of function getIntArraySize.
int getIntArraySize(intArray a) { // Returns the length of an intArray.
    int size = 0;
    for (size_t i = 0; a[i] != SENTINEL; ++i) size = i+1;
    return size;
}//End of function getIntArraySize.

// Start of function getIntArray.
bool getIntArray(intArray a) {//Takes a string with numbers and commas form the user and creates an intarray if the string has the correct format.
    char input[CAPACITY];
    char *endPtr;
    fflush(stdin);
    fgets(input, CAPACITY, stdin);


    if (// Returns false if the user tries to insert spaces or commas before inserting a number and if the user inserts a comma at the end of the string.
        input[0] == ',' 
        || *(strchr(input, '\n')-1) == ',' 
        || input[0] == ' '
    ) return false;

    size_t j = 0;
    for (size_t i = 0, k = 0; input[i] != '\n'; i++, k++) {// Loops through the string.
        
        if (input[i] == ',' && input[i+1]== ',') return false; // Return false if the user entered 2 commas in a row.
        
        int count = 0;
        for (; input[k] != ',' && input[k] != '\n'; k++) {// Controls when a number is longer than only 1 digit.
                if (isdigit(input[k]) && isdigit(input[k+1])) count++;
            }
        int init = strtol(input + i, &endPtr, 10); // Returns 0 if input + i is anything else than a number.
        i = i + count; 
        k = i;


        if (init != 0) {
            while (init != SENTINEL) {// Initializes the intArray with ints as long as SENTINEL value not found.
            a[j] = init;
             j++;
            break;
            }
        }
    }
    a[j] = SENTINEL;
    return true; // Returns true if the string entered has the correct format.
}// End of function getIntArray.

// Start of function appendIntArray.
void appendIntArray(intArray a, intArray b, intArray c) {// Appends 2 intArrays into third intArray.
    size_t h;
    for (size_t i = 0, j = 0; a[i] != SENTINEL || b[j] != SENTINEL;) {
        if (a[i] != SENTINEL) {// Puts values from intArray a into the correct slots of intArray c as long as SENTINEL value not found.
            c[i] = a[i];
            i++;
        }
        // When all values from intArray a is stored in intArray c 
        // the function starts putting values from intArray b into the correct slots of intArray c as long as SENTINEL value not found.
        else if (b[j] != SENTINEL) {
            c[i+j] = b[j];
            j++;
        }
        h = i+j;
    }
    c[h] = SENTINEL;// Puts SENTINEL value at the end of the intArray c.
}// End of function appendIntArray.

// Start of function interleaveIntArray.
void interleaveIntArray(intArray a, intArray b, intArray c) {// interleaves values from 2 intArrays and puts the result in a third intArray.
    size_t h = 0;
    for (size_t i = 0, j = 0; a[i] != SENTINEL || b[j] != SENTINEL;) {
        if (a[i] != SENTINEL) {// Puts values from intArray a into the correct slots of intArray c as long as SENTINEL value not found.
            c[h] = a[i];
            i++;
            h++;
        }
        if (b[j] != SENTINEL) {// Puts values from intArray b into the correct slots of intArray c as long as SENTINEL value not found.
            c[h] = b[j];
            j++;
            h++;
        }
    }
    c[h] = SENTINEL; // Puts SENTINEL value at the end of the intArray c.
}// End of function interleaveIntArray..

// Start of function sortIntArray.
void sortIntArray(intArray a) {
    setUniqueness();
    setSortOrder();
    bubbleSort(a);
    if (uniqueness == UNIQUE) {
        filterUnique(a);
    }
}// End of function sortIntArray.

// Start of function setSortOrder.
void setSortOrder() {
    printf("Enter 0 to sort in ascending order,\n"
    "Enter 1 to sort in descending order: ");
    int order; // 0 for ascending order or 1 for descending order
    scanf("%d", &order);
    if (order == 1) sortOrder = DESCENDING;
    else sortOrder = ASCENDING;
}// End of function setSortOrder.

// Start of function setUniqueness.
void setUniqueness() {
    printf("Enter 0 to for only unique numbers,\n"
    "Enter 1 to for only nonunique numbers: ");
    int unique; // 0 for unique or 1 for nonunique
    scanf("%d", &unique);
    if (unique == 0) uniqueness = UNIQUE;
    else uniqueness = NONUNIQUE;
}// End of function setUniqueness.

// Start of function filterUnique.
void filterUnique(intArray a) {
    // loop to control comparisons during each pass
    for (size_t j = 0; a[j+1] != SENTINEL; ++j) {
        if (a[j] == a[j + 1]) {
            for (size_t i = j; a[i] !=SENTINEL; ++i) {// Only inserts unique values into an intArray.
                a[i] = a[i+1];
            }
            j = 0;    
        } 
    }   
}// End of function filterUnique.

// Start of function bubbleSort.
void bubbleSort(intArray a) {// Sorts an intArray in descending or ascending order.
    for (unsigned int pass = 0; a[pass + 1] != SENTINEL; ++pass) {

        // loop to control comparisons during each pass
        for (size_t j = 0; a[j + 1] != SENTINEL; ++j) {

            if (sortOrder == ASCENDING) {
                if (a[j] > a[j + 1]) {
                    swap(&a[j], &a[j + 1]);
                }
            }
            if (sortOrder == DESCENDING) {
                if (a[j] < a[j + 1]) {
                    swap(&a[j], &a[j + 1]);
                }
            }
        }   
    }
}// End of function swap. 

// Start of function swap.
void swap(int *element1Ptr, int *element2Ptr) {// Swaps elements in an intArray.
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}// End of function swap.