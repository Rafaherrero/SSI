#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class diffie{
private:
	unsigned primo_, alpha_, secreto_, y_;
public:
	diffie(void);
	diffie(unsigned pr_, unsigned al_, unsigned sec_);
	~diffie(void);
	bool es_primo(unsigned pr_);
	unsigned calculo(unsigned base, unsigned exp_);
	unsigned get_y(void);
	unsigned get_secreto(void);
};