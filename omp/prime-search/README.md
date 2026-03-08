# Counting Prime Numbers (OpenMP)

This program counts the number of prime numbers between 1 and a given limit.

The computation is parallelized using OpenMP by distributing the candidate numbers
among multiple threads.

## Parallelization

The loop that tests numbers for primality is parallelized using:

#pragma omp parallel for reduction(+:n)

A reduction clause is used to safely accumulate the number of primes found.

## Compilation

gcc -fopenmp primo_numeros.c -o primo_numeros -lm

## Execution

./primo_numeros

# Largest Prime Search (OpenMP)

This program searches for the largest prime number that can be represented
using an unsigned long long integer.

The algorithm checks numbers starting from the maximum possible value and
tests them for primality.

## Parallelization

The primality test is parallelized using OpenMP threads that divide the
search space among themselves.

Each thread tests a subset of possible divisors.

## Compilation

gcc -fopenmp primo_grande.c -o primo_grande -lm

## Execution

./primo_grande
