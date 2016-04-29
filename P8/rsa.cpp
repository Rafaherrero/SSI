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