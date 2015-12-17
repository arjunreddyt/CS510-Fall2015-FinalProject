#include <iostream>
#include <complex>
#include "julia.h"

std::complex<long double> juliamap(std::complex<long double> zval, std::complex<long double> cval){
	return (zval*zval)+cval;
}
