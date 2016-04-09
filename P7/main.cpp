//Compilar usando g++ -std=c++11 main.cpp diffie.cpp
#include "diffie.hpp"

using namespace std;

int main (void){
	unsigned primo = 43;
	unsigned alpha = 23;
	unsigned secreto_a = 25;
	unsigned secreto_b = 33;
	diffie A(primo, alpha, secreto_a);
	diffie B(primo, alpha, secreto_b);

	cout << "======== " << "DIFFIE-HELLMAN" << " =========" << endl;
	cout << "El número primo a utilizar es: " << primo << endl;
	cout << "El número alpha a utilizar es: " << alpha << endl;
	cout << "El secreto de A es: " << A.get_secreto() << endl;
	cout << "El secreto de B es: " << B.get_secreto() << endl;
	cout << "El valor de 'y' de A es: " << A.get_y() << endl;
	cout << "El valor de 'y' de B es: " << B.get_y() << endl;
	cout << "Para A la clave 'k' vale: " << A.calculo(B.get_y(),A.get_secreto()) << endl;
	cout << "Para B la clave 'k' vale: " << B.calculo(A.get_y(),B.get_secreto()) << endl;
}
