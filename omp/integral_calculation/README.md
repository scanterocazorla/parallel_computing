# Numerical Integration with OpenMP

Parallel computation of a numerical integral.

The main loop is parallelized using OpenMP with a reduction clause.

## Compilation

gcc -fopenmp pintegral.c -o pintegral -lm

## Execution

./pintegral <variant> [n]

variant = 1 or 2
n = number of intervals
