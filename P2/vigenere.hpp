#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <locale>
#include <algorithm>

using namespace std;

class vigenere{
private:
	//Los 3 atributos de nuestra clase son la clave, el mensaje sin/con formato y el mensaje una vez cifrado
	string clave_;
	string mensaje_;
	string mensaje_cifrado_;
public:
	//Constructores sin atributos y otro que si y destructor por defecto
	vigenere(void);
	vigenere(string clave_cifrar, string mensaje_sin_cifrar);
	~vigenere(void);

	//Metodos para imprimir los atributos mensaje_ y mensaje_cifrado
	string imprimir_formato(void);
	string imprimir_cifrado(void);

	//Metodo que da formato a la clave y al mensaje
	void corrector(void);

	//Metodos para cifrar y descifrar con los atributos almacenados en la clase
	void cifrar(void);
	string descifrar(void);

	//Metodos iguales a los anteriores, salvo que ahora el mensaje y la clave los recibe el metodo y no utiliza los de la clase
	void corrector (string& mensaje_df, string& clave_cf);
	string cifrar (string mensaje_df, string clave_cf);
	string descifrar (string mensaje_cf, string clave_descifrar);

	//Modificación de la práctica
	string cesar(void);
};
