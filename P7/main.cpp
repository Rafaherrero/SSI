//Compilar usando g++ -std=c++11 main.cpp diffie.cpp
#include "diffie.hpp"

using namespace std;

int main (void){
	unsigned primo = 7;
	unsigned alpha = 3;
	unsigned secreto_a = 12;
	unsigned secreto_b = 19;
	diffie(primo, alpha, secreto_a, secreto_b);
}
