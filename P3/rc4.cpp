#include "rc4.hpp"

using namespace std;

rc4::rc4 (void):
S_(0),
K_(0),
i_(0),
j_(0)
{}

rc4::rc4 (std::vector<unsigned char> semilla):
S_(256, 0),
K_(256, 0),
i_(0),
j_(0)
{
	for (int i=0; i<S_.size();i++){
		S_[i] = i;
		K_[i] = semilla[i%semilla.size()];

	}
	int j=0;
	for (int i=0; i<S_.size();i++){
		j = (j+S_[i]+K_[i])%S_.size();
		swap(S_[i],S_[j]);
	}
}

rc4::~rc4(void){

}

unsigned char rc4::prga (void){
	unsigned t;
	i_ = (i_+1)%256;
	j_ = (j_+S_[i_])%256;
	swap(S_[i_],S_[j_]);
	t = (S_[i_]+S_[j_])%256;
	return (S_[t]);
}

std::vector<unsigned char> rc4::cifrar (std::vector<unsigned char> mensaje){
	unsigned char cf;
	std::vector<unsigned char> mensaje_cifrado(mensaje.size(),0);
	secuencia_.resize(mensaje.size(),0);

	for (int i=0; i< mensaje.size();i++){
		cf = prga();
		secuencia_[i] = cf;
		mensaje_cifrado[i] = mensaje[i]^cf;
	}

	return mensaje_cifrado;
}

std::vector<unsigned char> rc4::secuencia (void){
	return secuencia_;
}









