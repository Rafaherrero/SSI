//Compilar usando g++ -std=c++11 main.cpp aes.cpp

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

	std::vector<vector<unsigned char>> clave_2(4, vector<unsigned char>(4));

	clave_2[0][0] = 0x00;
	clave_2[1][0] = 0x00;
	clave_2[2][0] = 0x00;
	clave_2[3][0] = 0x00;
	clave_2[0][1] = 0x00;
	clave_2[1][1] = 0x00;
	clave_2[2][1] = 0x00;
	clave_2[3][1] = 0x00;
	clave_2[0][2] = 0x00;
	clave_2[1][2] = 0x00;
	clave_2[2][2] = 0x00;
	clave_2[3][2] = 0x00;
	clave_2[0][3] = 0x00;
	clave_2[1][3] = 0x00;
	clave_2[2][3] = 0x00;
	clave_2[3][3] = 0x00;

	std::vector<vector<unsigned char>> texto_2(4, vector<unsigned char>(4));

	texto_2[0][0] = 0x00;
	texto_2[1][0] = 0x01;
	texto_2[2][0] = 0x02;
	texto_2[3][0] = 0x03;
	texto_2[0][1] = 0x04;
	texto_2[1][1] = 0x05;
	texto_2[2][1] = 0x06;
	texto_2[3][1] = 0x07;
	texto_2[0][2] = 0x08;
	texto_2[1][2] = 0x09;
	texto_2[2][2] = 0x0A;
	texto_2[3][2] = 0x0B;
	texto_2[0][3] = 0x0C;
	texto_2[1][3] = 0x0D;
	texto_2[2][3] = 0x0E;
	texto_2[3][3] = 0x0F;

	cout << endl << "===============" << " CIFRADO RIJNDAEL " << "===============" << endl;
	cout << "Clave cifrante: ";
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			cout << hex << setfill('0') << setw(2) << int(clave_2[j][i]);
	}
	cout << endl << "Texto a cifrar: ";
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			cout << hex << setfill('0') << setw(2) << int(texto_2[j][i]);
	}

	aes rij_2(clave_2,texto_2);

	std::vector<vector<unsigned char>> clave_3(4, vector<unsigned char>(4));

	clave_3[0][0] = 0x00;
	clave_3[1][0] = 0x00;
	clave_3[2][0] = 0x00;
	clave_3[3][0] = 0x00;
	clave_3[0][1] = 0x00;
	clave_3[1][1] = 0x00;
	clave_3[2][1] = 0x00;
	clave_3[3][1] = 0x00;
	clave_3[0][2] = 0x00;
	clave_3[1][2] = 0x00;
	clave_3[2][2] = 0x00;
	clave_3[3][2] = 0x00;
	clave_3[0][3] = 0x00;
	clave_3[1][3] = 0x00;
	clave_3[2][3] = 0x00;
	clave_3[3][3] = 0x00;

	std::vector<vector<unsigned char>> texto_3(4, vector<unsigned char>(4));

	texto_3[0][0] = 0x00;
	texto_3[1][0] = 0x01;
	texto_3[2][0] = 0x02;
	texto_3[3][0] = 0x03;
	texto_3[0][1] = 0x04;
	texto_3[1][1] = 0x05;
	texto_3[2][1] = 0x06;
	texto_3[3][1] = 0x07;
	texto_3[0][2] = 0x08;
	texto_3[1][2] = 0x09;
	texto_3[2][2] = 0x0A;
	texto_3[3][2] = 0x0B;
	texto_3[0][3] = 0x0C;
	texto_3[1][3] = 0x0D;
	texto_3[2][3] = 0x0E;
	texto_3[3][3] = 0x0F;

	cout << endl << "===============" << " CIFRADO RIJNDAEL " << "===============" << endl;
	cout << "Clave cifrante: ";
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			cout << hex << setfill('0') << setw(2) << int(clave_3[j][i]);
	}
	cout << endl << "Texto a cifrar: ";
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			cout << hex << setfill('0') << setw(2) << int(texto_3[j][i]);
	}

	aes rij_3(clave_3,texto_3);
}