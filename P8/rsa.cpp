#include "rsa.hpp"

rsa::rsa (void){
}

rsa::rsa(boost::multiprecision::mpz_int p, boost::multiprecision::mpz_int q, boost::multiprecision::mpz_int d){
	
	if (lehman(p))
		p_ = p;
	else
		cout << "El numero p: " << p << ", no es primo." << endl;

	if (lehman(q))
		q_ = q;
	else
		cout << "El numero q: " << q << ", no es primo." << endl;
}

rsa::~rsa (void){

}

boost::multiprecision::mpz_int rsa::euclides(boost::multiprecision::mpz_int a, boost::multiprecision::mpz_int b){
	boost::multiprecision::mpz_int z_1 = 0, z0 = 1, aux_z=z0;
	boost::multiprecision::mpz_int x0=a, x1=b, aux=b;

	while(x1>0){

		z0=(-x0/x1)*z0+z_1;
		z_1=aux_z;
		aux_z=z0;

		x1=(x0%x1);
		x0=aux;
		aux=x1;
	}

	if(x0!=1)
		cout << "Los números pasados no son primos" << endl;
	else{
		if(z_1<0){
			return ((z_1%a+a)%a);
		}
		else
			return z_1;
	}
}

bool rsa::lehman(boost::multiprecision::mpz_int p){
	vector<boost::multiprecision::mpz_int> ai(100);
	bool es_primo=true;

	for (int i=0; i<ai.size(); i++)
		ai[i] = aleatorio(1,p-1);
	for (int i=0; i<ai.size()&&es_primo;i++){
		if((expo(ai[i],((p-1)/2),p))!=1 && (expo(ai[i],((p-1)/2),p))!=p-1)
			es_primo=false;
	}
	return es_primo;
		
}

boost::multiprecision::mpz_int rsa::aleatorio (boost::multiprecision::mpz_int rg_1, boost::multiprecision::mpz_int rg_2){
	
	uint64_t rgg_1 = uint64_t(rg_1);
	uint64_t rgg_2 = uint64_t(rg_2);

	random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator (http://www.cplusplus.com/reference/random/mersenne_twister_engine/)
    uniform_int_distribution<> distr(rgg_1, rgg_2); // define the range
    return distr(eng);
}

boost::multiprecision::mpz_int rsa::expo(boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_, boost::multiprecision::mpz_int primo_){
	boost::multiprecision::mpz_int x = 1;
	boost::multiprecision::mpz_int y = base%primo_;
	boost::multiprecision::mpz_int copia_sec = exp_;

	while (copia_sec>0 && y>1){
		if (copia_sec%2==1){
			x = (x*y)%primo_;
			copia_sec--;
		}
		else{
			y = (y*y)%primo_;
			copia_sec = copia_sec/2;
		}
	}
	return x;
}