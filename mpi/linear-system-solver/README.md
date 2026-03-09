# Linear System Solver (MPI)

Parallel implementation of a linear system solver using LU factorization and MPI.

The program solves a system of linear equations:

A x = b

The matrix is distributed among MPI processes and the LU decomposition is computed in parallel.

## Algorithm

The program performs the following steps:

1. Generate a well-conditioned matrix **A**
2. Generate vector **b** so that the solution is known
3. Distribute the matrix rows among MPI processes
4. Compute the **LU factorization**
5. Solve the triangular systems:
   - L y = b
   - U x = y

## Parallelization

The matrix rows are distributed among processes.  
During the LU factorization, pivot rows are broadcast to all processes.

MPI operations used include:

- `MPI_Bcast`
- `MPI_Scatter`
