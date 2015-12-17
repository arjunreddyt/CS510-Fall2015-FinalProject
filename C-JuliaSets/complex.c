#include <stdio.h>
#include <assert.h>
#include "complex.h"

COMPLEX mul(const COMPLEX *a, const COMPLEX *b)//multiply two complex numbers
{
  COMPLEX r;

  r.real = a->real * b->real - a->imag * b->imag;
  r.imag = a->imag * b->real + a->real * b->imag;

  printf("\n%.2Lf + %.2Lfi\n\n", r.real, r.imag);

  return r;
}

COMPLEX square(const COMPLEX *k)//square two complex numbers
{
  COMPLEX r;

  r.real = (k->real * k->real) - (k->imag * k->imag);
  r.imag = 2 * (k->real * k->imag);

  printf("\n%.2Lf + %.2Lfi\n\n", r.real, r.imag);

  return r;
}

COMPLEX add(const COMPLEX *a, const COMPLEX *b)//add two complex numbers
{
  COMPLEX r;

  r.real = a->real + b->real;
  r.imag = a->imag + b->imag;

  printf("\n%.2Lf + %.2Lfi\n\n", r.real, r.imag);

  return r;
}

COMPLEX juliamap(const COMPLEX *z, const COMPLEX *c)//apply juliamap to two complex numbers
{
  COMPLEX r;

  r.real = ((z->real * z->real) - (z->imag * z->imag) + c->real);
  r.imag = 2 * z->real * z->imag + c->imag;

  printf("\n%.2Lf + %.2Lfi\n\n", r.real, r.imag);

  return r;
}

void complex_print(COMPLEX z)//print the complex numbers
{
  printf("\nz = %.2Lf + %.2Lfi\n\n", z.real, z.imag);
}
