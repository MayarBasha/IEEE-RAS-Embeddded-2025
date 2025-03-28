#include <stdio.h>

// Recursive function to find GCD
int gcd(int a, int b) {
    // Base case
    if (b == 0)
        return a;
    // Recursive case
    return gcd(b, a % b);
}

int main() {
    int num1, num2;


    printf(" first number: ");
    scanf("%d", &num1);

    printf("second number: ");
    scanf("%d", &num2);

    // Calculate GCD
    int result = gcd(num1, num2);


    printf("GCD of %d and %d = %d\n", num1, num2, result);

    return 0;
}
