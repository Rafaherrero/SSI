//Compilar usando g++ -std=c++11 main.cpp rc4.cpp

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

	std::vector<unsigned char> semilla_2(8,0);
	semilla_2 = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef};

	std::vector<unsigned char> msg_2(8, 0);
	msg_2 = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

	std::vector<unsigned char> msg_cifrado_2(8,0);
	std::vector<unsigned char> secuencia_cifrado_2;

	rc4 B(semilla_2);
	msg_cifrado_2 = B.cifrar(msg_2);

	cout << "====================" << endl;
	cout << "El mensaje original es: ";
	for (int i=0;i<msg_2.size();i++){
		if (i==msg_2.size()-1)
			cout << hex << int(msg_2[i]);
		else
			cout << hex << int(msg_2[i]) << ", ";
	}
	cout << endl << "La semilla es: ";
	for (int i=0;i<semilla_2.size();i++){
		if (i==semilla_2.size()-1)
			cout << hex << int(semilla_2[i]);
		else
			cout << hex << int(semilla_2[i]) << ", ";
	}
	secuencia_cifrado_2=B.secuencia();
	cout << endl << "La clave de cifrado es: ";
	for (int i=0;i<secuencia_cifrado_2.size();i++){
		if (i==secuencia_cifrado_2.size()-1)
			cout << hex << int(secuencia_cifrado_2[i]);
		else
			cout << hex << int(secuencia_cifrado_2[i]) << ", ";
	}
	cout << endl << "El mensaje cifrado es: ";
	for (int i=0;i<msg_cifrado_2.size();i++){
		if (i==msg_cifrado_2.size()-1)
			cout << hex << int(msg_cifrado_2[i]);
		else
			cout << hex << int(msg_cifrado_2[i]) << ", ";
	}
	cout << endl << "====================" << endl;


	rc4 C(semilla_2);
	cout << "====================" << endl;
	cout << "MODIFICACIÓN SPRITZ" << endl;
	std::vector<unsigned char> msg_cifrado_3(8,0);
	msg_cifrado_3 = C.cifrar_mod(msg_2);
	cout << "El mensaje cifrado es: ";
	for (int i=0;i<msg_cifrado_3.size();i++){
		if (i==msg_cifrado_3.size()-1)
			cout << hex << int(msg_cifrado_3[i]);
		else
			cout << hex << int(msg_cifrado_3[i]) << ", ";
	}
	cout << endl << "====================" << endl;

}