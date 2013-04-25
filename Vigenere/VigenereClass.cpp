/*
 * @file VigenereClass.cpp
 * @author Jarmo Erola
 * @version 0.1
 */

#define VIGENERE_DLL

#include <string>

#include "VigenereClass.h"

using namespace std;

string VigenereClass::encrypt(string txt){
    //this->key;
    
    string text = "Vigenere encryption... ";
    text.append(txt);
    
    return text;
}

string VigenereClass::decrypt(string txt){
    //this->key;
    cout << "Vigenere decryption..." << endl;
}

