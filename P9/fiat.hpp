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
	boost::multiprecision::mpz_int p_, q_, s_, n_, v_, x_;
public:
	fiat(void);
	fiat(boost::multiprecision::mpz_int p, boost::multiprecision::mpz_int q, boost::multiprecision::mpz_int s);
	~fiat(void);
	boost::multiprecision::mpz_int euclides(boost::multiprecision::mpz_int a, boost::multiprecision::mpz_int b, bool modo);
	bool lehman(boost::multiprecision::mpz_int p);
	boost::multiprecision::mpz_int aleatorio(boost::multiprecision::mpz_int rg_1, boost::multiprecision::mpz_int rg_2);
	boost::multiprecision::mpz_int expo(boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_, boost::multiprecision::mpz_int modulo);
	boost::multiprecision::mpz_int get_n (void);
	boost::multiprecision::mpz_int get_v (void);
	boost::multiprecision::mpz_int get_a (void);
	boost::multiprecision::mpz_int get_y (boost::multiprecision::mpz_int e);
	boost::multiprecision::mpz_int pow_multiprecision (boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_);
	void set_x (boost::multiprecision::mpz_int x);
	bool verificacion(boost::multiprecision::mpz_int y, boost::multiprecision::mpz_int a, boost::multiprecision::mpz_int v, boost::multiprecision::mpz_int n, boost::multiprecision::mpz_int e);
};