#include "rsa.hpp"
#define alfabeto boost::multiprecision::mpz_int(26)
#define ascii unsigned (65)

rsa::rsa (void){
}

rsa::rsa(boost::multiprecision::mpz_int p, boost::multiprecision::mpz_int q, boost::multiprecision::mpz_int d){
	
	if (lehman(p))
		p_ = p;
	else
		cout << "El numero p: " << p << ", no es primo." << endl;

	if (lehman(q))
		q_ = q;
	else
		cout << "El numero q: " << q << ", no es primo." << endl;

	phi_n_ = (p_-1)*(q_-1);

	if (euclides(phi_n_,d,false)==1)
		d_ = d;
	else
		cout << "El numero d: " << d << ", no es coprimo con " << phi_n_ << endl;

	n_ = p_*q_;
	e_ = euclides(phi_n_,d_,true);
}

rsa::~rsa (void){

}

boost::multiprecision::mpz_int rsa::euclides(boost::multiprecision::mpz_int a, boost::multiprecision::mpz_int b, bool modo){
	boost::multiprecision::mpz_int z_1 = 0, z0 = 1, aux_z=z0;
	boost::multiprecision::mpz_int x0=a, x1=b, aux=b;

	while(x1>0){

		z0 = (-x0/x1) * z0 + z_1;
		z_1 = aux_z;
		aux_z = z0;

		x1 = (x0 % x1);
		x0 = aux;
		aux = x1;
	}

	if(x0!=1)
		cout << "Los números pasados no son coprimos" << endl;
	else{
		if (modo){
			if(z_1<0){
				return ((z_1%a+a)%a);
			}
			else
				return z_1;
		}
		else
			return x0;
	}
}

bool rsa::lehman(boost::multiprecision::mpz_int p){
	vector<boost::multiprecision::mpz_int> ai(100);
	bool es_primo=true;

	for (int i=0; i<ai.size(); i++)
		ai[i] = aleatorio(1,p-1);
	for (int i=0; i<ai.size()&&es_primo;i++){
		if((expo(ai[i],((p-1)/2),p))!=1 && (expo(ai[i],((p-1)/2),p))!=p-1)
			es_primo=false;
	}
	return es_primo;
		
}

boost::multiprecision::mpz_int rsa::aleatorio (boost::multiprecision::mpz_int rg_1, boost::multiprecision::mpz_int rg_2){
	
	uint64_t rgg_1 = uint64_t(rg_1);
	uint64_t rgg_2 = uint64_t(rg_2);

	random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator (http://www.cplusplus.com/reference/random/mersenne_twister_engine/)
    uniform_int_distribution<> distr(rgg_1, rgg_2); // define the range
    return distr(eng);
}

boost::multiprecision::mpz_int rsa::expo(boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_, boost::multiprecision::mpz_int primo_){
	boost::multiprecision::mpz_int x = 1;
	boost::multiprecision::mpz_int y = base%primo_;
	boost::multiprecision::mpz_int copia_sec = exp_;

	while (copia_sec>0 && y>1){
		if (copia_sec%2==1){
			x = (x*y)%primo_;
			copia_sec--;
		}
		else{
			y = (y*y)%primo_;
			copia_sec = copia_sec/2;
		}
	}
	return x;
}

vector<boost::multiprecision::mpz_int> rsa::cifrar (string tx_cf, boost::multiprecision::mpz_int e_del_otro, boost::multiprecision::mpz_int n_del_otro){
	boost::multiprecision::mpz_int j=0;

	boost::to_upper(tx_cf);

	while (pow_multiprecision(alfabeto, j)<n_del_otro)
		j++;

	boost::multiprecision::mpz_int lg_text = tx_cf.length();
	boost::multiprecision::mpz_int size_vector = (lg_text)/(j-1);

	if ((lg_text)%(j-1)!=0)
		size_vector++;

	int tm_vc = int(size_vector);
	vector<string> tx_div(tm_vc);

	for (int i=0; i<tx_div.size(); i++){
		tx_div[i] = tx_cf.substr(i*(int(j)-1),int(j)-1);
		if (i==tx_div.size()-1){
			if (tx_div[i].length()!=(int(j)-1)){
				while (tx_div[i].length()<(int(j)-1))
					tx_div[i].append("A");
			}
		}
	}

	vector<boost::multiprecision::mpz_int> tx_num(tx_div.size());

	boost::multiprecision::mpz_int num=0;
	boost::multiprecision::mpz_int caracter=0;

	for (int i=0; i<tx_num.size(); i++){
		int k = tx_div[i].length()-1;
		num=0;
		for (int j=0; j<tx_div[i].length(); j++){
			caracter = int(tx_div[i][j])-ascii;
			num = num + caracter*pow_multiprecision(alfabeto,k);	
			k--;
		}
		tx_num[i] = num;
	}

	vector<boost::multiprecision::mpz_int> tx_num_cf(tx_num.size());

	for (int i=0; i<tx_num_cf.size(); i++)
		tx_num_cf[i] = expo(tx_num[i], e_del_otro, n_del_otro);

	return tx_num_cf;
}

boost::multiprecision::mpz_int rsa::pow_multiprecision (boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_){
	boost::multiprecision::mpz_int resultado=1;

	for (boost::multiprecision::mpz_int i=0; i<exp_;i++)
		resultado = resultado * base;
	
	return resultado;
}

boost::multiprecision::mpz_int rsa::get_e (void){
	return e_;
}

boost::multiprecision::mpz_int rsa::get_n (void){
	return n_;
}

vector<boost::multiprecision::mpz_int> rsa::descifrado (vector<boost::multiprecision::mpz_int> tx_cifrado, boost::multiprecision::mpz_int n_del_otro){
	vector<boost::multiprecision::mpz_int> tx_descifrado(tx_cifrado.size());

	int w=0,y=0;

	for (int i=0; i<tx_descifrado.size(); i++)
		tx_descifrado[i] = expo(tx_cifrado[i], d_, n_del_otro);

	return tx_descifrado;
}

string rsa::paso_string (vector<boost::multiprecision::mpz_int> tx_descifrado, boost::multiprecision::mpz_int n_del_otro){
	boost::multiprecision::mpz_int j=0;
	int w=0,y=0;
	string salida;

	while (pow_multiprecision(alfabeto, j)<n_del_otro)
		j++;

	vector<boost::multiprecision::mpz_int> num_des(tx_descifrado.size()*(int(j)-1));

	for (int i=0; i<num_des.size(); i++)
		num_des[i] = 0;

	for (int i=0; i<tx_descifrado.size(); i++){
		y=(int(j)-2);
		for (int k=0; k<(int(j)-1); k++){

			if (k==(int(j)-2))
				num_des[w] = tx_descifrado[i];
			else{
				while (num_des[w]*pow_multiprecision(alfabeto,y)<=tx_descifrado[i]){
					num_des[w] = num_des[w]+1;
				}
				//if(num_des[w]!=0)
					num_des[w] = num_des[w]-1;
			}
			if (k!=(int(j)-1))
				tx_descifrado[i] = tx_descifrado[i] - num_des[w]*pow_multiprecision(alfabeto,y);
			w++;
			y--;
		}
	}

	for (int i=0; i<num_des.size(); i++)
		salida += (char(int(num_des[i])+ascii));

	return salida;
}