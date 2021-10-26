#include <stdlib.h>
#include "matmul.h"

////////////////// NOTE //////////////////
// NOTE:
// C = A * B
// C          Maxtix containing the result of the multiplciation
// A          Matrix A
// aHeight    Matrix A height
// aWidth    Matrix A width
// B          Matrix B
// bHeight    Matrix B height
// bWidth     Matrix B width


Matrix AllocateMatrix2(int height, int width, int init);
void matmul(float*, const float*, const float*, unsigned int, unsigned int, unsigned int);


/* Matrix Multiplication Function */
void matmul(float* C, const float* A, const float* B, unsigned int aHeight, unsigned int aWidth, unsigned int bWidth) {
    for (unsigned int i = 0; i < aHeight; i++) {
        for (unsigned int j = 0; j < bWidth; j++) {
            double sum = 0;
            for (unsigned int k = 0; k < aWidth; k++) {
                double first = A[aWidth * i + k];
                double second = B[bWidth * j + k];
                sum += first * second;
            }
            C[bWidth * i + j] = (float)sum;
        }
    }
}


/* Allocate a matrix with inputed height and width */
/* Optimized to be column-major order */
Matrix AllocateMatrix2(int height, int width)
{
    Matrix X;
    X.width = width;
    X.height = height;
    X.elements = NULL;
    int matrixSize = X.width * X.height;

    X.elements = (float*) malloc(matrixSize * sizeof(float));

    /* This is a column-major allocation and initialization */
    for(unsigned int i = 0; i < X.height; i++) {
        for(unsigned int j = 0; j < X.width; j++) {
            X.elements[X.height * j + i] = (rand() / (float)RAND_MAX);
        }
    }
    return X;
}	

