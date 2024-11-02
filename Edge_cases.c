/* these are the return values used in the edge cases:
 * return 100 --> means exceeded DBL_MAX
 * return -100 --> means exceeded negative DBL_MAX
 * return 200 --> means exceeded DBL_MIN
 * return -200 --> means exceeded negative -DBL_MIN
 * return -2 --> means both values are same but one is oppisite in sign (ONLY IN "add_cases")
 * return INFINITY --> means both values are DBL_MAX and will result in an almost INFINITY (FOR NOW IN "add_cases")
 * return -INFINITY --> means both values are -DBL_MAX and will result in an almost -INFINITY (FOR NOW IN "add_cases")
 * return NAN --> means any one of both vaules is not a number*/

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <floats.h>

int add_cases(double x, double y)
{
	if (x > DBL_MAX || y > DBL_MAX)
	{
		return 100;
	}
	else if (x > -DBL_MAX || y > -DBL_MAX)
	{
		return -100;
	}
	else if (x < DBL_MIN || y < DBL_MIN)
	{
		return 200;
	}
	else if (x < -DBL_MIN || y < -DBL_MIN)
	{
		return -200;
	}
	else if ((x == y) && (x < 0 || y < 0))
	{
		return -2;
	}
	else if (x == DBL_MAX && y == DBL_MAX)
	{
		return INFINITY;
	}
	else if (x == -DBL_MAX && y == -DBL_MAX)
	{
		return -INFINITY;
	}
	else if (x == NAN || y == NAN)
	{
		return NAN;
	}

}

int subtract_cases(double x, double y)

int multiply_cases(double x, double y);

int divide_cases(double x, double y);

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
