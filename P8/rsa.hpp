#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <ctype.h>
#include <boost/multiprecision/gmp.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

class rsa{
private:
	boost::multiprecision::mpz_int p_, q_, d_, phi_n_, n_, e_;
public:
	rsa(void);
	rsa(boost::multiprecision::mpz_int p, boost::multiprecision::mpz_int q, boost::multiprecision::mpz_int d);
	~rsa(void);
	boost::multiprecision::mpz_int euclides(boost::multiprecision::mpz_int a, boost::multiprecision::mpz_int b, bool modo);
	bool lehman(boost::multiprecision::mpz_int p);
	boost::multiprecision::mpz_int aleatorio(boost::multiprecision::mpz_int rg_1, boost::multiprecision::mpz_int rg_2);
	boost::multiprecision::mpz_int expo(boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_, boost::multiprecision::mpz_int primo_);
	boost::multiprecision::mpz_int pow_multiprecision (boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_);
	vector<boost::multiprecision::mpz_int> cifrar (string tx_cf, boost::multiprecision::mpz_int e_del_otro, boost::multiprecision::mpz_int n_del_otro);
	vector<boost::multiprecision::mpz_int> descifrado (vector<boost::multiprecision::mpz_int> tx_cifrado, boost::multiprecision::mpz_int n_del_otro);
	string paso_string (vector<boost::multiprecision::mpz_int> tx_descifrado, boost::multiprecision::mpz_int n_del_otro);
	boost::multiprecision::mpz_int get_e (void);
	boost::multiprecision::mpz_int get_n (void);
};