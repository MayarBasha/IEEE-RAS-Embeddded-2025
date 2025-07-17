#include <stdio.h>

// Enum for arithmetic operations
typedef enum {
    ADD = '+',      // 43 in ASCII
    SUBTRACT = '-', // 45 in ASCII
    MULTIPLY = '*', // 42 in ASCII
    DIVIDE = '/',   // 47 in ASCII
    BITWISE_AND = '&', // 38 in ASCII
    BITWISE_OR = '|',  // 124 in ASCII
    LOGICAL_NOT = '!'  // 33 in ASCII
} ArithmeticOperation;

int main() {
    int operand1, operand2;
    char operation_char;

    printf("Enter first operand: ");
    scanf("%d", &operand1);

    printf("Enter second operand: ");
    scanf("%d", &operand2);

    printf("Enter operation (+, -, *, /, &, |, !): ");
    scanf(" %c", &operation_char); // Note the space before %c to skip whitespace

    ArithmeticOperation op = (ArithmeticOperation)operation_char;

    switch(op) {
        case ADD:
            printf("Result: %d\n", operand1 + operand2);
            break;
        case SUBTRACT:
            printf("Result: %d\n", operand1 - operand2);
            break;
        case MULTIPLY:
            printf("Result: %d\n", operand1 * operand2);
            break;
        case DIVIDE:
            if (operand2 != 0) {
                printf("Result: %d\n", operand1 / operand2);
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        case BITWISE_AND:
            printf("Result: %d\n", operand1 & operand2);
            break;
        case BITWISE_OR:
            printf("Result: %d\n", operand1 | operand2);
            break;
        case LOGICAL_NOT:
            printf("Result for operand1: %d\n", !operand1);
            printf("Result for operand2: %d\n", !operand2);
            break;
        default:
            printf("Error: Unknown operation\n");
    }

    return 0;
}
/*If we add extra members:

If we add more members that can still be represented within the range of an int, the size will remain 4 bytes.

If we add a member that requires a larger value (like a value that can't fit in an int but fits in a long),
 the enum size might increase to 8 bytes (size of long) depending on the compiler implementation.*/