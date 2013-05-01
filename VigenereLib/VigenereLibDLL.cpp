/** 
 * @file VigenereLibDLL.cpp
 * Vigenere DLL library resource file
 * @author Jarmo Erola
 * @version 0.1
 */

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdexcept>

#include "VigenereLibDll.h"

using namespace std;

/**
 * A constructor
 * @param key Default key for encryption.
 */
Vigenere::Vigenere(string key){

	for(int i = 0; i < key.size(); ++i){
		if(key[i] >= 'A' && key[i] <= 'Z'){
			this->key += key[i];
		}
		else if(key[i] >= 'a' && key[i] <= 'z'){
			this->key += key[i] + 'A' - 'a';
		}
	}

}

/**
 * Sets a key to private variable
 * @param key A key.
 */
void Vigenere::setKey(string key){
	this->key = key;
}

/**
 * Encrypt given text
 * @param txt A text to encrypt.
 */
string Vigenere::encrypt(string txt){
	string output;
	string key = this->key;
	
	for(int i = 0, j = 0; i < txt.length(); ++i){
		char c = txt[i];
	
		if(c >= 'a' && c <= 'z'){
			c += 'A' - 'a';
		}
		else if(c < 'A' || c > 'Z'){
			continue;
		}
		
		output += (c + key[j] - 2*'A') % 26 + 'A'; 
		j = (j + 1) % key.length();
	}

	return output;
}

/**
 * Decrypt given text
 * @param txt A text to decrypt.
 */
string Vigenere::decrypt(string txt){
	string output;
	string key = this->key;
 
	for(int i = 0, j = 0; i < txt.length(); ++i){
		char c = txt[i];
 
		if(c >= 'a' && c <= 'z'){
			c += 'A' - 'a';
		}
		else if(c < 'A' || c > 'Z'){
			continue;
		}
 
		output += (c - key[j] + 26) % 26 + 'A'; 
		j = (j + 1) % key.length();
	}
 
	return output;
}
