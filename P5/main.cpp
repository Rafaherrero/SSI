#include "aes.hpp"

using namespace std;

int main (void){
	std::vector<vector<unsigned char>> clave(4, vector<unsigned char>(4));

	clave[0][0] = 0x00;
	clave[1][0] = 0x01;
	clave[2][0] = 0x02;
	clave[3][0] = 0x03;
	clave[0][1] = 0x04;
	clave[1][1] = 0x05;
	clave[2][1] = 0x06;
	clave[3][1] = 0x07;
	clave[0][2] = 0x08;
	clave[1][2] = 0x09;
	clave[2][2] = 0x0A;
	clave[3][2] = 0x0B;
	clave[0][3] = 0x0C;
	clave[1][3] = 0x0D;
	clave[2][3] = 0x0E;
	clave[3][3] = 0x0F;

	std::vector<vector<unsigned char>> texto(4, vector<unsigned char>(4));

	texto[0][0] = 0x00;
	texto[1][0] = 0x11;
	texto[2][0] = 0x22;
	texto[3][0] = 0x33;
	texto[0][1] = 0x44;
	texto[1][1] = 0x55;
	texto[2][1] = 0x66;
	texto[3][1] = 0x77;
	texto[0][2] = 0x88;
	texto[1][2] = 0x99;
	texto[2][2] = 0xAA;
	texto[3][2] = 0xBB;
	texto[0][3] = 0xCC;
	texto[1][3] = 0xDD;
	texto[2][3] = 0xEE;
	texto[3][3] = 0xFF;

	cout << "===============" << " CIFRADO RIJNDAEL " << "===============" << endl;
	cout << "Clave cifrante: ";
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			cout << hex << setfill('0') << setw(2) << int(clave[j][i]);
	}
	cout << endl << "Texto a cifrar: ";
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			cout << hex << setfill('0') << setw(2) << int(texto[j][i]);
	}
	
	aes rij(clave,texto);

}