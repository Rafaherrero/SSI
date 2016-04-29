//Compilar usando g++ -std=c++11 main.cpp rsa.cpp
#include "rsa.hpp"

using namespace std;

int main (void){
	rsa A;

	cout << A.euclides(139901,128189) << endl;
}