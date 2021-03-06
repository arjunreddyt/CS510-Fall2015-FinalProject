#include<iostream>
#include<boost/numeric/ublas/matrix.hpp>
#include<boost/numeric/ublas/io.hpp>
#include<complex>
#include<cstdio>
//class declaration
class CPlane{
	public:
	long double Xmin, Xmax, Ymin, Ymax;
	unsigned long int Xpoints, Ypoints;
	boost::numeric::ublas::matrix<std::complex<long double> > mat;
	CPlane(long double xmin, long double xmax, long double ymin, long double ymax, unsigned long int xpoints, unsigned long int  ypoints);
};
