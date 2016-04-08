#include "diffie.hpp"

diffie::diffie(void):
primo_(1),
alpha_(0),
secreto_a_(0),
secreto_b_(0)
{}

diffie::diffie(unsigned pr_, unsigned al_, unsigned sec_a_, unsigned sec_b_):
secreto_a_(sec_a_),
secreto_b_(sec_b_)
{
	if (al_<pr_)
		alpha_ = al_;
	else
		cout << "Alpha no es menor que p" << endl;

	if (es_primo(pr_))
		primo_ = pr_;
	else
		cout << "P no es un número primo" << endl;

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
