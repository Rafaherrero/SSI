#include "diffie.hpp"

diffie::diffie(void):
primo_(1),
alpha_(0),
secreto_a_(0),
secreto_b_(0),
y_a_(0),
y_b_(0)
{}

diffie::diffie(unsigned pr_, unsigned al_, unsigned sec_a_, unsigned sec_b_):
secreto_a_(sec_a_),
secreto_b_(sec_b_),
y_a_(0),
y_b_(0)
{
	if (al_<pr_){
		alpha_ = al_;
		if (es_primo(pr_)){
			primo_ = pr_;
			y_a_ = calculo(alpha_, sec_a_);
			y_b_ = calculo(alpha_, sec_b_);
			clave_a_ = calculo(y_b_, sec_a_);
			clave_b_ = calculo(y_a_, sec_b_);
			cout << "Deberian ser iguales " << clave_a_ << " y " << clave_b_ << endl;
		}
		else
			cout << "P no es un número primo" << endl;
	}
	else
		cout << "Alpha no es menor que p" << endl;
}

diffie::~diffie(void){

}

bool diffie::es_primo(unsigned pr_){
	
	unsigned a=0;

	for(unsigned i=1;i<(pr_+1);i++){  
		if(pr_%i==0)  
			a++;    
	}  

	if(a!=2)
		return false;  
	else  
		return true;  
}  

unsigned diffie::calculo(unsigned base, unsigned exp_){
	unsigned x = 1;
	unsigned y = base%primo_;
	unsigned copia_sec = exp_;

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