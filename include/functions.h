#ifndef FUNCTION_H
#define FUNCTION_H

// Basic Arithmetic Functions
double add(double a, double b);          // Addition
double subtract(double a, double b);    // Subtraction
double multiply(double a, double b);    // Multiplication
double divide(double a, double b);      // Division (handle divide by zero)

// Exponential and Logarithmic Functions
double complex power(double complex base, double complex exp);  // Exponentiation (handles all cases)
double complex sqrt_custom(double complex a);           // Square Root
double complex ln_e(double complex z);                    // Natural Logarithm
double complex log10_custom(double complex a);          // Logarithm Base 10
double log_base(double a, double base); // Logarithm Base N

// Trigonometric Functions
double sin_custom(double angle);        // Sine
double cos_custom(double angle);        // Cosine
double tan_custom(double angle);        // Tangent (handle undefined points)
double arcsin(double x);                // Inverse Sine
double arccos(double x);                // Inverse Cosine
double arctan(double x);                // Inverse Tangent
double sinh_custom(double x);           // Hyperbolic Sine
double cosh_custom(double x);           // Hyperbolic Cosine
double tanh_custom(double x);           // Hyperbolic Tangent

// Complex Number Functions
double complex complex_power(double complex z, double complex w); // Complex Exponentiation
double complex complex_conjugate(double complex z);               // Complex Conjugate
double complex_magnitude(double complex z);                       // Magnitude of Complex Number
double complex_phase(double complex z);                           // Phase (Argument) of Complex Number
// Geometric Functions
double abs_custom(double a);             // Absolute Value
long long factorial(int n);              // Factorial (integer input)

// Advanced Mathematical Functions
int gcd(int a, int b);                   // Greatest Common Divisor
int lcm(int a, int b);                   // Least Common Multiple
int mod(int a, int b);                   // Modulus (handle divide by zero)
double n_root(double a, double n);       // n-th Root (e.g., cube root)

// Statistical Functions
double mean(double values[], int size);       // Mean (Average)
double median(double values[], int size);     // Median
double mode(double values[], int size);       // Mode
double variance(double values[], int size);   // Variance
double stddev(double values[], int size);     // Standard Deviation

// Programming/Logical Functions
int and_operation(int a, int b);        // AND
int or_operation(int a, int b);         // OR
int xor_operation(int a, int b);        // XOR
int not_operation(int a);               // NOT
int shift_left(int a, int n);           // Shift Left
int shift_right(int a, int n);          // Shift Right

// Specialized Functions
double e_constant();                    // Euler’s Number
double pi_constant();                   // Pi Constant
double random_number(double min, double max); // Random Number Generator

// Memory Functions
void store_memory(double value);        // Store Value in Memory
double recall_memory();                 // Recall Value from Memory
void clear_memory();                    // Clear Memory

#endif
