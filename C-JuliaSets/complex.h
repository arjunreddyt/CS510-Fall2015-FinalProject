#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct complex_number
{
    long double real;
    long double imag;
};

typedef struct complex_number COMPLEX;

COMPLEX mul(const COMPLEX *a, const COMPLEX *b);
COMPLEX square(const COMPLEX *k);
COMPLEX add(const COMPLEX *a, const COMPLEX *b);
COMPLEX juliamap(const COMPLEX *z, const COMPLEX *c);
void complex_print(COMPLEX z);
void test();
