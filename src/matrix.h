
#ifndef MATRIX_H 
#define MATRIX_H

typedef struct matrix {
  int length;
  int width;
  double** elems;
  
} matrix;

//real operations
matrix* identity(int);
matrix* multiply_matrix(matrix*,matrix*);
matrix* transpose_matrix(matrix*);
matrix* sum_matrix(matrix*, matrix*);
void sum_line_to_line(matrix*,int,int,double);
void sum_column_to_column(matrix*,int,int,double);
matrix* escalar_multiplication_matrix(matrix*,double);

// technical functions
matrix* init_matrix(int,int);
void print_matrix(matrix*);
void free_matrix(matrix*);
void copy_matrix(matrix*,matrix*);

#endif // MATRIX_H
