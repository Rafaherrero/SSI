#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <ctype.h>
#include <boost/multiprecision/gmp.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

class fiat{
private:
public:
	fiat(void);
	~fiat(void);
	boost::multiprecision::mpz_int euclides(boost::multiprecision::mpz_int a, boost::multiprecision::mpz_int b, bool modo);
	bool lehman(boost::multiprecision::mpz_int p);
	boost::multiprecision::mpz_int aleatorio(boost::multiprecision::mpz_int rg_1, boost::multiprecision::mpz_int rg_2);
	boost::multiprecision::mpz_int expo(boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_, boost::multiprecision::mpz_int primo_);
};