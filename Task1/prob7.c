#include <stdio.h>
#include <stdbool.h>


int main() {
    int number, sum = 0;

    // Prompt user for a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Calculate the sum of digits
    int temp = number;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    // Display the sum of digits
    printf("Sum of digits: %d\n", sum);

    // Check if the sum is a prime number

    for (int i = 2; i * i <= sum; i++) {
        if (sum % i == 0) {
             printf("The sum of digits (%d) is not a prime number.\n", sum);
return 0;
        }
        }

        printf("The sum of digits (%d) is a prime number.\n",sum);


    return 0;
}

