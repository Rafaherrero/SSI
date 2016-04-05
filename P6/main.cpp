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
	
	aes rij(clave,texto,0);

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

	aes rij_2(clave_2,texto_2,0);

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

	aes rij_3(clave_3,texto_3,0);

	//AQUI SE ENCUENTRA LA MODIFICACION DE LA PRACTICA DEL CBC
	cout << endl << "===========" << " MODIFICACION PRACTICA 6 CBC " << "===========" << endl;

	std::vector<vector<unsigned char>> clave_4(4, vector<unsigned char>(4));

	clave_4[0][0] = 0xC7;
	clave_4[1][0] = 0x38;
	clave_4[2][0] = 0xE1;
	clave_4[3][0] = 0x83;
	clave_4[0][1] = 0x44;
	clave_4[1][1] = 0x56;
	clave_4[2][1] = 0xF9;
	clave_4[3][1] = 0x15;
	clave_4[0][2] = 0xF3;
	clave_4[1][2] = 0x7E;
	clave_4[2][2] = 0x20;
	clave_4[3][2] = 0x8D;
	clave_4[0][3] = 0x90;
	clave_4[1][3] = 0x34;
	clave_4[2][3] = 0x1B;
	clave_4[3][3] = 0x2B;

	std::vector<vector<vector<unsigned char>>> textos(2, vector<vector<unsigned char>>(4, vector<unsigned char>(4)));

	textos[0][0][0] = 0xE8;
	textos[0][1][0] = 0xB1;
	textos[0][2][0] = 0x1B;
	textos[0][3][0] = 0xEA;
	textos[0][0][1] = 0x4A;
	textos[0][1][1] = 0x65;
	textos[0][2][1] = 0x9A;
	textos[0][3][1] = 0x7E;
	textos[0][0][2] = 0x22;
	textos[0][1][2] = 0x4F;
	textos[0][2][2] = 0x92;
	textos[0][3][2] = 0x4B;
	textos[0][0][3] = 0xDA;
	textos[0][1][3] = 0x8D;
	textos[0][2][3] = 0x72;
	textos[0][3][3] = 0x39;

	textos[1][0][0] = 0xDA;
	textos[1][1][0] = 0x47;
	textos[1][2][0] = 0x51;
	textos[1][3][0] = 0x74;
	textos[1][0][1] = 0x9A;
	textos[1][1][1] = 0x1D;
	textos[1][2][1] = 0x45;
	textos[1][3][1] = 0xC9;
	textos[1][0][2] = 0x2B;
	textos[1][1][2] = 0x11;
	textos[1][2][2] = 0x43;
	textos[1][3][2] = 0x22;
	textos[1][0][3] = 0xE5;
	textos[1][1][3] = 0x10;
	textos[1][2][3] = 0x36;
	textos[1][3][3] = 0x65;

	std::vector<vector<unsigned char>> clave_anterior(4, vector<unsigned char>(4));

	clave_anterior[0][0] = 0x00;
	clave_anterior[1][0] = 0x00;
	clave_anterior[2][0] = 0x00;
	clave_anterior[3][0] = 0x00;
	clave_anterior[0][1] = 0x00;
	clave_anterior[1][1] = 0x00;
	clave_anterior[2][1] = 0x00;
	clave_anterior[3][1] = 0x00;
	clave_anterior[0][2] = 0x00;
	clave_anterior[1][2] = 0x00;
	clave_anterior[2][2] = 0x00;
	clave_anterior[3][2] = 0x00;
	clave_anterior[0][3] = 0x00;
	clave_anterior[1][3] = 0x00;
	clave_anterior[2][3] = 0x00;
	clave_anterior[3][3] = 0x00;

	cout << "Clave cifrante:    ";
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			cout << hex << setfill('0') << setw(2) << int(clave_4[j][i]);
	}
	cout << endl;

	for (int i=0; i<2; i++){
	cout << endl << "Texto a cifrar:    ";
	for (int j=0; j<4; j++){
		for (int k=0; k<4; k++)
			cout << hex << setfill('0') << setw(2) << int(textos[i][k][j]);
	}
	cout << endl << "Texto anterior:    ";
	for (int j=0; j<4; j++){
		for (int k=0; k<4; k++)
			cout << hex << setfill('0') << setw(2) << int(clave_anterior[k][j]);
	}
		aes rij_4(clave_4,textos[i],clave_anterior);
		clave_anterior = rij_4.get_clave_anterior();

	cout << endl << "Bloque " << i+1 << " cifrado:  ";
	for (int j=0; j<4; j++){
		for (int k=0; k<4; k++)
			cout << hex << setfill('0') << setw(2) << int(clave_anterior[k][j]);
	}
	cout << endl;
	}

	//AQUI SE ENCUENTRA LA MODIFICACION DE LA PRACTICA DEL CIPHER STEALING

	cout << endl << "=================" << " MODIFICACION PRACTICA 6 CS " << "=================" << endl;

	for (int i=0; i<2; i++){
		aes rij_5(clave_4, textos[i], 1);
		

		cout << "Texto a cifrar " << i+1 << ":             ";
		for (int j=0; j<4; j++){
			for (int k=0; k<4; k++)
				cout << hex << setfill('0') << setw(2) << int(textos[i][k][j]);
		}

		textos[i] = rij_5.get_texto_encriptado();

		cout << endl << "Texto cifrado " << i+1 << ":              ";
		for (int j=0; j<4; j++){
			for (int k=0; k<4; k++)
				cout << hex << setfill('0') << setw(2) << int(textos[i][k][j]);
		}

		if (i<1){

			cout << endl << "Texto a cifrar " << i+2 << " sin alterar: ";
			for (int j=0; j<4; j++){
				for (int k=0; k<4; k++)
					cout << hex << setfill('0') << setw(2) << int(textos[i+1][k][j]);
			}

			textos[i+1][2][3] = textos[i][2][3];
			textos[i+1][3][3] = textos[i][3][3];
		}
		cout << endl;
	}
	swap(textos[1],textos[0]);

	cout << endl << "Comprobación de swap";
	for (int i=0; i<2; i++){
		cout << endl << "Texto " << i+1	 << " listo para cifrar: ";
	for (int j=0; j<4; j++){
		for (int k=0; k<4; k++)
			cout << hex << setfill('0') << setw(2) << int(textos[i][k][j]);
		}
	}
	cout << endl;
}