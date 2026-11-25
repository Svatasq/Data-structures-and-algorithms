#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x = 1.0 / 3.0;
    double pi = 3.1415;
    double product = 3.0;
    double sum, numerator, denominator, factor;

    long long operations = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum = 0.0;

        for (int j = 1; j <= i; j++) {
            sum += 2 * j - 1;
            operations += 3;
        }

        numerator = 8 * x * x;
        operations += 2;

        denominator = x * x - pi * pi * sum;
        operations += 4;

        factor = 1 + numerator / denominator;
        operations += 2;

        product *= factor;
        operations++;
    }

    double exact = sin(3 * x) / sin(x);

    printf("\nApproximation: %.7f\n", product);
    printf("Operations:   %lld\n", operations);

    return 0;
}
