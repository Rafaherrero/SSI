#include <vector>
#include <iostream>

using namespace std;

class a5{
private:
	std::vector<bool> v1_;
	std::vector<bool> v2_;
	std::vector<bool> v3_;
	std::vector<unsigned int> datos_v1_;
	std::vector<unsigned int> datos_v2_;
	std::vector<unsigned int> datos_v3_;
public:
	a5 (void);
	a5 (std::vector<bool> vector1,std::vector<unsigned int> datos_vector1, std::vector<bool> vector2,std::vector<unsigned int> datos_vector2, std::vector<bool> vector3, std::vector<unsigned int> datos_vector3);
	a5 (std::vector<bool> vector1,std::vector<unsigned int> datos_vector1, std::vector<bool> vector2,std::vector<unsigned int> datos_vector2, std::vector<bool> vector3, std::vector<unsigned int> datos_vector3, unsigned int mod);
	~a5 (void);
	unsigned int mayoria(void);
	bool generar(void);
	void imprimir_datos(void);
	bool generar_mod(unsigned int registro);
};