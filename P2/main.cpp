#include "vigenere.hpp"
#include <cctype>

using namespace std;

//Con este programa podremos cifrar y descifrar clave usando el metodo de Vigenere
int main (void){
	//Declaramos la clave y el mensaje para la primera prueba
	string clave_cifrar = "MISION";
	string mensaje_sin_cifrar ="Este mensaje se autodestruira*ñÑ";
	vigenere A(clave_cifrar,mensaje_sin_cifrar);

	//Mostramos como seria el mensaje sin/con formato, la clave, el cifrado y el descifrado
	cout << endl << "====================" << endl;
	cout << "El mensaje sin formato es: " << mensaje_sin_cifrar << endl;
	cout << "La clave de cifrado es: " << clave_cifrar << endl;
	cout << "El mensaje con formato es: " << A.imprimir_formato() << endl;
	cout << "El mensaje cifrado es: " << A.imprimir_cifrado() << endl;
	cout << "El mensaje descifrado es: " << A.descifrar() << endl;
	cout << "====================" << endl;
 
	//Aqui probamos a simplemente descifrar un mensaje con una clave dada
	string mensaje_cifrado = "XQXWZZVYWYTUABRCW";
	string clave_descifrar = "LIMON";
	cout << endl << "====================" << endl;
	cout << "Nuestro mensaje cifrado es: " << mensaje_cifrado << endl;
	cout << "Nuestra clave es: " << clave_descifrar << endl;
	cout << "El mensaje descifrado es: " << A.descifrar(mensaje_cifrado,clave_descifrar) << endl;
	cout << "====================" << endl;

	//Aqui probamos a cifrar con un mensaje y una clave sin formato, sin meterlas como atributos de la clase
	string mensaje_df = "Probando probando";
	string clave_cf = "Microfono";
	cout << endl << "====================" << endl;
	cout << "El mensaje sin formato es: " << mensaje_df << endl;
	cout << "La clave de cifrado sin formato es: " << clave_cf<< endl;
	cout << "El mensaje cifrado es: " << A.cifrar(mensaje_df,clave_cf) << endl;
	cout << "====================" << endl;

	//Modificación práctica
	string clave_cifrar_2 = "SECRET";
	string mensaje_sin_cifrar_2 ="THERE ARE NO SECRETS ANYMORE";
	vigenere B(clave_cifrar_2,mensaje_sin_cifrar_2);

	//Mostramos como seria el mensaje sin/con formato, la clave, el cifrado y el descifrado
	cout << endl << "====================" << endl;
	cout << "El mensaje sin formato es: " << mensaje_sin_cifrar_2 << endl;
	cout << "La clave de cifrado es: " << clave_cifrar_2 << endl;
	cout << "El mensaje con formato es: " << B.imprimir_formato() << endl;
	cout << "El mensaje cifrado es: " << B.imprimir_cifrado() << endl;
	cout << "El mensaje descifrado es: " << B.descifrar() << endl;
	cout << "El mensaje César es: " << B.cesar() << endl;
	cout << "====================" << endl;
}