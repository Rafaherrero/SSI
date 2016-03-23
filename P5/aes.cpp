#include "aes.hpp"

using namespace std;

aes::aes (void)
{}

aes::aes(std::vector<vector<unsigned char>> cl, std::vector<vector<unsigned char>> tx):
clave_(cl),
texto_(tx),
clave_exp_ (std::vector<vector<vector<unsigned char>>>(11, vector<vector<unsigned char>>(4, vector<unsigned char>(4)))),
iter_(0)
{
	expan_clave();
}

aes::~aes (void){

}

void aes::expan_clave(void){

	unsigned char col_ant[4],copia;

	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			clave_exp_[0][j][i] = clave_[j][i];
	}

	for (int i=1; i<11; i++){

		for (int j=0; j<4; j++)
			col_ant[j]=clave_exp_[i-1][j][3];

		copia = col_ant[0];
		col_ant[0] = col_ant[1];
		col_ant[1] = col_ant[2];
		col_ant[2] = col_ant[3];
		col_ant[3] = copia;

		col_ant[0] = cajaS_[col_ant[0]];
		col_ant[1] = cajaS_[col_ant[1]];
		col_ant[2] = cajaS_[col_ant[2]];
		col_ant[3] = cajaS_[col_ant[3]];

		col_ant[0] = col_ant[0] ^ cajaRcon_[i];

		clave_exp_[i][0][0] = clave_exp_[i-1][0][0] ^ col_ant[0];
		clave_exp_[i][1][0] = clave_exp_[i-1][1][0] ^ col_ant[1];
		clave_exp_[i][2][0] = clave_exp_[i-1][2][0] ^ col_ant[2];
		clave_exp_[i][3][0] = clave_exp_[i-1][3][0] ^ col_ant[3];

		for (int j=1; j<4; j++){
			for (int k=0; k<4; k++){
				col_ant[k]=clave_exp_[i-1][k][j];
			}
			for (int k=0; k<4; k++){
				clave_exp_[i][k][j] = clave_exp_[i][k][j-1] ^ col_ant[k];
			}
		}

		cout << " " << hex << int(clave_exp_[i][0][0]) << " " << int(clave_exp_[i][1][0]) << " " << int(clave_exp_[i][2][0]) << " " << int(clave_exp_[i][3][0]) << endl;
		cout << " " << hex << int(clave_exp_[i][0][1]) << " " << int(clave_exp_[i][1][1]) << " " << int(clave_exp_[i][2][1]) << " " << int(clave_exp_[i][3][1]) << endl;
		cout << " " << hex << int(clave_exp_[i][0][2]) << " " << int(clave_exp_[i][1][2]) << " " << int(clave_exp_[i][2][2]) << " " << int(clave_exp_[i][3][2]) << endl;
		cout << " " << hex << int(clave_exp_[i][0][3]) << " " << int(clave_exp_[i][1][3]) << " " << int(clave_exp_[i][2][3]) << " " << int(clave_exp_[i][3][3]) << endl;
		cout << endl;

	}
}