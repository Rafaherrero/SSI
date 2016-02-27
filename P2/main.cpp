#include "vigenere.hpp"
#include <cctype>

using namespace std;

int main (void){
	string clave_cifrar = "MISION";
	string mensaje_sin_cifrar ="Este mensaje *^`se autodestruira";

	vigenere A(clave_cifrar,mensaje_sin_cifrar);

	cout << "====================" << endl;
	cout << "El mensaje sin formato es: " << mensaje_sin_cifrar << endl;
	cout << "La clave de cifrado es: " << clave_cifrar << endl;
	cout << A.imprimir() << endl;
}