//Compilar usando g++ -std=c++11 main.cpp diffie.cpp
#include "diffie.hpp"

using namespace std;

int main (void){
	unsigned primo = 43;
	unsigned alpha = 23;
	unsigned secreto_a = 25;
	unsigned secreto_b = 33;
	diffie(primo, alpha, secreto_a, secreto_b);
}
