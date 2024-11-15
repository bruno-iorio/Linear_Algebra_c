#include "matrix.h"
#include "vector.h"
#include "systems.h"
#include <stdio.h>

int main(){
  matrix* m = init_matrix(2,2);
  m->elems[0][0] = 4;
  m->elems[0][1] = 2;
  m->elems[1][0] = -1;
  m->elems[1][1] = 5;
  print_matrix(m);
  
  vector* v = init_vector(2);
  v->elems[0] = 1;
  v->elems[1] = 2;

  vector* ans  = solve_system_gaussian(m,v);
  free_matrix(m);
  free_vector(v);
  free_vector(ans);
  return 0;
}
