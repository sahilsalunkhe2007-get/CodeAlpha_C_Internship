/* CodeAlpha Task 1: Basic Calculator */
#include <stdio.h>

int main(void) {
    double a, b;
    int choice;

    printf("===== BASIC CALCULATOR =====\n");
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input. Please enter numeric values.\n");
        return 1;
    }

    printf("\n1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division (/)\n");
    printf("Choose an operation (1-4): ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid choice.\n");
        return 1;
    }

    switch (choice) {
        case 1: printf("Result = %.2f\n", a + b); break;
        case 2: printf("Result = %.2f\n", a - b); break;
        case 3: printf("Result = %.2f\n", a * b); break;
        case 4:
            if (b == 0.0) printf("Error: Division by zero is not allowed.\n");
            else printf("Result = %.2f\n", a / b);
            break;
        default: printf("Invalid choice. Select 1 to 4.\n");
    }
    return 0;
}
