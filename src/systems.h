#ifndef SYSTEMS_H
#define SYSTEMS_H

#include "matrix.h"
#include "vector.h"

vector* multiply_matrix_vector(matrix*,vector*);
matrix* gaussian_elim(matrix*);
vector* solve_system_gaussian(matrix*,vector*);

#endif //SYSTEMS_H
