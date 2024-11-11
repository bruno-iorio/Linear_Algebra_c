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
  allocated_matrix->elems = (int**) malloc(sizeof(int*)*length); 

  for (int i = 0; i < length; i++) {
    allocated_matrix->elems[i] = (int*) malloc(sizeof(int)*width);
    memset(allocated_matrix->elems[i], 0, i);
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

matrix* multiply_matrix(matrix* m1,matrix* m2){ // Not cache friendly algo to multply matrix
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

void copy(matrix* m1,matrix* m2){
  memcpy(m2, m1, sizeof(matrix));
}

matrix* transpose(matrix* m1){
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



