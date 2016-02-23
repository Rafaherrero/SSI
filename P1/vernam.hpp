#include <iostream>
#include <bitset>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

class vernam{
private:
	string clave_;
public:
	vernam(void);
	vernam(string clave);
	vernam(string clave, int num);
	~vernam(void);
	string encriptar (string mensaje);
	string desencriptar (string mensaje);
	string conversor (string clave);
	string aleatorio (string mensaje);
	string conversor_to_bool (string clave);
	string imprimir_clave (void);
	string imprimir_bien (string mensaje);
};