#include "vernam.hpp"

vernam::vernam (void)
{}

vernam::~vernam(void)
	{}

vernam::vernam(string clave)
{
	clave_=conversor(clave);
}

vernam::vernam(string clave, int num)
{
	clave_=clave;
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

string vernam::conversor_to_bool (string clave){
	std::string clave_bool;
	for(int i = 0; i < clave.size(); i++){
		clave_bool += (bitset<8>(clave.c_str()[i])).to_string();
	}
	return clave_bool;
}

string vernam::aleatorio (string mensaje){
	string clave_aleatoria("",mensaje.size()/8);
	for (int i=0; i<mensaje.size()/8;i++){
		srand(time(NULL));
		clave_aleatoria[i]=rand()%100;
	}
	return clave_aleatoria;
}

string vernam::imprimir_clave(void){
	return clave_;
}

string vernam::imprimir_bien (string mensaje){
	string mensaje_bueno;
	for (int i=0;i<mensaje.size();i++){
		if(32 <= mensaje[i]&&mensaje[i]<=126)
			mensaje_bueno+=mensaje[i];
		else
			mensaje_bueno+='@';
	}
	return mensaje_bueno;
}