#include "vigenere.hpp"
#include <cctype>

using namespace std;

int main (void){
	string clave_cifrar = "MISION";
	string mensaje_sin_cifrar ="Este mensaje se autodestruira";

	vigenere A(clave_cifrar,mensaje_sin_cifrar);

	cout << "====================" << endl;
	cout << "El mensaje sin formato es: " << mensaje_sin_cifrar << endl;
	cout << "La clave de cifrado es: " << clave_cifrar << endl;
	cout << "El mensaje con formato es: " << A.imprimir_formato() << endl;
	cout << "El mensaje cifrado es: " << A.imprimir_cifrado() << endl;
	cout << "El mensaje descifrado es: " << A.descifrar() << endl;

	string mensaje_cifrado = "XQXWZZVYWYTUABRCW";
	string clave_descifrar = "LIMON";
	cout << "====================" << endl;
	cout << "Nuestro mensaje cifrado es: " << mensaje_cifrado << endl;
	cout << "Nuestra clave es: " << clave_descifrar << endl;
	cout << "El mensaje descifrado es: " << A.descifrar(mensaje_cifrado,clave_descifrar) << endl;
}