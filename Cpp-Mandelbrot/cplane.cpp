#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include<boost/numeric/ublas/io.hpp>
#include<complex>
#include<cstdio>
#include "cplane.hpp"

//initializing parameters to create complex
CPlane::CPlane(long double xmin, long double xmax, long double ymin, long double ymax, unsigned long int xpoints, unsigned long int  ypoints):
							Xmin(xmin), Xmax(xmax),  Ymin(ymin),  Ymax(ymax),  Xpoints(xpoints),   Ypoints(ypoints), mat(xpoints,ypoints){


	long double xinc = ((xmax - xmin)) / xpoints, x;
	long double yinc = ((ymax - ymin)) / ypoints, y;
	int i,j;
//initializing matrix
	for (x = xmin, i = 0; i < xpoints; x += xinc, i++) {
		for (y = ymin, j = 0; j < ypoints; y += yinc, j++) {
			this->mat(i,j) = std::complex<long double>(x, y);
		}
  }
};
