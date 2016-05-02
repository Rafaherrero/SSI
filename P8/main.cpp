//Compilar usando g++ -std=c++11 main.cpp rsa.cpp -lgmp
#include "rsa.hpp"

using namespace std;

int main (void){
	
	string text_cf;
	boost::multiprecision::mpz_int p_a, q_a, d_a, p_b, q_b, d_b;

	cout << "==================== " << "RSA" << " ====================" << endl << endl;
	cout << "Introduzca el texto a cifrar: ";
	getline(cin, text_cf);
	cout << endl << "Introduzca la p de Anastacia: ";
	cin >> p_a;
	cout << "Introduzca la q de Anastacia: ";
	cin >> q_a;
	cout << "Introduzca la d de Anastacia: ";
	cin >> d_a;
	cout << endl << "Bonifacio utilizará los mismo valores que Anastacia." << endl << endl;

	text_cf.erase( std::remove_if(text_cf.begin(), text_cf.end(), ::isspace ), text_cf.end());
	rsa A(p_a, q_a, d_a);
	rsa B(p_a, q_a, d_a);

	cout << "Anastacia quiere enviarle el mensaje a Bonifacio. Para ello, necesita su e y n." << endl;
	cout << "e de Bonifacio: " << B.get_e() << endl;
	cout << "n de Bonifacio: " << B.get_n() << endl << endl;
	
	vector<boost::multiprecision::mpz_int> texto_cifrado = A.cifrar(text_cf, B.get_e(), B.get_n());

	cout << "Bonifacio recibe el texto cifrado: ";
	for (int i=0; i<texto_cifrado.size(); i++)
		cout << texto_cifrado[i] << "  ";

	cout << endl << endl << "Bonifacio no entiende nada y quiere descifrar el mensaje. Para ello necesita su d (privada) y la n de Anastacia." << endl;
	cout << "n de Anastacia: " << A.get_n() << endl;

	vector<boost::multiprecision::mpz_int> texto_descifrado = B.descifrado(texto_cifrado, A.get_n());

	cout << "Bonifacio descifra el texto cifrado: ";
	for (int i=0; i<texto_descifrado.size(); i++)
		cout << texto_descifrado[i] << "  ";

	cout << endl << endl << "Bonifacio sigue sin enterarse de lo que pone, aunque sabe que el mensaje ya esta descifrado. Para entender algo de lo que pone, utiliza un parseador." << endl;
	cout << "Texto parseado: ";

	string resultado = B.paso_string(texto_descifrado, A.get_n());
	cout << resultado << endl;

	cout << endl << "Finalmente, Anastacia y Bonifacio han establecido comunicacion utilizando un canal seguro." << endl;
	cout << endl << "=============================================" << endl;
}