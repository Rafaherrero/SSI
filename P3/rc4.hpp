#include <vector>
#include <iostream>

using namespace std;

class rc4{
private:
	std::vector<unsigned char> S_;
	std::vector<unsigned char> K_;
	std::vector<unsigned char> secuencia_;
	int i_,j_,k_;
	unsigned t_;
public:
	rc4(void);
	rc4(std::vector<unsigned char> semilla);
	~rc4 (void);
	unsigned char prga(void);
	unsigned char prga_mod(void);
	std::vector<unsigned char> cifrar (std::vector<unsigned char> mensaje);
	std::vector<unsigned char> secuencia (void);

	std::vector<unsigned char> cifrar_mod (std::vector<unsigned char> mensaje);
};