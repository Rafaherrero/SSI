//Compilar usando g++ -std=c++11 main.cpp rsa.cpp -lgmp
#include "rsa.hpp"

using namespace std;

int main (void){
	
	string text_cf;
	boost::multiprecision::mpz_int p_a, q_a, d_a, p_b, q_b, d_b;

	cout << "==================== " << "RSA" << " ====================" << endl << endl;
	cout << "Introduzca el texto a cifrar: ";
	cin >> text_cf;
	cout << endl << "Introduzca la p de Anastacia: ";
	cin >> p_a;
	cout << "Introduzca la q de Anastacia: ";
	cin >> q_a;
	cout << "Introduzca la d de Anastacia: ";
	cin >> d_a;
	cout << endl << "Introduzca la p de Bonifacio: ";
	cin >> p_b;
	cout << "Introduzca la q de Bonifacio: ";
	cin >> q_b;
	cout << "Introduzca la d de Bonifacio: ";
	cin >> d_b;

	rsa A(p_a, q_a, d_a);
	rsa B(p_b, q_b, d_b);
	
	cout << "Inverso segun el algoritmo de Euclides extendido entre 811716 y 5 es: " << A.euclides(811716,5) << endl;

	if (A.lehman(4267149919458365153))
		cout << "El numero 4267149919458365153 es primo" << endl;
	else
		cout << "El numero 4267149919458365153 no es primo" << endl;
}