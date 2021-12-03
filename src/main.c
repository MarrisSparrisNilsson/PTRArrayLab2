#include <stdio.h>
#include <stdbool.h>
#include "intarray.h"
#include "fmatrix.h"

void displayMainMenu();

// Start of the main function.
int main() { 
    intArray a = {0}, b = {0}, c = {0};
    fMatrix *m1, *m2;

    int inputValue = 0;
   
    displayMainMenu(); // Displays the different options you have.
    while (inputValue != 7) {
        printf("Select an option (1-7): ");
        scanf("%d", &inputValue);

        switch (inputValue) {
            
            case 1:
                puts("\n=== Append two integer arrays ===");
                for (size_t i = 0; i < 2 ; ) { // Loops until the user inserts the correct format.
                    printf("Please enter %s comma-separated list of positive integers: ", (i == 0 ? "first": "second"));
                    if(getIntArray(i == 0 ? a : b)) {
                        i++;
                        if (i == 2) {
                            appendIntArray(a,b,c);
                            printArray(c);
                        }
                    } else puts("Oops! You entered an invalid list, please try again.");
                } break;

            case 2:
                puts("\n=== Interleave two integer arrays ===");
                for (size_t i = 0; i < 2 ; ) { // Loops until the user inserts the correct format.
                    printf("Please enter %s comma-separated list of positive integers: ", (i == 0 ? "first": "second"));
                    if(getIntArray(i == 0 ? a : b)) {
                        i++;
                        if (i == 2) {
                            interleaveIntArray(a,b,c);
                            printArray(c);
                        }
                    } else puts("Oops! You entered an invalid list, please try again.");
                } break;
                
            case 3:
                puts("\n=== Sort an integer array ===");
                for (size_t i = 0; i < 1;) { // Loops until the user inserts the correct format.
                    printf("Please enter a comma-separated list of positive integers: ");
                    if (getIntArray(a)) {
                        sortIntArray(a);
                        printArray(a);
                        i++;
                    } else printf("Oops! You entered an invalid list, please try again.");
                } break;

            case 4:
                m1 = createMatrix(0.00);
                m2 = createMatrix(0.00);
                puts("\n=== Add two 3x3 float matrices ===");
                for (size_t i = 0; i < 2 ; ) { // Loops until the user inserts the correct format.
                    printf("Please enter %s comma-separated list of 9 floats: ", (i == 0 ? "first": "second"));
                    if(getMatrix(i == 0 ? m1 : m2)) {
                        i++;
                        if (i == 2) {
                            matAdd(m1,m2);
                            printMatrix(m1);
                        }
                    } else puts("Oops! You entered an invalid list, please try again.");
                }
                destroyMatrix(m1); 
                destroyMatrix(m2);
                break;

            case 5:
                m1 = createMatrix(0.00);
                m2 = createMatrix(0.00);
                puts("\n=== Multiply two 3x3 float matrices ===");
                for (size_t i = 0; i < 2 ; ) { // Loops until the user inserts the correct format.
                    printf("Please enter %s comma-separated list of 9 floats: ", (i == 0 ? "first": "second"));
                    if(getMatrix(i == 0 ? m1 : m2)) {
                        i++;
                        if (i == 2) {
                            matMul(m1,m2);
                            printMatrix(m1);
                        }
                    } else puts("Oops! You entered an invalid list, please try again.");
                }
                destroyMatrix(m1);
                destroyMatrix(m2);
                break;

            case 6:
                displayMainMenu();
                break;

            case 7: break;

            default:
                puts("Please enter a valid option!\n");
                break;   
        }
    }
    return 0;
} // End of the main function.

// Start of function displayManiMenu.
void displayMainMenu() { // Displays the main menu and promtps the user to select an option.
   puts("\n== Main Menu ==\n"
   "1. Append two integer arrays.\n"
   "2. Interleave two integer arrays.\n"
   "3. Sort an integer array.\n"
   "4. Add two 3x3 float matrices.\n"
   "5. Multiply two 3x3 float matrices.\n"      
   "6. Print Main Menu.\n"      
   "7. Quit\n");      
} // End of displayMainMenu