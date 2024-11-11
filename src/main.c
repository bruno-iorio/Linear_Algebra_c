#include "matrix.h"
#include <stdio.h>

int main(){
  matrix* m = init_matrix(5,5);
  m->elems[0][0] = 7;
  m->elems[1][1] = 7;
  m->elems[2][2] = 7;
  m->elems[3][3] = 7;
  m->elems[4][4] = 7;
  matrix* m2 = init_matrix(5,5);
  m2->elems[0][0] = 1;
  m2->elems[1][1] = 2;
  m2->elems[2][2] = 3;
  m2->elems[3][3] = 4;
  m2->elems[4][4] = 5;
  matrix* m3  = multiply_matrix(m,m2);
  for (int i = 0; i < 5; i++){
    for (int j = 0 ; j < 5 ; j++){
      printf("%d ",m3->elems[i][j]);
    }
    putchar('\n');
  }
  free_matrix(m);
  free_matrix(m2);
  free_matrix(m3);
  return 0;
}
