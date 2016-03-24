#include "aes.hpp"

using namespace std;

aes::aes (void)
{}

//Constructor que recibe la clave y el texto a cifrar, y genera en su clase una copia del texto y del texto cifrado
//Ademas, inicializa un vector tridimensional que almacenaran las 11 subclaves, las cuales estan formadas por vectores bidimensionales de 4x4
//Se inicializa el contador de iteraciones a 0 y se llama al metodo encriptar
aes::aes(std::vector<vector<unsigned char>> cl, std::vector<vector<unsigned char>> tx):
clave_(cl),
texto_(tx),
texto_cf_(tx),
clave_exp_ (std::vector<vector<vector<unsigned char>>>(11, vector<vector<unsigned char>>(4, vector<unsigned char>(4)))),
iter_(0)
{
	encriptar();
}

aes::~aes (void){
}

//Método que expande la clave
void aes::expan_clave(void){

	//Variables auxiliares
	unsigned char col_ant[4],copia;

	//La primera matrix de 4x4 de la clave expandida es la misma que la de la clave cifrante, por lo que la copiamos tal cual
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			clave_exp_[0][j][i] = clave_[j][i];
	}

	//Para las siguiente diez iteraciones realizamos el siguiente bucle 
	for (int i=1; i<=10; i++){

		//En el caso de la primera columna de cada columna, copiamos la columna anterior en una variable de copia
		for (int j=0; j<4; j++)
			col_ant[j]=clave_exp_[i-1][j][3];

		//La variable que contiene que contiene la columna anterior la desplazamos a un byte superior de forma ciclica, por lo que el primero pasa a ser el ultimo
		copia = col_ant[0];
		col_ant[0] = col_ant[1];
		col_ant[1] = col_ant[2];
		col_ant[2] = col_ant[3];
		col_ant[3] = copia;

		//Una vez rotados, sustituimos por el byte de su posición correspondiente en la Caja S
		col_ant[0] = cajaS_[col_ant[0]];
		col_ant[1] = cajaS_[col_ant[1]];
		col_ant[2] = cajaS_[col_ant[2]];
		col_ant[3] = cajaS_[col_ant[3]];

		//Al primer byte el aplicamos XOR con la posición correspondiente en la Caja RCon
		col_ant[0] = col_ant[0] ^ cajaRcon_[i];

		//Cuando hayamos realizado todo lo anterior, tenemos que sustituir los bytes de la clave expandida con los de la matriz anterior de la clave expandida
		//y con los bytes calculados realizando un XOR
		clave_exp_[i][0][0] = clave_exp_[i-1][0][0] ^ col_ant[0];
		clave_exp_[i][1][0] = clave_exp_[i-1][1][0] ^ col_ant[1];
		clave_exp_[i][2][0] = clave_exp_[i-1][2][0] ^ col_ant[2];
		clave_exp_[i][3][0] = clave_exp_[i-1][3][0] ^ col_ant[3];

		//Lo realizado anteriormente solo afecta a la primera columna de la matriz, mientras que lo que viene a continuacion afecta al resto de columnas
		//Recorremos las columnas de la 2 a la 4, ambas inclusive
		for (int j=1; j<4; j++){
			//Recorremos cada fila copiando en una variable auxiliar la columna de la matriz anterior
			for (int k=0; k<4; k++){
				col_ant[k]=clave_exp_[i-1][k][j];
			}
			//Recorremos cada fila de la matriz de la clave expandida, almacenando en ella el resultado de aplicar un XOR entre la columna anterior y la de la matriz anterior
			for (int k=0; k<4; k++){
				clave_exp_[i][k][j] = clave_exp_[i][k][j-1] ^ col_ant[k];
			}
		}
	}
}

//Metodo que aplica una XOR al texto cifrado con la clave expandida
void aes::addRoundKey(void){
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			texto_cf_[j][i] = texto_cf_[j][i] ^ clave_exp_[iter_][j][i];
		}
	}
}

//Metodo que sustituye un byte del texto cifrado por su correspondiente en la Caja S
void aes::subBytes(void){
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			texto_cf_[j][i] = cajaS_[texto_cf_[j][i]];
		}
	}
}

//Metodo que mueve bytes a la izquierda las matrices del texto cifrado
void aes::shiftRow(void){
	unsigned char copia;

	copia = texto_cf_[1][0];
	texto_cf_[1][0] = texto_cf_[1][1];
	texto_cf_[1][1] = texto_cf_[1][2];
	texto_cf_[1][2] = texto_cf_[1][3];
	texto_cf_[1][3] = copia;

	copia = texto_cf_[2][0];
	texto_cf_[2][0] = texto_cf_[2][2];
	texto_cf_[2][2] = copia;
	copia = texto_cf_[2][1];
	texto_cf_[2][1] = texto_cf_[2][3];
	texto_cf_[2][3] = copia;

	copia = texto_cf_[3][0];
	texto_cf_[3][0] = texto_cf_[3][3];
	texto_cf_[3][3] = texto_cf_[3][2];
	texto_cf_[3][2] = texto_cf_[3][1];
	texto_cf_[3][1] = copia;
}

//Metodo que aplica una transformacion lineal al texto cifrado
void aes::mixColumn(void){

	//Variables auxiliares
	unsigned char a[4];
	unsigned char b[4];
	unsigned char h;

	//Doble bucle para recorrer una matriz completa de una sola llamada al metodo
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			
			//Copiamos en a el texto cifrado
			a[j] = texto_cf_[j][i];

			//Multiplicacion entre el byte del texto cifrado y 128 para comprobar si el byte del texto es mayor que 128
			h = texto_cf_[j][i] & 0x80; 

			//Multiplicamos por 2 (desplazamos un byte) el byte del texto cifrado y lo dejamos en la variable auxiliar b
			b[j] = texto_cf_[j][i] << 1;

			//En caso de que el byte sea mayor de 127 aplicamos una XOR con 27
			if(h == 0x80)
				b[j] = b[j] ^0x1b;
		}

		//Realizamos todas las XOR correspondientes para cada uno de los elementos de nuestra columna, ya que cada fila tiene un valor distinto
		texto_cf_[0][i] = b[0] ^ a[3] ^ a[2] ^ b[1] ^ a[1];
		texto_cf_[1][i] = b[1] ^ a[0] ^ a[3] ^ b[2] ^ a[2];
		texto_cf_[2][i] = b[2] ^ a[1] ^ a[0] ^ b[3] ^ a[3];
		texto_cf_[3][i] = b[3] ^ a[2] ^ a[1] ^ b[0] ^ a[0];
	}
}

//Metodo que se encarga de llamar a los metodos para realizar el encriptado completo
void aes::encriptar(void){

	//En la iteracion 0 solo expandimos la clave y aplicamos una XOR al texto cifrado con la clave expandida
	expan_clave();
	addRoundKey();

	//Informacion para imprimir por pantalla
	cout << endl << endl << "=================" << " Iteracción 0 " << "=================" << endl;
	cout << "Subclave 0:     ";
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			cout << hex << setfill('0') << setw(2) << int(clave_exp_ [0][j][i]);
	}
	cout << endl << "Texto cifrado:  ";
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			cout << hex << setfill('0') << setw(2) << int(texto_cf_[j][i]);
	}

	//Llamamos a cada metodo por separado 9 veces. Se aumenta el contador de iteraciones, necesario para moverse por la clave expandida
	for (int i=1;i<10;i++){
		iter_++;
		subBytes();
		shiftRow();
		mixColumn();
		addRoundKey();

		//Informacion para imprimir por pantalla
		cout << endl << endl << "=================" << " Iteracción " << iter_ << " =================" << endl;
		cout << "Subclave " << iter_ << ":     ";
		for (int i=0; i<4; i++){
			for (int j=0; j<4; j++)
				cout << hex << setfill('0') << setw(2) << int(clave_exp_ [iter_][j][i]);
		}
		cout << endl << "Texto cifrado:  ";
		for (int i=0; i<4; i++){
			for (int j=0; j<4; j++)
				cout << hex << setfill('0') << setw(2) << int(texto_cf_[j][i]);
		}
	}

	//En la ultima iteracion aplicamos los mismos metodos que antes, salvo que ahora no realizamos 
	iter_++;
	subBytes();
	shiftRow();
	addRoundKey();

	//Informacion para imprimir por pantalla
	cout << endl << endl << "=================" << " Iteracción 10 " << "=================" << endl;
	cout << "Subclave 10:     ";
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			cout << hex << setfill('0') << setw(2) << int(clave_exp_ [iter_][j][i]);
	}
	cout << endl << "Texto cifrado:   ";
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			cout << hex << setfill('0') << setw(2) << int(texto_cf_[j][i]);
	}
	cout << endl;
}