#include "vernam.hpp"

vernam::vernam (void)
{}

vernam::~vernam(void)
	{}

vernam::vernam(string clave)
{
	clave_=conversor(clave);
}

string vernam::encriptar(string mensaje){
	for (int i=0;i<mensaje.length();i++)	
		mensaje[i]=mensaje[i]^clave_[i];
	return mensaje;
}

string vernam::desencriptar(string mensaje){
	for (int i=0;i<mensaje.length();i++)	
		mensaje[i]=mensaje[i]^clave_[i];
	return mensaje;
}

string vernam::conversor (string clave){
	if (clave.size()%8!=0)
		cerr << "LA CLAVE ESTA MAL" << endl;

	string clave_ascii("", clave.size()/8);
	stringstream clave_stream(clave);
	for (int i=0; i < clave.size()/8;i++){
		bitset<8> clave_bit;
		clave_stream >> clave_bit;
		clave_ascii[i] = char(clave_bit.to_ulong());
	}
	return clave_ascii;
}