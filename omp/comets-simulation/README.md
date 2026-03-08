# Comet Simulation (OpenMP)

Simulation of comet trajectories around the Sun using a simple gravitational model.

The program updates the position and velocity of many comets over several time steps and computes statistics such as kinetic energy and velocity histograms.

## Parallelization

The main simulation loop over the comets is parallelized using OpenMP so that different threads process different comets independently.

### comets.c
Basic OpenMP parallelization using:

- `#pragma omp parallel for`
- `reduction` for total kinetic energy
- `atomic` operations for updating the velocity histogram
- `critical` sections to safely store grazing events

### comets2.c
Optimized version of the program.

Instead of updating the histogram with `atomic` operations, each thread uses a **private histogram (`hist_private`)** and the results are combined afterwards. This reduces synchronization overhead and improves scalability.
