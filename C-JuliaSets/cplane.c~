#include <stdio.h>
#include <stdlib.h>
#include "cplane.h"

CPLANE* CPlane(long double XMin, long double XMax, long double YMin,
	long double YMax, unsigned long int XPoints, unsigned long int YPoints) {

		CPLANE* temp = malloc(sizeof(CPLANE)+(sizeof(long double) * ( XPoints * YPoints)));//Matrix Initialization
		temp->xmin = XMin;//Initializing Parameters
		temp->xmax = XMax;
		temp->ymin = YMin;
		temp->ymax = YMax;
		temp->xpoints = XPoints;
		temp->ypoints = YPoints;
		long double x, y;
		long double xInc = (XMax-XMin) / XPoints;//Defines Step Size
		long double yInc = (YMax-YMin) / YPoints;//Defines Step Size
		COMPLEX* mat[XPoints][YPoints];
		int i = 0, j = 0;
		temp->mat = malloc(sizeof(long double) * (XPoints * YPoints));
		for ( x = XMin, i = 0; i < XPoints; x = x + xInc, i++) {//GEt the complex plane
			j=0;
			for (y = YMin, j = 0; j < YPoints; y = y + yInc, j++) {
				COMPLEX c;
				c.real= x;
				c.imag= y;
				*(temp->mat+j+i) = c;
			}
		}
		return temp;
	}
