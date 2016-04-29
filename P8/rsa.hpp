#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class rsa{
private:
public:
	rsa(void);
	rsa(unsigned long a, unsigned long b);
	~rsa(void);
	unsigned long euclides(unsigned long a, unsigned long b);
};