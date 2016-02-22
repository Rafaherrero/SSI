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
	cout << "Nuestro mensaje Aencriptado es: " << A.encriptar(mensaje_A) << "." << endl;

	cout << endl << "Nuestra clave B es: " << clave_B << "." << endl;
	cout << "Nuestro mensaje encriptado es: " << mensaje_B << "." << endl;
	vernam B(clave_B);
	cout << "Nuestro mensaje desencriptado es: " << B.desencriptar(mensaje_B) << "." << endl;
	

}