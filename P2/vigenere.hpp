#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <locale>
#include <algorithm>

using namespace std;

class vigenere{
private:
	string clave_;
	string mensaje_;
	string mensaje_cifrado_;
public:
	vigenere(void);
	vigenere(string clave_cifrar, string mensaje_sin_cifrar);
	~vigenere(void);
	string imprimir_formato(void);
	string imprimir_cifrado(void);
	void corrector(void);
	void cifrar(void);
	string descifrar(void);
	string descifrar (string mensaje_cf, string clave_descifrar);
};
