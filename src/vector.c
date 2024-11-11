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
  allocated_vector->elems = (int*) malloc(sizeof(int)*size);
  memset(allocated_vector, 0, size);
  return allocated_vector;
}

void free_vector(matrix* m){
  if (!m){
    printf("impossible to free");
    exit(1);
  }
  free(m->elems);
  free(m);
}

