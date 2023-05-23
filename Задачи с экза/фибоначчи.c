#include <stdio.h>

int main() {
    int i, n = 500;
    unsigned long long fib1 = 0, fib2 = 1, fib3;
    
    printf("The first %d Fibonacci numbers are:\n", n);
    
    printf("%llu ", fib1); // First Fibonacci number
    printf("%llu ", fib2); // Second Fibonacci number
    
    for (i = 2; i < n; i++) {
        fib3 = fib1 + fib2;
        printf("%llu ", fib3);
        fib1 = fib2;
        fib2 = fib3;
    }
    
    printf("\n");
    return 0;
}

