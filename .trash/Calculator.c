#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <assert.h>

#define M_PI 3.14159265358979323846
#define EULER_CONST 2.718281828459045235
#define NEWTON_ITERATIONS 20

//Actual functions to be used in the Calculator

double add_num(double x, double y);

double subtract_num(double x, double y);

double multiply_num(double x, double y);

double divide_num(double x, double y);

double percent_num(double x, double y);

double power(double base, double exponent);

double root(double base, double rootval);

double exp(double x);

double logarithm_e(double x);

double logarithm_10(double x);

double logarithm_2(double x);

double logarithm_user_def(double x, double log_base);

double antilogarithm(double x);

double factorial(int n);

double cos(double x);

double sin(double x);

double tan(double x);

double add_num(double x, double y)
{
    return x + y;
}

double subtract_num(double x, double y)
{
    return x - y;
}

double multiply_num(double x, double y)
{
    return x * y;
}

double divide_num(double x, double y)
{
    double result = x / y;
    return result;
}

double percent_num(double x, double y)
{
    double result = (x / y) * 100;
    return result;
}

double power(double base, double exponent)
{
    // Edge case for both base and exponent being zero
    if (base == 0 && exponent == 0)
    {
        fprintf(stderr, "Warning: 0^0 is undefined, but returning 1 as a convention.\n");
        return 1;
    }

    // Edge cases for zero base and non-zero exponent
    if (base == 0)
    {
        if (exponent > 0)
        {
            fprintf(stderr, "Warning: base being zero returns zero when the exponent is greater than zero!\n");
            return 0;
        }
        fprintf(stderr, "Error: Division by zero!\n");
        return INFINITY; // Return a large number to indicate error
    }

    // Edge case for zero exponent
    if (exponent == 0)
    {
        return 1;
    }

    // Handling negative exponents
    if (exponent < 0)
    {
        return 1 / power(base, -exponent);
    }

    // Handling infinite input of base and exponents
    if (isinf(exponent))
    {
        if (exponent > 0)
        {
            return INFINITY;
        }

        return 0;
    }
    if (isinf(base))
    {
        if (base > 0)
        {
            return INFINITY;
        }

        return NAN; // Negative infinity base with positive exponent is undefined
    }

    // Variables for calculation
    double result = 1;
    double current_base = base;
    double current_exponent = exponent;

    // Exponentiation by Squaring
    while (current_exponent >= 1)
    {
        if ((int)current_exponent % 2 == 1)
        {
            result *= current_base;
        }

        current_base *= current_base;
        current_exponent /= 2;
    }

    // Handling the fractional part of the exponent
    double fractional_part = exponent - (int)exponent;
    if (fractional_part > 0)
    {
        result *= exp(fractional_part * log(base));
    }

    return result;
}

double root(double base, double rootval)
{
    if (base == 0 && rootval <= 0)
    {
        printf("Invalid input: zero base with non-positive root.\n");
        return -1; // Indicate an error
    }
    if (rootval == 0)
    {
        printf("Invalid input: zero root.\n");
        return -1; // Indicate an error
    }
    if (base < 0 && fmod(rootval, 2) != 1)
    {
        printf("Invalid input: negative base with non-integer root.\n");
        return -1; // Indicate an error
    }

    if (fabs(base) == INFINITY || fabs(rootval) == INFINITY)
    {
        printf("Invalid input: near-infinity values are not supported.\n");
        return -1; // Indicate an error
    }

    double result = power(fabs(base), 1 / rootval);

    if (rootval < 0)
    {
        result = 1.0 / result;
    }

    return base < 0 ? -result : result;
}

double exp(double x)
{
    double sum = 1.0; // Initialize sum of series
    for (int i = NEWTON_ITERATIONS - 1; i > 0; --i)
    {
        sum = 1 + x * sum / i;
    }
    return sum;
}

double logarithm_e(double X)
{
    // Trap illegal values
    if (X <= 0)
    {
        return 0.0 / 0.0; // NaN
    }

    // Initial guess
    double guess = 1.0;
    for (int i = 0; i < NEWTON_ITERATIONS; i++)
    {
        guess = guess - (exp(guess) - X) / exp(guess);
    }

    return guess;
}

double logarithm_10(double x)
{
    if (x <= 1)
    {
        return 0.0 / 0.0;
    }

    double ln_x = logarithm_e(x);
    double ln_10 = logarithm_e(10);

    return ln_x / ln_10;
}

double logarithm_2(double x)
{
    if (x <= 1)
    {
        return 0;
    }

    double log_10_x = logarithm_10(x);
    double log_10_2 = logarithm_10(2);

    return log_10_x / log_10_2;
}

double logarithm_user_def(double x, double log_base)
{
    if (x <= 1)
    {
        return 0;
    }

    double log_10_x = logarithm_10(x);
    double log_10_b = logarithm_10(log_base);

    return log_10_x / log_10_b;
}

double antilogarithm(double x)
{
    double antilog_base = 10;
    double result = power(antilog_base, x);

    return result;
}

double factorial(int n)
{
    double result = 1.0;

    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

double cos(double x)
{

    double result = 1.0;
    double terms = 10;

    for (int i = 1; i <= terms; i++)
    {
        double term = power(x, 2 * i) / factorial(2 * i);

        if (i % 2 == 0)
        {
            result *= term;
        }
        else
    {
            result -= term;
        }
    }

    return result;
}

double sin(double x)
{
    double result = 0.0;
    double terms = 10;

    for (int i = 1; i <= terms; i++)
    {
        double term = power(x, 2 * i - 1) / factorial(2 * i - 1);

        if (i % 2 == 0)
        {
            result -= term;
        }
        else
    {
            result += term;
        }
    }

    return result;
}

double tan(double x)
{
    double cos_n = cos(x);
    double sin_n = sin(x);
    return sin_n / cos_n;
}
