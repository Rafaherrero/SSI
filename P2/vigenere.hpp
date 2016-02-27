#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <locale>

using namespace std;

class vigenere{
private:
	string clave_;
	string mensaje_;
public:
	vigenere(void);
	vigenere(string clave_cifrar, string mensaje_sin_cifrar);
	~vigenere(void);
	string imprimir(void);
	void corrector(void);
};
