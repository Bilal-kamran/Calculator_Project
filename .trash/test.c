#include <stdio.h>
#include <complex.h>
#include <math.h>

double complex ln_e(double complex z)
{
    if (cimag(z) == 0 && creal(z) == 0)
    {
        return NAN + I * NAN;
    }

    double magnitude = sqrt(creal(z) * creal(z) + cimag(z) * cimag(z));
    double argument = atan2(cimag(z), creal(z));

    return log(magnitude) + I * argument;
}

int main()
{
    // Define test cases
    double complex test1 = 1.0 + 1.0 * I;
    double complex test2 = -1.0 + 0.0 * I;
    double complex test3 = 0.0 + 2.0 * I;
    double complex test4 = 0.0 + 0.0 * I;
    double complex test5 = 5.0 + 0.0 * I;

    // Test and print results
    printf("ln(1 + i): %lf + %lfi\n", creal(ln_e(test1)), cimag(ln_e(test1)));
    printf("ln(-1): %lf + %lfi\n", creal(ln_e(test2)), cimag(ln_e(test2)));
    printf("ln(0 + 2i): %lf + %lfi\n", creal(ln_e(test3)), cimag(ln_e(test3)));
    printf("ln(0): %lf + %lfi\n", creal(ln_e(test4)), cimag(ln_e(test4)));
    printf("ln(5): %lf + %lfi\n", creal(ln_e(test5)), cimag(ln_e(test5)));
    return 0;
}

