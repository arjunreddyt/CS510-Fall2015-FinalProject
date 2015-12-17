#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "cplane.h"
#define MAXITER 256

void iterate(COMPLEX z,COMPLEX c);

int main (int argc, char **argv) {

	if (argc != 9) {
		printf("Error, program expects 9 input values: xmin, xmax, ymin, ymax, xpoints, ypoints, real, imaginary.\n\n");
		return -1;
	}

	//initialize cplane parameters
	long double xmin = atof(argv[1]);
	long double xmax = atof(argv[2]);
	long double ymin = atof(argv[3]);
	long double ymax = atof(argv[4]);
	unsigned long int xpoints = atol(argv[5]);
	unsigned long int ypoints = atol(argv[6]);
	long double real = atof(argv[7]);
	long double imaginary = atof(argv[8]);

	//create complex plane
	CPLANE* cplane = CPlane(xmin, xmax, ymin, ymax, xpoints, ypoints);
	COMPLEX C;
	C.real = real;
  	C.imag = imaginary;
	int i, j=0;
	for (i = 0; i < xpoints; i++) {
		for (j = 0; j < ypoints; j++) {
			COMPLEX c = *(cplane[0].mat + j + i);
			iterate(c, C);
		}
	}
	return 0;
}

//calculate and iterate juliaset
void iterate(COMPLEX z, COMPLEX c){
	int out = 0;
	while(1){
	     if(sqrtl((z.real*z.real)+(z.imag*z.imag))>=2){
			out = 0;
			printf("%1.10Lf, %1.10Lf, %d \n", z.real,z.imag, out);
			break;
		}
		else if(out>=MAXITER){
			printf("%1.10Lf, %1.10Lf, %d \n",z.real, z.imag, out);
			break;
		}
		const COMPLEX Z = z;
		const COMPLEX C = c;
		z = juliamap(&Z, &C);
		out++;
	}
}
