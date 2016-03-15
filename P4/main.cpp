#include "a5.hpp"

using namespace std;

int main (void){
	std::vector<bool> vector_1 = {1,0,0,0,1,0,1,1,0,0,0,1,0,0,0,1,0,0,1};
	std::vector<bool> vector_2 = {0,1,0,1,1,0,0,1,0,0,0,1,1,1,1,0,0,1,1,0,1,0};
	std::vector<bool> vector_3 = {1,1,1,1,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,1,1,0,1};
	std::vector<unsigned int> datos_vector_1 = {14,17,18,19,9};
	std::vector<unsigned int> datos_vector_2 = {21,22,11};
	std::vector<unsigned int> datos_vector_3 = {8,21,22,23,11};
	a5 A(vector_1, datos_vector_1, vector_2, datos_vector_2, vector_3, datos_vector_3);
	A.imprimir_datos();
	A.generar();
	A.generar();
	// A.generar();
	// A.generar();
	// A.generar();
	// A.generar();
	
	//MODIFICACION PRACTICA
	std::vector<bool> vector_1_mod = {1,0,0,0,1,0,1,1,0,0,0,1,0,0,0,1,0,0,1};
	std::vector<bool> vector_2_mod = {0,1,0,1,1,0,0,1,0,0,0,1,1,1,1,0,0,1,1,0,1,0};
	std::vector<bool> vector_3_mod = {1,1,1,1,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,1,1,0,1};
	std::vector<unsigned int> datos_vector_1_mod = {14,17,18,19,9};
	std::vector<unsigned int> datos_vector_2_mod = {21,22,11};
	std::vector<unsigned int> datos_vector_3_mod = {8,21,22,23,11};
	a5 B(vector_1_mod, datos_vector_1_mod, vector_2_mod, datos_vector_2_mod, vector_3_mod, datos_vector_3_mod,0);
}