#include "vigenere.hpp"

vigenere::vigenere(void):
mensaje_(0),
clave_(0)
{}

vigenere::vigenere(string clave_cifrar, string mensaje_sin_cifrar):
mensaje_(mensaje_sin_cifrar),
clave_(clave_cifrar)
{
	corrector();
}

vigenere::~vigenere (void){

}

void vigenere::corrector (void){
	if (!(mensaje_.length()>=clave_.length())){
		cerr << "El mensaje no es mayor o igual que la clave. " << endl;
	}
	else{
		mensaje_.erase(remove(mensaje_.begin(),mensaje_.end(),' '),mensaje_.end());

		for (int i=0; i<mensaje_.length();i++){
			mensaje_[i] = toupper(mensaje_[i]);
			if (!((mensaje_[i] >= 'A')&&(mensaje_[i] <='Z')))
				mensaje_[i]='?';
		}

		clave_.erase(remove(clave_.begin(),clave_.end(),' '),clave_.end());

		for (int i=0; i<clave_.length();i++){
			clave_[i] = toupper(clave_[i]);
			if (!((clave_[i] >= 'A')&&(clave_[i] <='Z')))
				clave_[i]='?';
		}
	}
}

string vigenere::imprimir(void){
	return mensaje_;
}

string vigenere::cifrar (void){

}