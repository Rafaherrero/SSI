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
	//mensaje_ = mensaje_[0] ;
}

string vigenere::imprimir(void){
	return mensaje_;
}