#include <stdio.h>

// Recursive function to get the n-th Fibonacci number
int fibonacci(int n) {
    // Base cases: the first two terms are 0 and 1
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    // Recursive case: the n-th term is the sum of the two preceding ones
    else {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int main() {
    int n, i;

    // Get the number of terms from the user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Fibonacci series is not possible for negative terms.\n");
    } else {
        printf("Fibonacci Series: ");
        // Loop from 0 to n-1 to print each term
        for (i = 0; i < n; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}

