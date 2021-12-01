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
void displayMainMenu();

int main() {
    intArray a = {0}, b = {0}, c = {0};
    
    // fMatrix *m = createMatrix(0.00);
    // destroyMatrix(m);
    // printMatrix(m);
    // fMatrix *m1 = createMatrix(0.00), *m2 = createMatrix(0.00);
    int inputValue = 0;
   
    displayMainMenu(); // Displays the different options you have.
   while (inputValue != 7) {

      printf("Select an option: ");
      scanf("%d", &inputValue);

      switch (inputValue) {
         
        case 1:
            for (int i = 0; i < 2 ; ) {
                printf("Please enter %s comma-separated list of positive integers: ", (i == 0 ? "first": "second"));
                if(getIntArray(i == 0 ? a : b)) {
                    i++;
                    if (i == 2) {
                        appendIntArray(a,b,c);
                        printArray(c);
                    }
                }
                else puts("Oops! You entered a invalid list, please try again. ");
            }
            break;

        case 2:
           for (int i = 0; i < 2 ; ) {
                printf("Please enter %s comma-separated list of positive integers: ", (i == 0 ? "first": "second"));
                if(getIntArray(i == 0 ? a : b)) {
                    i++;
                    if (i == 2) {
                        interleaveIntArray(a,b,c);
                        printArray(c);
                    }
                }
                else puts("Oops! You entered a invalid list, please try again. ");
            }
            break;
         
        case 3:
            for (size_t i = 0; i < 1;) {
                printf("Please enter a comma-separated list of positive integers: ");
                if (getIntArray(a)) {
                    sortIntArray(a);
                    printArray(a);
                    i++;
                }
                else printf("Oops! You entered a invalid list, please try again. ");
            }
            break;

        case 4:
            fMatrix *m1 = createMatrix(0.00), *m2 = createMatrix(0.00);
            getMatrix(m1);
            printMatrix(m1);
            getMatrix(m2);
            printMatrix(m2);
            matAdd(m1,m2);
            printf("Result:\n");
            printMatrix(m1);
            destroyMatrix(m1); destroyMatrix(m2);
            break;

        case 5:
            // fMatrix *m1 = createMatrix(0.00), *m2 = createMatrix(0.00);
            // printf("Please enter first comma-separated list of 9 floats: ");
            // getMatrix(m1);
            // printMatrix(m1);
            // printf("Please enter second comma-separated list of 9 floats: ");
            // getMatrix(m2);
            // printMatrix(m2);
            // // matMul(m1,m2);
            // printf("Result:\n");
            // printMatrix(m1);
            // destroyMatrix(m1); destroyMatrix(m2);
            break;

        case 6:
            displayMainMenu();
            break;

        case 7:
            break;

         default:
            puts("Please enter a valid option!\n");
            break;   
      }
    }
    // intArray a = {1,1,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,SENTINEL};
    // intArray a = {2,6,8,4,5,SENTINEL};
    // intArray b = {3,4,6,7,9,SENTINEL};
    // intArray c;
    // intArray arr = {0};

    // printArray(a); 
    // appendIntArray(a,b,c);
    // interleaveIntArray(a,b,c);
    // sortIntArray(a);
    // fMatrix *m = createMatrix(0.00);
    // printMatrix(m);
    // destroyMatrix(m);
    // getMatrix(m);
    // printMatrix(m);
    // destroyMatrix(m);
    

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

// Displays the mainmenu and prompts the user to pick a game or to quit.
void displayMainMenu() {
   puts("\n== Main Menu ==\n"
   "1. Append two integer arrays.\n"
   "2. Interleave two integer arrays.\n"
   "3. Sort an integer array.\n"
   "4. Add two 3x3 float matrices.\n"
   "5. Multiply two 3x3 float matrices.\n"      
   "6. Print Main Menu.\n"      
   "7. Quit\n");      
} // end of mainmenu