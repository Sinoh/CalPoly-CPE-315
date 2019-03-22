/* Main file for matmul */
/* Maxtrix Multiplication */

/* Includes source files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matmul.h"

void matmul(float*, const float*, const float*, unsigned int, unsigned int, unsigned int);
void WriteResults(Matrix);
Matrix AllocateMatrix(int height, int width, int init);
Matrix AllocateMatrix2(int height, int width);


/* Main Program */
int main(int argc, char** argv) {

    // Matricies
    Matrix X;
    Matrix Y;
    Matrix Z;
    
    /* Keeps the matrices the same between runs */
    srand(1);

    /* Check command line for arguements */
    if(argc == 1) {
        /* Allocate and initialize the matrices */
        X  = AllocateMatrix(MATRIX_SIZE, MATRIX_SIZE, 1);
        Y  = AllocateMatrix2(MATRIX_SIZE, MATRIX_SIZE);
        Z  = AllocateMatrix(MATRIX_SIZE, MATRIX_SIZE, 0);
    } else {
        printf("Wrong number of arguements\n");
        printf("Usage: matmul > outfile\n");
        return 1;
    }
    
    /* Perform maxtrix multiplication */
    matmul(Z.elements, X.elements, Y.elements, xHeight, xWidth, yWidth);
    /* Write result to stdout */
    WriteResults(Z);

    // Free the matrices
    free(X.elements);
    X.elements = NULL;
    free(Y.elements);
    Y.elements = NULL;
    free(Z.elements);
    Z.elements = NULL;
    return 0;
    }


/* Allocate a matrix with inputed height and width */
/*	init == 0, initialize to zeroes */
/*	init == 1, initialize to randoms */
Matrix AllocateMatrix(int height, int width, int init) {
    Matrix X;
    X.width = width;
    X.height = height;
    X.elements = NULL;
    int matrixSize = X.width * X.height;

    X.elements = (float*) malloc(matrixSize * sizeof(float));

    for(unsigned int i = 0; i < X.height * X.width; i++) {
        if (init == 0) {
            X.elements[i] = (0.0f);
        }else {
            X.elements[i] = (rand() / (float)RAND_MAX);
        }
    }
    return X;
}	


// Write matrix to file
void WriteResults(Matrix X) {
    for (unsigned int i = 0; i < X.height; i++){
        for (unsigned int j = 0; j < X.width; j++) 
        fprintf(stdout, "%.2f ", X.elements[X.width * i + j]);
        fprintf(stdout, "\n"); 
    }
}
