#include "vigenere.hpp"
#include <cctype>

using namespace std;

int main (void){
	string clave_cifrar = "MISION";
	string mensaje_sin_cifrar ="ESTE MENSAJE SE AUTODESTRUIRA";

	vigenere A(clave_cifrar,mensaje_sin_cifrar);
	cout << A.imprimir() << endl;
}