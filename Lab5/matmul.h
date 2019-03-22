#ifndef MATMUL_H
#define MATMUL_H

// Matrix Size
#define MATRIX_SIZE 1024

// Dimension of each matrix
#define xWidth MATRIX_SIZE  // Matrix X width
#define xHeight MATRIX_SIZE // Matrix X height
#define yWidth MATRIX_SIZE  // Matrix Y width
#define yHeight MATRIX_SIZE // Matrix Y height
#define zWidth MATRIX_SIZE  // Matrix Z width 
#define zHeight MATRIX_SIZE // Matrix Z height 


// Structure declaration for Matrices
typedef struct {
    unsigned int width;     //width of the matrix
    unsigned int height;    //height of the matrix
    float* elements;        //Pointer to the first element of the matrix
} Matrix;

#endif
