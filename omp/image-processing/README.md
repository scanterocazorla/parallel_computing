# Image Filtering with OpenMP

This program applies a smoothing filter to a PPM image using OpenMP for parallelization.

The filter computes a weighted average of neighboring pixels within a configurable radius and applies it multiple times to the image.

## Parallelization

The main image processing loop is parallelized using:

#pragma omp parallel for

Each thread processes different rows of the image independently.

## Input / Output

Input image: `peppers.ppm`  
Output image: `peppers-fil.ppm`

The program will:

1. Read the input image
2. Apply the filter several times
3. Save the processed image
4. Print the execution time
