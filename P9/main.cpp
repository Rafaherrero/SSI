//Compilar usando g++ -std=c++11 main.cpp fiat.cpp -lgmp
//Es necesario tener instalado las librerias gmp de multiprecision y string de algorithm, ambas incluidas en la librería Boost
//Para instalar Boost, en cualquier sistema con gestor de paquetes apt, ejecutar este comando: sudo apt install libboost-all-dev
//Para instalar la libreria gmp, ejecutar sudo apt install libgmp3-dev

#include "fiat.hpp"

using namespace std;

int main (void){

	boost::multiprecision::mpz_int p_a, q_a, d_a, s_a, p_b, q_b, d_b, x_a, x_b, e_a, e_b;
	unsigned iter;

	cout << "==================== " << "FIAT-SHAMIR" << " ====================" << endl << endl;
	cout << "Introduzca la p de Anastacia: ";
	cin >> p_a;
	cout << "Introduzca la q de Anastacia: ";
	cin >> q_a;
	cout << "Introduzca la s de Anastacia: ";
	cin >> s_a;
	cout << "Introduzca el número de iteraciones: ";
	cin >> iter;
	cout << endl << "Bonifacio utilizará los mismo valores que Anastacia." << endl << endl;

	fiat A(p_a, q_a, s_a);
	fiat B(p_a, q_a, s_a);

	cout << "La N de Anastacia es: " << A.get_n() << endl;
	cout << "La v de Anastacia es: " << A.get_v() << endl << endl;

	for (int i=0; i < iter; i++){
		cout << "Iteracción " << i+1 << endl;
		cout << "Introduzca la x de Anastacia: ";
		cin >> x_a;
		A.set_x(x_a);
		
		cout << "Anastacia responde con una a de valor: " << A.get_a() << endl;
		cout << "Introduzca un bit cualquiera: ";
		cin >> e_b;
		
		cout << "Anastacia responde con una y de valor: " << A.get_y(e_b) << endl;
		cout << "Bonifacio procede a la verificación de la información recibida" << endl;
		
		if(B.verificacion(A.get_y(e_b),A.get_a(),A.get_v(),A.get_n(),e_b))
			cout << "La verificación por parte de Bonifacio es válida" << endl;
		else
			cout << "La información recibida para Bonifacio no es válida" << endl;

		cout << endl;
	}
}