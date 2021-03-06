#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include "cplane.hpp"
#include "julia.h"
const int MAX_ITER = 256;

void iterate(std::complex<long double> cval, std::complex<long double> zval);
int main (int argc, char **argv) {

//initializing the parameters
	long double XMin  = atof(argv[1]);
	long double XMax = atof(argv[2]);
	long double YMin = atof(argv[3]);
	long double YMax = atof(argv[4]);
	unsigned long int XPoints = atol(argv[5]);
	unsigned long int YPoints = atol(argv[6]);
  	


	CPlane cplane(XMin,XMax,YMin,YMax,XPoints,YPoints);

  // iterators ref http://www.boost.org/doc/libs/1_36_0/libs/numeric/ublas/doc/matrix.htm
//using boost 
	boost::numeric::ublas::matrix<std::complex<long double> >::iterator1 it1;
	boost::numeric::ublas::matrix<std::complex<long double> >::iterator1 it1_end = cplane.mat.end1();
  	boost::numeric::ublas::matrix<std::complex<long double> >::iterator2 it2;
	boost::numeric::ublas::matrix<std::complex<long double> >::iterator2 it2_end;
//matrix iteration
  	for(it1 = cplane.mat.begin1();it1 != it1_end; ++it1) {
      	it2_end = it1.end();
     	for(it2 = it1.begin();it2 != it2_end; ++it2) {
        iterate(0, *it2);
      }
    }
    return 0;
}

void iterate(std::complex<long double> cval,std::complex<long double> zval){
	int out=0;
  while(1){
    if((sqrt((zval.real()*zval.real())+(zval.imag()*zval.imag())) >= 2) || out > MAX_ITER){
      std::cout << zval.real() << "," << zval.imag() << "," << out <<std::endl;
      break;
    }
    zval=juliamap(zval,cval);
    out++;
	}
}
