#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>

using namespace std;

class rsa{
private:
public:
	rsa(void);
	~rsa(void);
	unsigned long euclides(unsigned long a, unsigned long b);
	bool lehman(unsigned long p);
	unsigned long aleatorio(unsigned long rg_1, unsigned long rg_2);
	unsigned long expo(unsigned long base, unsigned long exp_, unsigned long primo_);
};