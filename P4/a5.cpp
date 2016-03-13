#include "a5.hpp"

using namespace std;

a5::a5 (void):
v1_(0),
v2_(0),
v3_(0)
{
}

a5::~a5(void){

}

void a5::prueba(void){
	v1_.resize(8);
	v1_ = {0,1,0,0,1,1,1,0};

	for (int i=0;i<v1_.size();i++)
		cout << v1_[i] << ", ";

	v1_.push_back(v1_.front());
	v1_.erase(v1_.begin());

	cout << endl << endl;

	for (int i=0;i<v1_.size();i++)
		cout << v1_[i] << ", ";

	v1_.push_back(v1_.front());
	v1_.erase(v1_.begin());

	cout << endl << endl;

	for (int i=0;i<v1_.size();i++)
		cout << v1_[i] << ", ";
}