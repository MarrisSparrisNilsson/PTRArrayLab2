#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SENTINEL -1
#define CAPACITY 20

typedef int intArray[CAPACITY];

void printArray(intArray a);
int getIntArraySize(intArray a);
int getIntArray(intArray a);

int main() {
    // intArray a = {SENTINEL};
    intArray a = {2,6,8,4,5,SENTINEL};

    printArray(a); 
    printf("%d\n", getIntArraySize(a));


    intArray arr = {0};
    bool b;

    b = getIntArray(arr);
    printf("%s", b == 1 ? "True" : "False");

    
    return 0;
}

void printArray(intArray a) {
    printf("[");
    for(int i=0; a[i]!=SENTINEL; i++) {
        printf(" %d ", a[i]);
    }
    puts("]");
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
    scanf("%[^\n]", &input);

    int strLength = strlen(input);
    printf("%d", strlen(input));

    if (!isdigit(input[0])) {
        puts("[]");
        return false;
    }
    if (!isdigit(input[strlen(input)-1])) {
        puts("[]");
        return false;
    }

    char arr[CAPACITY];
    // char arr[strlen(input)];
    for (int i = 0; i < strlen(input); i++) {
        if (!isblank(input[i])) {
            arr[i] = input[i];
        }        
    }
    

    for (int i = 0; i < strlen(arr); i++) {
        if (!isdigit(arr[i]) && i <= strlen(arr)) {
            // if (isblank(arr[i+1])){
            //     i++;
            // }
            if (!isdigit(arr[i+1])) {
                printf("[]");
                return false;
            }
            
        }
        if (arr[i] < 0) return false;

    }
    printf("[ %d ]", input);

    return true;
}