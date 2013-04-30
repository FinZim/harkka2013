
#include "stdafx.h"
#include "VigenereLibDll.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

namespace nsVigenere {

	Vigenere::Vigenere(char* key){

		string strkey(key);

		for(int i = 0; i < strkey.size(); ++i){
			if(strkey[i] >= 'A' && strkey[i] <= 'Z'){
				this->key += strkey[i];
			}
			else if(strkey[i] >= 'a' && strkey[i] <= 'z'){
				this->key += strkey[i] + 'A' - 'a';
			}
		}

	}

	void Vigenere::setKey(char* _key){
		this->key = _key;
	}

	const char* Vigenere::encrypt(char* txt){
		string out;
		string strtxt(txt);

		cout << "This is encrypt. " << strtxt << endl;

		string key = this->key;
 
		for(int i = 0, j = 0; i < strtxt.length(); ++i){
			char c = strtxt[i];
	
			if(c >= 'a' && c <= 'z'){
				c += 'A' - 'a';
			}
			else if(c < 'A' || c > 'Z'){
				continue;
			}
		
			out += (c + key[j] - 2*'A') % 26 + 'A'; 
			j = (j + 1) % key.length();
		}
 
		const char* output = out.c_str();

		cout << "This is encrypt. " << output << endl;

		return output;
	}

	const char* Vigenere::decrypt(char* txt){
		string out;
		string strtxt(txt);

		/*string key = this->key;
 
		for(int i = 0, j = 0; i < strtxt.length(); ++i){
			char c = strtxt[i];
 
			if(c >= 'a' && c <= 'z'){
				c += 'A' - 'a';
			}
			else if(c < 'A' || c > 'Z'){
				continue;
			}
 
			out += (c - key[j] + 26) % 26 + 'A'; 
			j = (j + 1) % key.length();
		}
 */
		const char* output = out.c_str();
		return output;
	}
}
