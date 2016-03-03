#include "rc4.hpp"

using namespace std;

int main (void){
	string semilla;
	semilla+=2;
	semilla+=5;
	string msg;
	msg+=1;
	msg+=34;
	rc4 A(semilla);
	cout << A.cifrar(msg) << endl;
}