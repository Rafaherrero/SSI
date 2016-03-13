#include "a5.hpp"

using namespace std;

a5::a5 (void):
v1_(0),
v2_(0),
v3_(0)
{}

a5::a5 (std::vector<bool> vector1,std::vector<unsigned int> datos_vector1, std::vector<bool> vector2,std::vector<unsigned int> datos_vector2, std::vector<bool> vector3, std::vector<unsigned int> datos_vector3):
v1_(vector1),
v2_(vector2),
v3_(vector3),
datos_v1_(datos_vector1),
datos_v2_(datos_vector2),
datos_v3_(datos_vector3)
{}

a5::~a5(void){

}

unsigned int a5::mayoria(void){
	
	if (((v1_[datos_v1_.back()-1]==1)&&(v2_[datos_v2_.back()-1]==1)&&(v3_[datos_v3_.back()-1]==1))||((v1_[datos_v1_.back()-1]==0)&&(v2_[datos_v2_.back()-1]==0)&&(v3_[datos_v3_.back()-1]==0))){
		return 123;
	}
	else if (((v1_[datos_v1_.back()-1]==1)&&(v2_[datos_v2_.back()-1]==1)&&(v3_[datos_v3_.back()-1]==0))||((v1_[datos_v1_.back()-1]==0)&&(v2_[datos_v2_.back()-1]==0)&&(v3_[datos_v3_.back()-1]==1))){
		return 12;
	}
	else if (((v1_[datos_v1_.back()-1]==1)&&(v2_[datos_v2_.back()-1]==0)&&(v3_[datos_v3_.back()-1]==0))||((v1_[datos_v1_.back()-1]==0)&&(v2_[datos_v2_.back()-1]==1)&&(v3_[datos_v3_.back()-1]==1))){
		return 23;
	}
	else{
		return 13;
	}
}

bool a5::generar(void){
	unsigned int registro_mover=mayoria();
	bool meter_1, meter_2, meter_3, devolver;

	if (registro_mover!=123&&registro_mover!=12&&registro_mover!=23&&registro_mover!=13)
		cout << "HAY UN ERROR EN LOS REGISTROS!!!" << endl;
	else{
		devolver = v1_.back() ^ v2_.back() ^ v3_.back();
		meter_1 = v1_[datos_v1_[0]-1];
		meter_2 = v2_[datos_v2_[0]-1];
		meter_3 = v3_[datos_v3_[0]-1];
	}
	if (registro_mover==123){
		
		for (int i=1; i<datos_v1_.size()-1;i++)
			meter_1 = meter_1 ^ v1_[datos_v1_[i]];

		for (int i=1; i<datos_v2_.size()-1;i++)
			meter_2 = meter_2 ^ v2_[datos_v2_[i]];

		for (int i=1; i<datos_v3_.size()-1;i++)
			meter_3 = meter_3 ^ v3_[datos_v3_[i]];
	}
	else if (registro_mover==12){
		
		for (int i=1; i<datos_v1_.size()-1;i++)
			meter_1 = meter_1 ^ v1_[datos_v1_[i]];
		
		for (int i=1; i<datos_v2_.size()-1;i++)
			meter_2 = meter_2 ^ v2_[datos_v2_[i]];
		v1_.erase(v1_.begin());
		v1_.push_back(meter_1);
		v2_.erase(v2_.begin());
		v2_.push_back(meter_2);
	}
	else if (registro_mover==13){

		for (int i=1; i<datos_v1_.size()-1;i++)
			meter_1 = meter_1 ^ v1_[datos_v1_[i]];

		for (int i=1; i<datos_v3_.size()-1;i++)
			meter_3 = meter_3 ^ v3_[datos_v3_[i]];
	}
	else{

		for (int i=1; i<datos_v2_.size()-1;i++)
			meter_2 = meter_2 ^ v2_[datos_v2_[i]];

		for (int i=1; i<datos_v3_.size()-1;i++)
			meter_3 = meter_3 ^ v3_[datos_v3_[i]];
	}
	return devolver;
}