#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector{
  int size;
  int* elems;
} vector;

vector* init_vector(int);
void free_vector(vector*);

#endif // VECTOR_H
