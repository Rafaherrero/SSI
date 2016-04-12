//Compilar usando g++ -std=c++11 main.cpp diffie.cpp
#include "diffie.hpp"

using namespace std;

int main (void){
	unsigned primo = 1973;
	unsigned alpha = 125;
	unsigned secreto_a = 21;
	unsigned secreto_b = 32;
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

//==========================================================================================
	cout << endl << "================ " << "MODIFICACION" << "================" << endl;
	unsigned ct;
	unsigned primo_2;
	unsigned alpha_2;
	cout << "Introduzca la cantidad de personas a comunicar: ";
	cin >> ct;
	cout << "Introduzca el número primo: ";
	cin >> primo_2;
	cout << "Introduzca el generador alpha: ";
	cin >> alpha_2;

	unsigned secreto_mod[ct];
	diffie Per_[ct];

	for (int i=0; i<ct; i++){
		cout << "Introduzca el secreto de " << i+1 << ": ";
		cin >> secreto_mod[i];
		Per_[i].set(primo_2, alpha_2, secreto_mod[i]);
	}
	unsigned intermedio;

	for (int i=0; i<ct-1; i++){
		intermedio = Per_[i+1].calculo(Per_[i].get_y(), secreto_mod[i+1]);
		Per_[i+1].set_y(intermedio);		
	}

	cout << "La clave compartida es: " << Per_[ct-1].calculo(Per_[ct-2].get_y(), secreto_mod[ct-1]) << endl;

}
