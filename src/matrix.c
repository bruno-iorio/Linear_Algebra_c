#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



matrix* init_matrix(int length, int width){ // allocate memory to matrix
  if ( length <= 0 || width <= 0){
    printf("Error: Allocating matrix with 0 length or width\n");
    exit(1);
  }

  matrix* allocated_matrix = (matrix*) malloc(sizeof(matrix));
  allocated_matrix->length = length;
  allocated_matrix->width = width;
  allocated_matrix->elems = (double**) malloc(sizeof(double*)*length); 

  for (int i = 0; i < length; i++) {
    allocated_matrix->elems[i] = (double*) malloc(sizeof(double)*width);
    memset(allocated_matrix->elems[i], 0, width);
  }
  return allocated_matrix;
}

void free_matrix(matrix* matrix){ // free allocated matrix
  if (!matrix){
    printf("Error: impossible matrix freeing matrix\n");
    exit(1);
  }
  for(int i = 0 ; i < matrix->length; i++){
    free(matrix->elems[i]);
  }
  free(matrix->elems);
  free(matrix);
}

void print_matrix(matrix* m){
  if(!m){
    printf("ERROR: Printing matrix that is not initialized!\n");
    exit(1);
  }
  for(int i = 0; i < m->length; i++){
    for(int j = 0; j < m->width; j++){
      printf("%f ", m->elems[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}

matrix* multiply_matrix(matrix* m1,matrix* m2){ // Not cache friendly algo to multiply matrix
  if (m1->width != m2-> length || !m1 || !m2){
    printf("Error: impossible matrix multiplication\n");
    exit(1);
  }
  matrix* mult_matrix = init_matrix(m1->length,m2->width);
  for (int i = 0; i < m1->length; i++){
    for (int j = 0; j < m2->width; j++ ){
      int t = 0;
      for (int k = 0; k < m1->width; k++){
        t += m1->elems[i][k] * m2->elems[k][j]; 
      }
      mult_matrix->elems[i][j] = t;
    }
  }
  return mult_matrix;
}

void copy_matrix(matrix* m_from,matrix* m_to){ //copy matrix from one to the other
  m_to->width  = m_from->width;
  m_to->length = m_from->length;

  m_to->elems = (double**) realloc(m_to->elems,(m_to->length)*sizeof(double*)); 
  for (int i = 0 ; i < m_to->length ; i++){
    m_to->elems[i] = (double*) realloc(m_to->elems[i],sizeof(double)*(m_to->width));
    memcpy(m_to->elems[i],m_from->elems[i],sizeof(double)*(m_from->width));
  }
}

matrix* transpose(matrix* m1){ // transpose matrix
  if (!m1){
    printf("Error: impossible matrix transpose");
    exit(1);
  }
  matrix* m_transpose = init_matrix(m1->width, m1->length);
  for (int i = 0 ; i < m1->length; i++){
    for (int j = 0 ; j < m1->width ; j++){
      m_transpose->elems[j][i] = m1->elems[i][j];
    }
  }
  return m_transpose;
}

matrix* escalar_multiplication_matrix(matrix* m, double lambda){
  matrix* ans;
  copy_matrix(m,ans);
  for(int i = 0; i < m->length; i++){
    for (int j = 0; j < m->width; j++){
      ans->elems[i][j] *= lambda;
    }
  }
  return ans;
}

matrix* sum_matrix(matrix* m1, matrix* m2){ //compute the sum of two matrices
  if (m1->length != m2->length || m1->width != m2->width){
    printf("Error: impossible to sum matrices!");
    exit(1);
  }
  matrix* matrix_sum = init_matrix(m1->length,m1->width);
  for (int i = 0; i < m1->length; i++){
    for (int j = 0; j < m1->width; j++){
      matrix_sum->elems[i][j] = m1->elems[i][j] + m2->elems[i][j];
    }
  }
  return matrix_sum;
}

matrix* identity(int length){ //create an identity matrix
  matrix* m = init_matrix(length,length);
  for(int i = 0; i < length; i++ ){
    m->elems[i][i] = 1;
  }
  return m;
}
void sum_line_to_line(matrix* m1, int line1,int line2,double lambda){ // sum line2 to line1
  for (int i = 0; i < m1->width; i++){
    m1->elems[i][line1] += lambda*(m1->elems[i][line2]);
  }
}
void sum_column_to_column(matrix* m1, int column1,int column2,double lambda){ // sum column2 to column1
  for (int i = 0; i < m1->width; i++){
    m1->elems[column1][i] += lambda*(m1->elems[column2][i]);
  }
}

