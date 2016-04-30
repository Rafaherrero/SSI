//Compilar usando g++ -std=c++11 main.cpp rsa.cpp
#include "rsa.hpp"

using namespace std;

int main (void){
	rsa A;

	cout << "Inverso segun el algoritmo de Euclides extendido entre 139901 y 128189 es: " << A.euclides(139901,128189) << endl;
	if (A.lehman(1589322283))
		cout << "El numero 1589322283 es primo" << endl;
	else
		cout << "El numero 1589322283 no es primo" << endl;
}