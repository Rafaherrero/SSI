#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <boost/multiprecision/gmp.hpp>

using namespace std;

class rsa{
private:
public:
	rsa(void);
	~rsa(void);
	boost::multiprecision::mpz_int euclides(boost::multiprecision::mpz_int a, boost::multiprecision::mpz_int b);
	bool lehman(boost::multiprecision::mpz_int p);
	boost::multiprecision::mpz_int aleatorio(boost::multiprecision::mpz_int rg_1, boost::multiprecision::mpz_int rg_2);
	boost::multiprecision::mpz_int expo(boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_, boost::multiprecision::mpz_int primo_);
};