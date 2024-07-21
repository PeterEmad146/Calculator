#include <stdio.h>
#include <stdbool.h>

/*
 * Requirements:
 * - The calculator should be console-based.
 * - It should perform basic arithmetic operations: addition, subtraction, multiplication, and division.
 * - The user should be able to input two numbers and select the operation.
 * - Implement error handling for invalid inputs and division by zero.
 * - The program should continue to run until the user chooses to exit.
 */

int main (){
    printf("---------------------\n");
    printf("| Simple Calculator |\n");
    printf("---------------------\n\n");

    char execution;
    int first_operand;
    int second_operand;
    char operator;

    while(true){
        printf("ENTER \"x\" to exit or ENTER \"y\" to continue\n");
        scanf(" %c", &execution);
        getchar(); // Consume the newline character left in the buffer

        if(execution == 'x')
            return 0;

        else if (execution != 'y'){
            printf("Invalid Input! Try again.\n");
            continue;
        }

        else {
            printf("Enter first operand:\n");
            if (scanf("%d", &first_operand) != 1) { // Check if input is a valid number
                printf("Invalid Input! Please enter a valid number.\n");
                while (getchar() != '\n'); // Clear the input buffer
                continue; // Start the loop again
            }

            printf("Enter second operand:\n");
            if (scanf("%d", &second_operand) != 1) { // Check if input is a valid number
                printf("Invalid Input! Please enter a valid number.\n");
                while (getchar() != '\n'); // Clear the input buffer
                continue; // Start the loop again
            }

            printf("Enter operator:\n");
            scanf(" %c", &operator); // Note the space before %c to skip any whitespace
            getchar(); // Consume the newline character left in the buffer

            switch (operator) {
                case '+':
                    printf("Result: %d\n", first_operand + second_operand);
                    break;
                case '-':
                    printf("Result: %d\n", first_operand - second_operand);
                    break;
                case '*':
                    printf("Result: %d\n", first_operand * second_operand);
                    break;
                case '/':
                    if (second_operand == 0)
                        printf("Error: Division by zero!\n");
                    else
                        printf("Result: %d\n", first_operand / second_operand);
                    break;
                default:
                    printf("Invalid operator!\n");
                    break;
            }
        }
    }
}