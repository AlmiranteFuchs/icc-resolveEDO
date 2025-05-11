#include "edo.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Pontos internos da malha
  int n = 0;
  scanf("%d", &n);

  // Intervalo
  real_t a, b;
  scanf("%lf %lf", &a, &b);

  // Valores de contorno
  real_t ya, yb;
  scanf("%lf %lf", &ya, &yb);

  // Coeficientes p e q
  real_t p, q;
  scanf("%lf %lf", &p, &q);

  // TODO: while scanf make new edos for r1, r2, r3, r4
  // Coeficientes rn
  real_t r1, r2, r3, r4;
  scanf("%lf %lf %lf %lf", &r1, &r2, &r3, &r4);

  // printf("n = %d\n", n);
  // printf("Intervalo: a = %.15lf, b = %.15lf\n", a, b);
  // printf("Condicoes de contorno: y(a) = %.15lf, y(b) = %.15lf\n", ya, yb);
  // printf("Coeficientes: p = %.15lf, q = %.15lf\n", p, q);
  // printf("r(x) = r1*x + r2*x^2 + r3*cos(x) + r4*e^x\n");
  // printf("Coeficientes: r1 = %.15lf, r2 = %.15lf, r3 = %.15lf, r4 =
  // %.15lf\n",
  //        r1, r2, r3, r4);

  // Nova EDO
  EDo *edo_test = genEDo(n, a, b, ya, yb, p, q, r1, r2, r3, r4);

  // TEST
  Tridiag *tri = genTridiag(edo_test);
  prnTridiagSystem(tri);
  fatoraLU(tri);
  prnTridiagSystem(tri);

  real_t *x = (real_t *)calloc(tri->n, sizeof(real_t));
  resolveLU(tri, x);
  for (int i=0; i < n; i++) {
    printf(FORMAT, x[i]);
  }
  // TEST

  // prnEDOsl(edo_test);
}