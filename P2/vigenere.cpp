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
	int j, caracter = 0;
	string mensaje_cifrado;
	for (int i=0; i<mensaje_.length();i++){
		if (j>=clave_.length()){
			j=0;
		}

		if (mensaje_[i]!='?'){
			caracter = (((mensaje_[i])-65)+((clave_[j])-65));
		if (caracter>=26)
			caracter=caracter-26;
		caracter = caracter+65;
		}
		else{
			caracter = mensaje_[i];
		}
		j++;
		mensaje_cifrado.append(string(1, (char)(caracter)));
	}
	return mensaje_cifrado;
}




