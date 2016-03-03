#include <vector>
#include <iostream>

using namespace std;

class rc4{
private:
	std::vector<unsigned char> S_;
	std::vector<unsigned char> K_;
	int i_,j_;
public:
	rc4(void);
	rc4(string semilla);
	~rc4 (void);
	unsigned char prga(void);
	string cifrar (string mensaje);
};