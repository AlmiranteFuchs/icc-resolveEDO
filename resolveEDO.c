#include "edo.h"
#include "utils.h"
#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  fesetround(FE_DOWNWARD);

  int n = 0; // Pontos internos da malha
  scanf("%d", &n);

  real_t a, b; // Intervalo
  scanf("%lf %lf", &a, &b);

  real_t ya, yb; // Valores de contorno
  scanf("%lf %lf", &ya, &yb);

  real_t p, q; // Coeficientes p e q
  scanf("%lf %lf", &p, &q);

  real_t r1, r2, r3, r4; // Coeficientes rn
  scanf("%lf %lf %lf %lf", &r1, &r2, &r3, &r4);

  EDo *edo_test = genEDo(n, a, b, ya, yb, p, q, r1, r2, r3, r4); // Cria a EDO

  Tridiag *tri = genTridiag(edo_test); // Cria a tridiagonal

  real_t *x = (real_t *)calloc(tri->n, sizeof(real_t)); // Vetor solução

  // Fatora LU para o processamento
  fatoraLU(tri);

  // Processamento
  do {
    // Valores atualizados depois da primeira iteração
    edo_test->r1 = r1;
    edo_test->r2 = r2;
    edo_test->r3 = r3;
    edo_test->r4 = r4;

    // Re calcula B para novos valores de R(X)
    refazRX(tri, edo_test);

    prnEDOsl(edo_test);
    rtime_t t0 = timestamp();
    resolveLU(tri, x);
    rtime_t t1 = timestamp();

    printf("\n");

    for (int i = 0; i < n; i++) {
      printf(FORMAT, x[i]);
    }
    printf("\n");
    printf("  %.8e", t1 - t0);
    printf("\n\n");

  } while (scanf("%lf %lf %lf %lf", &r1, &r2, &r3, &r4) == 4);
}