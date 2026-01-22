#include <stdio.h>

// Recursive function to get the n-th Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    else {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int main() {
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Fibonacci series is not possible for negative terms.\n");
    } else {
        printf("Fibonacci Series: ");
        
        for (i = 0; i < n; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}


