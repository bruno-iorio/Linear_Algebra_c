#ifndef VECTOR_H
#define VECTOR_H

#define TRANSPOSED_VECTOR 1
#define VECTOR 0

typedef struct vector{
  int size;
  double* elems;
  int transposed;
} vector;

vector* sum_vector(vector*,vector*);
vector* escalar_multiplication_vector(vector*, double);
void tranpose_vector(vector*);

vector* init_vector(int);
void copy_vector(vector*,vector*);
void free_vector(vector*);


#endif // VECTOR_H
