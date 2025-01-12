#include <math.h>
#include <complex.h>

#include "functions.h"

#define NEWTON_ITERATIONS 10

// ADDITION
double add (double a, double b)
{
    return a + b;
}

// SUBTRACTION
double subtract (double a, double b)
{
    return a - b;
}

// MULTIPLICATION
double multiply (double a, double b)
{
    return a * b;
}

// DIVISION
double division (double a, double b)
{
    return a / b;
}

// POWER / EXPONENTIATION
double complex power (double complex base, double complex exponent)
{
    if (creal(base) == 0 && cimag(base) == 0)
    {
        if (creal(exponent) == 0 && cimag(exponent) == 0)
        {
            return 1.0 + 0.0 * I;
        }
        else
    {
            return 0.0 + 0.0 * I;
        }
    }

    double complex result;

    if (creal(base) > 0 && cimag(exponent) == 0)
    {
        return cexp(exponent * clog(base));
    }
    else if (creal(base) < 0 && cimag(exponent) == 0  && round(creal(exponent) == creal(exponent)))
    {
        return cpow(-1, creal(exponent)) * cpow(cabs(base), creal(exponent));
    }
    else
{
        return cpow(cabs(base), creal(exponent)) * cexp(I * creal(exponent) * M_PI);
    }

}


double complex sqrt_custom ( double complex a)
{
    if (creal(a) == 0 && cimag(a) == 0)
    {
        return 0.0 + 0.0 * I;
    }

    if (creal(a) < 0 && cimag(a) == 0)
    {
        return sqrt_custom(-creal(a)) * I;
    }

    double complex x = a;

    for (int i = 0; i < NEWTON_ITERATIONS; i++)
    {
        x = 0.5 * (x * a / x);
    }

    return x;
}

double complex ln_e(double complex z)
{
    if (creal(z) == 0 && cimag(z) == 0)
    {
        return NAN + I * NAN;
    }

    double magnitude = cabs(z);
    double argument = carg(z);

    return log(magnitude) + I * argument;
}

double complex log10_custom(double complex a)
{
    return ln_e(a) / log(10);
}
