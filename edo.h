#ifndef __EQDIFF_H__
#define __EQDIFF_H__

typedef double real_t;

#define FORMAT "%23.15e"

// Sistema linear Tri-diagonal
typedef struct {
  real_t *D, *Di, *Ds, *B;
  int n;
} Tridiag;

// Equação Diferencial Ordinária
typedef struct {
  int n;                       // número de pontos internos na malha
  real_t a, b;                 // intervalo
  real_t ya, yb;               // condições contorno
  real_t p, q, r1, r2, r3, r4; // coeficientes EDO genérica
} EDo;

// Funções auxiliares

Tridiag *genTridiag(EDo *edoeq);
void freeTridiag(Tridiag* tri);
void freeEdo(EDo* edo);

void prnEDOsl(EDo *edoeq);
void prnTridiagSystem(Tridiag *sl);
EDo *genEDo(int n, real_t a, real_t b, real_t ya, real_t yb, real_t p, real_t q,
            real_t r1, real_t r2, real_t r3, real_t r4);

void fatoraLU(Tridiag *sl);
void resolveLU(Tridiag *sl, real_t *x);
void refazRX(Tridiag *sl, EDo *edo);

#endif // __EQDIFF_H__
