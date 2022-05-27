#include <string>
#include <cstring>
#include "cifrados2.h"
using namespace std;


int main(){
	cout<<"\n"<<endl;

	string msg_original = "";
	cout << "Ingresar frase a cifrar (sin espacios): "; cin >> msg_original;
	cout<<"Mensaje original: "<<msg_original<<endl;

	poliAlf emisor;
	poliAlf receptor;

	string word0;
	cout << "Ingresar clave para cifrar (string): "; cin >> word0; cout<<endl;
	emisor.setKeyWord(word0);
	receptor.setKeyWord(word0);

	string msg_cifrado = emisor.encrypt(msg_original);
	cout<<"Mensaje cifrado: "<<msg_cifrado<<endl;

	string msg_descifrado = receptor.descifrar(msg_cifrado);
	cout<<"Mensaje descifrado: "<<msg_descifrado<<endl<<endl;

	return 0;
}