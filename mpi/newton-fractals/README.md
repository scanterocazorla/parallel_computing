# Newton Fractal (MPI)

This program generates a Newton fractal using the Newton–Raphson method to find the roots of complex polynomials.

The image is computed in parallel using MPI. The master process distributes rows of the image to worker processes, which compute the Newton iterations for each pixel.

## Description

Each pixel represents the number of iterations required for the Newton method to converge starting from a complex point.

Different polynomial functions can be selected, producing different fractal patterns.

## Parallelization

The computation of the image is distributed among MPI processes using a master–worker approach:

- Process 0 acts as the **master**
- Worker processes compute rows of the image
- Rows are sent back to the master to assemble the final image

Dynamic work distribution is used to balance the workload among processes.
