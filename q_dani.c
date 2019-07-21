#include <stdio.h>
// q 3 from dani's marathon


int print_digits(int n) {
    if (n <= 0) {
        return 0;
    }
    int sum = print_digits(n/10);
    printf("%d ", n%10);

    return n%10 + sum;
}

int main() {
    int n = 1360988;
    printf("sum of %d is %d\n", n, print_digits(n));
    return 0;
}

