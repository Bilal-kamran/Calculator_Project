/*
 *	
 * */

#include <math.h>
#include <limits.h>
#include <float.h>

int divide_cases(double x, double y)
{
	if (y == 0)
	{
		return x > 0 ? INFINITY : -INFINIY;
	}
}

int percent_cases(double x, double y);

int power_cases(double base, double exponent);

int root_cases(double base, double rootval);

int exp_cases(double x);

int logarithm_e_cases(double x);

int logarithm_10_cases(double x);

int logarithm_2_cases(double x);

int logarithm_user_def_cases(double x, double log_base);

int antilogarithm_cases(double x);

int factorial_cases(int n);

int cos_cases(double x);

int sin_cases(double x);

int tan_cases(double x);
