# Matrix–Vector Iteration (MPI)

This program performs repeated matrix–vector operations in parallel using MPI.

Given a matrix **M** and vectors **x** and **v**, the following operation is repeated several times:

x ← Mx + v

After the iterations, the program computes the 1-norm of the resulting vector.

## Implementations

Two parallel versions are included:

### mxv1.c
- The matrix is distributed **by blocks of rows** across processes.
- Each process computes a fragment of the resulting vector.
- The full vector is reconstructed using collective communication.

### mxv2.c
- The matrix is distributed **by blocks of columns**.
- Each process computes a partial contribution to the result.
- The final vector is obtained by summing all contributions.

Both implementations use MPI collective operations such as:
- `MPI_Scatter`
- `MPI_Bcast`
- `MPI_Allgather`
- `MPI_Reduce`
