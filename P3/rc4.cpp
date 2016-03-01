#include "rc4.hpp"

using namespace std;

rc4::rc4 (void):
S_(0),
K_(0)
{}

rc4::rc4 (string semilla):
S_(256, 0),
K_(256, 0)
{
	for (int i=0; i<=S_.length();i++){
		S[i] = i;
		K[i] = semilla[i%semilla.length()];
	}
	j=0;
	for (int i=0; i<S_.length();i++){
		j = (j+S_[i]+K_[i])%S_.length();
		swap(S_[i],S_[j]);
	}
}