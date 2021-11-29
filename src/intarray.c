#include <stdio.h>
#include <stdbool.h>
#include "intarray.h"

// int intArray() {
//     printf("intArray");


// }

void printArray(intArray a) {
    printf("[");
    for(int i=0; a[i]!=SENTINEL; i++) {
        printf(" %d", a[i]);
    }
    puts(" ]");
}

int getIntArraySize(intArray a) {
    int size = 0;
    for (int i = 0; a[i] != SENTINEL; ++i) 
        size = i+1;

    return size;
}

int getIntArray(intArray a) {

    char input[CAPACITY];
    printf("Please enter a comma-separated list of positive integers: ");
    fgets(input, CAPACITY, stdin);

    // pekare som pekar på \n -1
    int strLength = strlen(input)-1;
    // printf("Input length is: %d\n", strLength);

    // int covertToIntArray(int strLength, char input, intArray a);

    char *numPtr;
    int pointingIndex = 0;

    for (int i = 0; input[pointingIndex+1] != '\0';) {

        int number = strtol(input+pointingIndex, &numPtr, 10);
        if (number != 0) {
            pointingIndex = numPtr - input;
            a[i] = number;
            i++;
            strLength = i;
        }
        else {
            int nextNumber = strtol(input+pointingIndex+1, &numPtr, 10);
            if (nextNumber == 0 || input[0] == ',') {
                puts("[]");
                return false;
            }
            pointingIndex++;
        }
    }
    a[strLength] = SENTINEL;
    printArray(a);
    return true; 
}

void appendIntArray(intArray a, intArray b, intArray c) {
    int h;
    for (int i = 0, j = 0; a[i] != SENTINEL || b[j] != SENTINEL;) {
        if (a[i] != SENTINEL) {
            c[i] = a[i];
            i++;
        }
        else if (b[j] != SENTINEL) {
            c[i+j] = b[j];
            j++;
        }
        h = i+j;
    }
    c[h] = SENTINEL;
    printArray(c);
}

void interleaveIntArray(intArray a, intArray b, intArray c) {
    int h = 0;
    for (int i = 0, j = 0; a[i] != SENTINEL || b[j] != SENTINEL;) {
        if (a[i] != SENTINEL) {
            c[h] = a[i];
            i++;
            h++;
        }
        if (b[j] != SENTINEL) {
            c[h] = b[j];
            j++;
            h++;
        }
    }
    c[h] = SENTINEL;
    printArray(c);
}

void sortIntArray(intArray a) {
    setUniqueness();
    setSortOrder();
    if (sortOrder == ASCENDING) {
        bubbleSort(a, CAPACITY);
        puts("\nData items in ascending order: ");
    }
    else { // pass function descending
        bubbleSort(a, CAPACITY);
        puts("\nData items in descending order: ");
    }
    if (uniqueness == UNIQUE) {
        filterUnique(a);
        puts("\nUnique numbers:");
    }
    printArray(a);
}

void setSortOrder() {
    // static variables, värdena ska komma från 2 olika enumtypes
    // Fråga static varable?
    // sort ascending och descending

    printf("Enter 0 to sort in ascending order,\n"
    "Enter 1 to sort in descending order: ");
    int order; // 0 for ascending order or 1 for descending order
    scanf("%d", &order);
    if (order == 0) sortOrder = ASCENDING;
    else sortOrder = DESCENDING;
}

void setUniqueness() {
    printf("Enter 0 to for only unique numbers,\n"
    "Enter 1 to for only nonunique numbers: ");
    int unique; // 0 for unique or 1 for nonunique
    scanf("%d", &unique);
    if (unique == 0) uniqueness = UNIQUE;
    else uniqueness = NONUNIQUE;
}

void filterUnique(intArray a) {
    printArray(a);
    intArray buffer = {0}; 
    memcpy(buffer, a,CAPACITY);
    // loop to control passes

        // loop to control comparisons during each pass
        for (size_t j = 0; buffer[j+1] != SENTINEL; ++j) {

            // swap adjacent elements if they’re out of order
            if (a[j] == a[j + 1]) {
                buffer[j] = buffer[j+1];
                // removeDuplicate(&a[j], &a[j + 1]);
            }
        }   
    memcpy(a, buffer,CAPACITY);
} 

// void removeDuplicate(int *element1Ptr, int *element2Ptr, intArray a) {
//     intArray buffer = a;
//     for (size_t i = 0; buffer[i] != SENTINEL; i++)
//     {
//         buffer[i] = buffer[i+1];
//     }
//     a = buffer;    
// }

void bubbleSort(intArray a, const size_t size) {

    // loop to control passes
    // for (unsigned int pass = 0; pass < size - 1; ++pass) {

        // loop to control comparisons during each pass
            printArray(a);
        for (size_t j = 0; j < size - 1; ++j) {

            if (sortOrder == ASCENDING)
            {
                if (a[j] > a[j + 1]) {
                    swap(&a[j], &a[j + 1]);
                }
            }
            else {
                if (a[j] < a[j + 1]) {
                    swap(&a[j], &a[j + 1]);
                }
            }
            // swap adjacent elements if they’re out of order
            // else swap(&a[j+1], &a[j]);
        }   
            printArray(a);

    // }
} 

void swap(int *element1Ptr, int *element2Ptr) {
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}