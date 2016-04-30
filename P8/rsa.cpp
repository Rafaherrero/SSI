#include "rsa.hpp"

rsa::rsa (void){
}

rsa::~rsa (void){

}

unsigned long rsa::euclides(unsigned long a, unsigned long b){
	long int z_1 = 0, z0 = 1, aux_z=z0;
	unsigned long x0=a, x1=b, aux=b;

	while(x1>0){

		z0=-(x0/x1)*z0+z_1;
		z_1=aux_z;
		aux_z=z0;

		x1=(x0%x1);
		x0=aux;
		aux=x1;
	}

	if(x0!=1)
		cout << "Los números pasados no son primos" << endl;
	else
		return z_1;
}

bool rsa::lehman(unsigned long p){
	vector<unsigned> ai(100);
	bool es_primo=true;
	for (int i=0; i<ai.size(); i++)
		ai[i] = aleatorio(1,p-1);
	for (int i=0; i<ai.size()&&es_primo;i++){
		if((expo(ai[i],((p-1)/2),p))!=1 && (expo(ai[i],((p-1)/2),p))!=p-1)
			es_primo=false;
	}
	return es_primo;
		
}

unsigned long rsa::aleatorio (unsigned long rg_1, unsigned long rg_2){
	random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator (http://www.cplusplus.com/reference/random/mersenne_twister_engine/)
    uniform_int_distribution<> distr(rg_1, rg_2); // define the range
    return distr(eng);
}

unsigned long rsa::expo(unsigned long base, unsigned long exp_, unsigned long primo_){
	unsigned long x = 1;
	unsigned long y = base%primo_;
	unsigned long copia_sec = exp_;

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