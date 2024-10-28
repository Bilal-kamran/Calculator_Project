#include "Calculator.c"

int main()
{
    double values[] = {1.0, INFINITY, NAN, DBL_MAX, -DBL_MAX};
    double operands[] = {2.0, 3.0, 4.0, 1.0, -1.0};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
    {
        double add_result = add_num(values[i], operands[i]);
        if (add_result != -1)
        {
            printf("The result of adding %.2f to %.2f is %.2f\n", operands[i], values[i], add_result);
        }

        double sub_result = subtract_num(values[i], operands[i]);
        if (sub_result != -1)
        {
            printf("The result of subtracting %.2f from %.2f is %.2f\n", operands[i], values[i], sub_result);
        }

        double mul_result = multiply_num(values[i], operands[i]);
        if (mul_result != -1)
        {
            printf("The result of multiplying %.2f by %.2f is %.2f\n", values[i], operands[i], mul_result);
        }

        double div_result = divide_num(values[i], operands[i]);
        if (div_result != -1)
        {
            printf("The result of dividing %.2f by %.2f is %.2f\n", values[i], operands[i], div_result);
        }

        double perc_result = percent_num(values[i], operands[i]);
        if (perc_result != -1)
        {
            printf("The percentage of %.2f over %.2f is %.2f%%\n", values[i], operands[i], perc_result);
        }
    }

    return 0;
}