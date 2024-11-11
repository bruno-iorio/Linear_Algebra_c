
#ifndef MATRIX_H 
#define MATRIX_H
#include<stdlib.h>

typedef struct matrix {
  int length;
  int width;
  int** elems;
  
} matrix;

matrix* init_matrix(int,int);
matrix* multiply_matrix(matrix*,matrix*);
matrix* transpose(matrix*);
void free_matrix(matrix*);
void copy(matrix,matrix);
#endif // MATRIX_H
