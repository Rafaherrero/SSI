#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class diffie{
private:
	unsigned primo_, alpha_, secreto_a_, secreto_b_;
public:
	diffie(void);
	diffie(unsigned pr_, unsigned al_, unsigned sec_a_, unsigned sec_b_);
	~diffie(void);
	bool es_primo(unsigned pr_);
};