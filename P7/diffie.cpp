#include "diffie.hpp"

diffie::diffie(void):
primo_(1),
alpha_(0),
secreto_(0),
y_(0)
{}

diffie::diffie(unsigned pr_, unsigned al_, unsigned sec_):
secreto_(sec_),
y_(0)
{
	if (al_<pr_){
		alpha_ = al_;
		if (es_primo(pr_)){
			primo_ = pr_;
			y_ = calculo(alpha_, sec_);
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

unsigned diffie::get_y(void){
	return y_;
}

unsigned diffie::get_secreto(void){
	return secreto_;
}

