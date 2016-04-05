//Compilar usando g++ -std=c++11 main.cpp vernam.cpp

#include "vernam.hpp"

using namespace std;

int main(void)
{
	string clave_A = "001111000001100001110011";
	string mensaje_A = "SOL";
	string clave_B = "0000111100100001";
	string mensaje_B = "[t";
	cout << "Nuestra clave A es: " << clave_A << "." << endl;
	cout << "Nuestro mensaje A es: " << mensaje_A << "." << endl;
	vernam A(clave_A);
	cout << "Nuestro mensaje A encriptado es: " << A.encriptar(mensaje_A) << "." << endl;

	cout << endl << "Nuestra clave B es: " << clave_B << "." << endl;
	cout << "Nuestro mensaje encriptado es: " << mensaje_B << "." << endl;
	vernam B(clave_B);
	cout << "Nuestro mensaje desencriptado es: " << B.desencriptar(mensaje_B) << "." << endl;
	
	string mensaje_C = "ATACAR MARTES 23 9:30 HORAS";
	string clave_C = "Todavia recuerdo aquel aman";
	vernam C(clave_C,0);
	string mensaje_encriptado_C = C.encriptar(mensaje_C);
	cout << endl << "Nuestro mensaje es: " << mensaje_C << "." << endl;
	cout << "Nuestra clave es: " << clave_C << "." << endl;
	cout << "Nuestro mensaje encriptado es: " << C.imprimir_bien(mensaje_encriptado_C) << "." << endl;
	cout << "Nuestro mensaje encriptado en binario es: " << C.conversor_to_bool(mensaje_encriptado_C) << "." << endl;
}