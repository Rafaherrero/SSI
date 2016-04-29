#include "rsa.hpp"

rsa::rsa (void){}

rsa::rsa (unsigned long a, unsigned long b){
	euclides(a,b);
}

rsa::~rsa (void){

}

unsigned long rsa::euclides(unsigned long a, unsigned long b){
	long int z_1 = 0, z0 = 1;
	unsigned long x0=a, x1=b, aux=b;

	while(x1>0){

		cout << "Mi x0 vale: " << x0 << endl;
		cout << "Mi x1 vale: " << x1 << endl;

		x1=(x0%x1);
		x0=aux;
		aux=x1;

		cout << "Mi x0 vale: " << x0 << endl;
		cout << "Mi x1 vale: " << x1 << endl << endl;
	}
}