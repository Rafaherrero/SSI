#include "rc4.hpp"

using namespace std;

int main (void){

	std::vector<unsigned char> semilla(2,0);
	semilla[0]=2;
	semilla[1]=5;

	std::vector<unsigned char> msg(2, 0);
	msg[0]=1;
	msg[1]=34;
	std::vector<unsigned char> msg_cifrado(2,0);
	std::vector<unsigned char> secuencia_cifrado;
	
	rc4 A(semilla);
	msg_cifrado = A.cifrar(msg);

	cout << "====================" << endl;
	cout << "El mensaje original es: ";
	for (int i=0;i<msg.size();i++){
		if (i==msg.size()-1)
			cout << int(msg[i]);
		else
			cout << int(msg[i]) << ", ";
	}
	cout << endl << "La semilla es: ";
	for (int i=0;i<semilla.size();i++){
		if (i==semilla.size()-1)
			cout << int(semilla[i]);
		else
			cout << int(semilla[i]) << ", ";
	}
	secuencia_cifrado=A.secuencia();
	cout << endl << "La clave de cifrado es: ";
	for (int i=0;i<secuencia_cifrado.size();i++){
		if (i==secuencia_cifrado.size()-1)
			cout << int(secuencia_cifrado[i]);
		else
			cout << int(secuencia_cifrado[i]) << ", ";
	}
	cout << endl << "El mensaje cifrado es: ";
	for (int i=0;i<msg_cifrado.size();i++){
		if (i==msg_cifrado.size()-1)
			cout << int(msg_cifrado[i]);
		else
			cout << int(msg_cifrado[i]) << ", ";
	}
	cout << endl << "====================" << endl;
}