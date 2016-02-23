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
	
///////

	string mensaje_C = "ATACAR MARTES 23 9:30 HORAS";
	string clave_C = "010101000110111101100100011000010111011001101001011000010010000001110010011001010110001101110101011001010111001001100100011011110010000001100001011100010111010101100101011011000010000001100001011011010110000101101110";
	vernam C(clave_C);
	string mensaje_encriptado_C = C.encriptar(mensaje_C);
	cout << endl << "Nuestro mensaje encriptado es: " << C.imprimir_bien(mensaje_encriptado_C) << "." << endl;
	cout << "Nuestro mensaje encriptado en binario es: " << C.conversor_to_bool(mensaje_encriptado_C) << "." << endl;
}