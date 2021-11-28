#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
// Fråga 
*/


#define SENTINEL -1
#define CAPACITY 20

typedef int intArray[CAPACITY];

enum SortOrder {ASCENDING, DESCENDING};
enum Uniqueness {UNIQUE, NONUNIQUE};

void printArray(intArray a);
int getIntArraySize(intArray a);
int getIntArray(intArray a);
void appendIntArray(intArray a, intArray b, intArray c);
void interleaveIntArray(intArray a, intArray b, intArray c);
void sortIntArray(intArray a);
void setSortOrder(enum SortOrder sortOrder);
void setUniqueness(enum Uniqueness uniqueness);
void bubbleSort(int * const a, const size_t size);
void swap(int *element1Ptr, int *element2Ptr);

int main() {
    // intArray a = {SENTINEL};
    intArray a = {2,6,8,4,5,SENTINEL};
    intArray b = {3,4,6,7,9,SENTINEL};
    intArray c;

    printArray(a); 
    printf("%d\n", getIntArraySize(a));


    intArray arr = {0};
    bool y;

    y = getIntArray(arr);
    printf("%s\n", y == 1 ? "True" : "False");

    appendIntArray(a,b,c);
    interleaveIntArray(a,b,c);
    // printIntArray(c);
    return 0;
}

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

    int strLength = strlen(input)-1;
    printf("Input length is: %d\n", strLength);

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
    // Fråga
    // int arrLength = strlen (a)-1 + strlen (b)-1;
    // for (int i = 0; i < arrLength; i++) {
    //     if (a[i] != SENTINEL)
    //     {
    //         c[i] = a[i];
    //     }
    //     else if (i <= strlen (b))
    //     {
    //         c[i] = b[i];
    //     }
    // }
    c[h] = SENTINEL;
    printArray(c);
    // printf("/n%d", c);
}

void interleaveIntArray(intArray a, intArray b, intArray c) {
    printArray(a);
    printArray(b);
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
    int order;
    if (order == 0) {
    bubbleSort(a, CAPACITY);
    puts("\nData items in descending order");
    }
    else { // pass function descending
    bubbleSort(a, CAPACITY);
    }
    puts("\nData items in ascending order");

}

void setSortOrder(enum SortOrder sortOrder) {
    // static variables, värdena ska komma från 2 olika enumtypes
    // Fråga static varable?
    // sort ascending och descending

    // char ascOrdes[1];
    // printf("Do you want to sort the list in ascending or descending order? a/d");
    // scanf("%c", &ascOrdes);

    printf("%s", "Enter 1 to sort in ascending order,\n"
    "Enter 2 to sort in descending order: ");
    int order; // 1 for ascending order or 2 for descending order
    scanf("%d", &order);

    
    // if (ascOrdes == a) {
    //     // sort in ascenind order
    // }
    // else { //sort in descending order
    // }    
    // setUniqueness();
}
void setUniqueness(enum Uniqueness uniqueness) {

}

void bubbleSort(int * const a, const size_t size) {

    // loop to control passes
    for (unsigned int pass = 0; pass < size - 1; ++pass) {

        // loop to control comparisons during each pass
        for (size_t j = 0; j < size - 1; ++j) {

            // swap adjacent elements if they’re out of order
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
            // if (a[j] > a[j + 1]) {
            //     swap(&a[j], &a[j + 1]);
        }   
    }
} 

void swap(int *element1Ptr, int *element2Ptr) {
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}