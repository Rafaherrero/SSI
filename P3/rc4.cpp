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
	for (int i=0; i<S_.size();i++){
		S_[i] = i;
		K_[i] = semilla[i%semilla.length()];

	}
	int j=0;
	for (int i=0; i<S_.size();i++){
		j = (j+S_[i]+K_[i])%S_.size();
		swap(S_[i],S_[j]);
	}
}

rc4::~rc4(void){

}