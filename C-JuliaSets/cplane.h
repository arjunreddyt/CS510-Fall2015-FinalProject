#include "complex.h"

typedef struct cplane { //struct cplane
	long double xmin, xmax, ymin, ymax;
	unsigned long int xpoints, ypoints;
	COMPLEX* mat;
} CPLANE;

// Constructors
CPLANE* CPlane(long double, long double, long double, long double, unsigned long int, unsigned long int);
