#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <floats.h>

int add_num(double x, double y, int ret_val)
{
	if (x == INFINITY && x > 0 )
	{
		return 1;
	}

	if (x == INFINITY && x < 0 )
	{
		return 1;
	}

}

int subtract_num(double x, double y, int ret_val);

int multiply_num(double x, double y, int ret_val);

int divide_num(double x, double y, int ret_val);

int percent_num(double x, double y, int ret_val);

int power(double base, double exponent, int ret_val);

int root(double base, double rootval, int ret_val);

int exp(double x, int ret_val);

int logarithm_e(double x, int ret_val);

int logarithm_10(double x, int ret_val);

int logarithm_2(double x, int ret_val);

int logarithm_user_def(double x, double log_base, int ret_val);

int antilogarithm(double x, int ret_val);

int factorial(int n, int ret_val);

int cos(double x, int ret_val);

int sin(double x, int ret_val);

int tan(double x, int ret_val);
