#include "rc4.hpp"

using namespace std;

rc4::rc4 (void):
S_(0),
K_(0),
i_(0),
j_(0)
{}

rc4::rc4 (string semilla):
S_(256, 0),
K_(256, 0),
i_(0),
j_(0)
{
	for (int i=0; i<S_.size();i++){
		S_[i] = i;
		K_[i] = semilla[i%semilla.length()];

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

string rc4::cifrar (string mensaje){
	string mensaje_cifrado;
	for (int i=0; i< mensaje.length();i++){
		mensaje_cifrado[i] = mensaje[i]^prga();
	
	cout << int(mensaje_cifrado[i]) << " ";
}
	return mensaje_cifrado;
}











