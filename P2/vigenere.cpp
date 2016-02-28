#include "vigenere.hpp"

//Constructor por defecto que no almacena nada en los atributos
vigenere::vigenere(void):
mensaje_(""),
clave_(""),
mensaje_cifrado_("")
{}

//Constructor que recibe como parametros un mensaje sin cifrar y una clave para cifrar
vigenere::vigenere(string clave_cifrar, string mensaje_sin_cifrar):
mensaje_(mensaje_sin_cifrar),
clave_(clave_cifrar),
mensaje_cifrado_("")
{
	//Llamada al metodo corrector para almacenar en la clase el mensaje bien formateado
	corrector();

	//Llamada al metodo cifrar para almacenar en la clase el mensaje cifrado
	cifrar();
}

//Destructor que elimina los 3 atributos de la clase
vigenere::~vigenere (void){
	mensaje_.clear();
	clave_.clear();
	mensaje_cifrado_.clear();
}

//Metodo que da formato al mensaje almacenado en la clase
void vigenere::corrector (void){

	//Si el mensaje no es mayor que la clave, no damos formato
	if (!(mensaje_.length()>=clave_.length())){
		cerr << "El mensaje no es mayor o igual que la clave. " << endl;
	}
	else{

		//Eliminamos los espacios del mensaje sin cifrar
		mensaje_.erase(remove(mensaje_.begin(),mensaje_.end(),' '),mensaje_.end());

		//Convertimos en mayuscula el mensaje y si no se encuentra entre A y Z almacenamos un interrogante
		for (int i=0; i<mensaje_.length();i++){
			mensaje_[i] = toupper(mensaje_[i]);
			if (!((mensaje_[i] >= 'A')&&(mensaje_[i] <='Z')))
				mensaje_[i]='?';
		}

		//Eliminamos los espacios de la clave
		clave_.erase(remove(clave_.begin(),clave_.end(),' '),clave_.end());

		//Convertimos en mayucula la clave y si no se encuentra entre A y Z almacenamos un interrogante
		for (int i=0; i<clave_.length();i++){
			clave_[i] = toupper(clave_[i]);
			if (!((clave_[i] >= 'A')&&(clave_[i] <='Z')))
				clave_[i]='?';
		}
	}
}

//Metodo que devuelve el atributo privado que almacena el mensaje ya con formato
string vigenere::imprimir_formato(void){
	return mensaje_;
}

//Metodo que devuelve el atributo privado que almacena el mensaje cifrado
string vigenere::imprimir_cifrado (void){
	return mensaje_cifrado_;
}

//Metodo para cifrar los mensajes
void vigenere::cifrar (void){
	int j, caracter = 0;
	for (int i=0; i<mensaje_.length();i++){
		//Repetimos el cifrado con la clave una y otra vez
		if (j>=clave_.length()){
			j=0;
		}

		//Si lo que tenemos no es un interrogante, ciframos
		if (mensaje_[i]!='?'){
			//Sumamos las posiciones de los caracteres del mensaje y de la clave
			caracter = ((mensaje_[i]-65)+(clave_[j]-65));
		//Si el resultado sobrepasa el alfabeto, le restamos el tamano del mismo
		if (caracter>=26)
			caracter=caracter-26;
		//Devolvemos el caracter a su valor ASCII
		caracter = caracter+65;
		}
		else{
			//Si lo que teniamos era un interrogante en el mensaje, no hacemos nada
			caracter = mensaje_[i];
		}
		j++;
		//Añadimos los caracteres al atributo del mensaje cifrado
		mensaje_cifrado_.append(string(1, (char)(caracter)));
	}
}

//Metodo para descifrar los mensajes
string vigenere::descifrar (void){
	int j, caracter = 0;
	string mensaje_descifrado;
	for (int i=0; i<mensaje_cifrado_.length();i++){
		//Repetimos el des cifrado con la clave una y otra vez
		if (j>=clave_.length()){
			j=0;
		}
		//Si lo que tenemos no es un interrogante, desciframos
		if (mensaje_cifrado_[i]!='?'){
			//Restamos las posiciones de los caracteres del mensaje y de la clave
			caracter = ((mensaje_cifrado_[i]-65)-(clave_[j]-65));
		//Si el resultado es menor que la posicion de la A, le sumamos el tamano del alfabeto
		if (caracter<0)
			caracter=caracter+26;
		//Devolvemos el caracter a su valor ASCII
		caracter = caracter+65;
		}
		else{
			//Si lo que teniamos era un interrogante en el mensaje, no hacemos nada
			caracter = mensaje_[i];
		}
		j++;
		//Añadimos los caracteres al atributo del mensaje descifrado
		mensaje_descifrado.append(string(1, (char)(caracter)));
	}
	//Devolvemos el valor del atributo del mensaje descifrado
	return mensaje_descifrado;
}

//Mismo metodo que corrector(void), salvo que ahora lo hace con los parametros que le pasemos
void vigenere::corrector (string& mensaje_df, string& clave_cf){
	if (!(mensaje_df.length()>=clave_cf.length())){
		cerr << "El mensaje no es mayor o igual que la clave. " << endl;
	}
	else{
		mensaje_df.erase(remove(mensaje_df.begin(),mensaje_df.end(),' '),mensaje_df.end());

		for (int i=0; i<mensaje_df.length();i++){
			mensaje_df[i] = toupper(mensaje_df[i]);
			if (!((mensaje_df[i] >= 'A')&&(mensaje_df[i] <='Z')))
				mensaje_df[i]='?';
		}

		clave_cf.erase(remove(clave_cf.begin(),clave_cf.end(),' '),clave_cf.end());

		for (int i=0; i<clave_cf.length();i++){
			clave_cf[i] = toupper(clave_cf[i]);
			if (!((clave_cf[i] >= 'A')&&(clave_cf[i] <='Z')))
				clave_cf[i]='?';
		}
	}
}

//Mismo metodo que cifrar(void), salvo que ahora lo hace con los parametros que le pasemos
string vigenere::cifrar (string mensaje_df, string clave_cf){
	int j, caracter = 0;
	corrector (mensaje_df,clave_cf);
	string mensaje_cf;
	for (int i=0; i<mensaje_df.length();i++){
		if (j>=clave_cf.length()){
			j=0;
		}

		if (mensaje_df[i]!='?'){
			caracter = ((mensaje_df[i]-65)+(clave_cf[j]-65));
		if (caracter>=26)
			caracter=caracter-26;
		caracter = caracter+65;
		}
		else{
			caracter = mensaje_df[i];
		}

		j++;
		mensaje_cf.append(string(1, (char)(caracter)));
	}
	return mensaje_cf;
}

//Mismo metodo que descifrar(void), salvo que ahora lo hace con los parametros que le pasemos
string vigenere::descifrar (string mensaje_cf, string clave_descifrar){
	int j, caracter = 0;
	string mensaje_descifrado;
	for (int i=0; i<mensaje_cf.length();i++){
		if (j>=clave_descifrar.length()){
			j=0;
		}

		if (mensaje_cf[i]!='?'){
			caracter = ((mensaje_cf[i]-65)-(clave_descifrar[j]-65));
		if (caracter<0)
			caracter=caracter+26;
		caracter = caracter+65;
		}
		else{
			caracter = mensaje_[i];
		}

		j++;
		mensaje_descifrado.append(string(1, (char)(caracter)));
	}
	return mensaje_descifrado;
}