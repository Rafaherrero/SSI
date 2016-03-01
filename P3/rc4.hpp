#include <vector>

using namespace std;

class rc4{
private:
	std::vector<unsigned char> S_;
	std::vector<unsigned char> K_;
public:
	rc4(void);
	rc4(string semilla);
	~rc4 (void);
};