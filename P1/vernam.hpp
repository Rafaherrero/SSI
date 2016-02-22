#include <iostream>
#include <bitset>
#include <sstream>

using namespace std;

class vernam{
private:
	
public:
	string clave_;
	vernam(void);
	vernam(string clave);
	~vernam(void);
	string encriptar (string mensaje);
	string desencriptar (string mensaje);
	string conversor (string clave);
};