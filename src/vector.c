#include "vector.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

vector* init_vector(int size){
  if (size <= 0){
    printf("Error: vector size smaller than 0\n");
    exit(1);
  }
  vector* allocated_vector = (vector*) malloc(sizeof(vector));
  allocated_vector->size = size;
  allocated_vector->elems = (double*) malloc(sizeof(double)*size);
  allocated_vector->transposed = VECTOR;
  memset(allocated_vector, 0, size);
  return allocated_vector;
}

void free_vector(vector* v){
  if (!v){
    printf("ERROR: impossible to free vector\n");
    exit(1);
  }
  free(v->elems);
  free(v);
}

void copy_vector(vector* v_from, vector* v_to){
  if (!v_from || !v_to){
    printf("ERROR: impossible to copy vector");
  }
  v_to->transposed = v_from->transposed;
  v_to->size = v_from->size;
  v_to->elems = realloc(v_to->elems, sizeof(double)*v_to->size);
  memcpy(v_to->elems, v_from->elems, sizeof(double)*v_from->size);
}

vector* sum_vector(vector* v1,vector* v2){
  if(v1->size != v2->size || (v1->transposed != v2->transposed)){
    printf("Error: summing vectors with different dimentions\n");
    exit(0);
  }
  vector* sum_vector = init_vector(v1->size);
  for (int i = 0; i < v1->size; i++){
    sum_vector->elems[i] = v1->elems[i] + v2->elems[i];
  }
  return sum_vector;
}

void transpose_vector(vector* v){
  if(v->size == 1) return;
  if(v->transposed) v->transposed = VECTOR;
  else v->transposed = TRANSPOSED_VECTOR;
}

vector* escalar_multiplication_vector(vector* v, double lambda){
  vector* ans;
  copy_vector(v,ans);
  for(int i = 0; i < ans->size; i++) ans->elems[i] *= lambda;
  return ans;
}

