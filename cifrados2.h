#pragma once
#include <iostream>
#include <string>
using namespace std;

string const abc_mayus = "ABCDEFGHIJKLMN_OPQRSTUVWXYZ";
string const abc_minus = "abcdefghijklmn_opqrstuvwxyz";

void swap(int* a, int* b) {
    int x = *a;
    *a = *b;
    *b = x;
}

int moduloFunc(int a, int b) {
    int q = a / b;
    int r = a - (q * b);

    if (r < 0) {
        q--;
        r = a - (q * b);
    }

    return r;
    /*
   return a%b;
    */
}

int euclides_largo(int a, int b, int& x, int& y) {

    if (a < b) swap(a, b);

    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int mcd = euclides_largo(b, a % b, x1, y1);


    x = y1;
    y = x1 - (a / b) * y1;

    return mcd;
}

int euclides_largo2(int a, int b, int& x, int& y) {
    //if(a<b) {swap(a,b)};
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int mcd = euclides_largo2(b, a % b, x1, y1);


    x = y1;
    y = x1 - (a / b) * y1;

    return x;
}

int inversa(int a, unsigned int b) {
    int xTemp, yTemp;
    if (euclides_largo(a, b, xTemp, yTemp) == 1) {
        int x_temp, y_temp, x;
        x = euclides_largo2(a, b, x_temp, y_temp);

        return (moduloFunc(x, b));
    }
    else {
        cout << a << " no tiene inverso." << endl;
        return 0;
    }
}


class poliAlf {
    string clave_word;      // Palabra con la cual cifrar, ej: SOL
    string msg_clave = "";  // Frase SOLSOLSO, length = msg original
public:
    poliAlf() {
        string word_0 = "";
    }

    /*
    string getsetWord0(){
        string word0;
        cout << "Ingresar clave para cifrar (string): "; cin >> word0;
        clave_word = word0;
        return clave_word;
    }
    */

    string setKeyWord(string text){
        clave_word = text;
        return clave_word;
    }

    string encrypt_word_fill(string msg_original) {
        int counter = 0;
        for(int i = 0; i < msg_original.length(); i++){
            if( msg_original[i] == ' '){
                msg_clave += " ";
                continue;
            }
            if( counter == clave_word.length() ){ counter -= (clave_word.length()); }
            msg_clave += clave_word[counter];
            counter++;
        }
        //cout<<msg_clave<<endl;
        return msg_clave;
    }

    int modulo(int a, int b) {
        return moduloFunc(a, b);
    }

    int getIndexABC(char msg_char){
        for(int i=0; i<abc_mayus.length(); i++){
            if(msg_char == abc_mayus[i] || msg_char == abc_minus[i]){
                return i;}
        }
        return -1;
    }


    string encrypt(string msg) {
        string encriptado(msg.length(), ' ');
        string clone_msg = encrypt_word_fill(msg);
        unsigned int index;

        for (int i= 0; i < msg.length(); i++) {
            for (int j = 0; j < abc_minus.length(); j++) {
                if (msg[i] == abc_minus[j]) {
                    index = modulo(j + getIndexABC(clone_msg[i]), abc_minus.length());
                    encriptado[i] = abc_minus[index];
                    //cout<<"e="<<msg[i]<<" | e(index)="<<j<<" | clone_msg="<<getIndexABC(clone_msg[i])<<endl;
                    continue;
                }
            }
            for (int j = 0; j < abc_mayus.length(); j++) {
                if (msg[i] == abc_mayus[j]) {
                    index = modulo(j + getIndexABC(clone_msg[i]), abc_mayus.length());
                    encriptado[i] = abc_mayus[index];
                    //cout<<"e="<<msg[i]<<" | e(index)="<<j<<" | clone_msg="<<getIndexABC(clone_msg[i])<<endl;
                    continue;
                }
            }

        }
        return encriptado;
    }



    string descifrar(string msg) {
        string decrypt(msg.length(), ' ');
        string clone_msg = encrypt_word_fill(msg);
        int index;
        
        for (int i= 0; i < msg.length(); i++) {
            for (int j = 0; j < abc_minus.length(); j++) {
                if (msg[i] == abc_minus[j]) {
                    index = modulo(j - getIndexABC(clone_msg[i]), abc_minus.length());
                    decrypt[i] = abc_minus[index];
                    //cout<<"e="<<msg[i]<<" | e(index)="<<j<<" | clone_msg="<<getIndexABC(clone_msg[i])<<endl;
                    continue;
                }
            }
            for (int j = 0; j < abc_mayus.length(); j++) {
                if (msg[i] == abc_mayus[j]) {
                    index = modulo(j - getIndexABC(clone_msg[i]), abc_mayus.length());
                    decrypt[i] = abc_mayus[index];
                    //cout<<"e="<<msg[i]<<" | e(index)="<<j<<" | clone_msg="<<getIndexABC(clone_msg[i])<<endl;
                    continue;
                }
            }

        }

        return decrypt;
    }

};
