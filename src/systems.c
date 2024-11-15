#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "systems.h"
#include "matrix.h"
#include "vector.h"

vector* multiply_matrix_vector(matrix* m,vector* v){
  if((m->width != v->size && v->transposed == VECTOR)|| (m->length != v->size && v->transposed == TRANSPOSED_VECTOR) ){
    printf("Impossible matrix and vector multiplication\n");
    exit(1);
  }
  vector* ans = init_vector(m->length);
  if (v->transposed == VECTOR){
  ans->transposed = VECTOR;
  for (int i = 0; i < m->length; i++){
    for (int j = 0; j < m->width; j++){
      ans->elems[i] += (v->elems[j])*(m->elems[i][j]);
    }
   }
  return ans;
  }
  ans->transposed = TRANSPOSED_VECTOR;
  for (int i = 0; i < m->length; i++){
    for (int j = 0; j < m->width; j++){
      ans->elems[j] += (v->elems[i])*(m->elems[i][j]);
    }
   }
  return ans;
}

matrix* gaussian_elim(matrix* m){ // applies gaussian elimination to determine inverse of matrix m;
  matrix* l_matrix;
  copy_matrix(l_matrix, m);
  matrix* r_matrix = identity(m->width);
  int is_invertible = 1;
  int column = 0;

  while (column != m->width && is_invertible){
    if(l_matrix->elems[column][column] == 0){
      int i = 0;
      while(i<m->width){
        if(l_matrix->elems[i][column]){
          sum_column_to_column(l_matrix,i,column,1);
          sum_column_to_column(r_matrix,i,column,1);
          break;
        }
        i++;
      }
      if(i == m->width){
        is_invertible = 0;
        break;
      }
    }
    for(int i = 0; i < m->width; i++){
      if(i==column){
        continue;
      }
      if(l_matrix->elems[i][column] == 0){
        double lambda = l_matrix->elems[i][column]/l_matrix->elems[column][column];
        sum_column_to_column(l_matrix,i,column,lambda);
        sum_column_to_column(r_matrix,i,column,lambda);
      }
      if (l_matrix->elems[column][i] == 0){
        double lambda = l_matrix->elems[column][i]/l_matrix->elems[column][column];
        sum_column_to_column(l_matrix,i,column,lambda);
        sum_column_to_column(r_matrix,i,column,lambda);
      }
    }
  }
  if(is_invertible){
    return r_matrix;
  }
  printf("Matrix not invertible!\n");
  exit(0);
}

vector* solve_system_gaussian(matrix* A, vector* b){
  matrix* inverted_matrix = gaussian_elim(A);
  vector* ans = multiply_matrix_vector(inverted_matrix,b);
  return ans;
}

