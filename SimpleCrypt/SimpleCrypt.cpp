/** 
 * @file SimpleCrypt.cpp
 * SimpleCrypt encryption software main file
 * @author Jarmo Erola
 * @version 0.1
 */

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>

#include "VigenereLibDLL.h"
#include "Registry.h"

#define VERSION "v.0.1"

using namespace std;

bool is_number(const std::string& s);

/**
 * A main function
 * @param argc An integer specifying how many arguments are passed to the program from the command line.
 * @param argv An array of null-terminated strings.
 * @param envp A pointer to an array of environment strings.
 */
int wmain(int argc, wchar_t *argv[], wchar_t *envp[]){

	string method, key, algorithm, file, text;
	bool help, version;

	help = false;
	version = false;

	/**
	 * Check that there is enough arguments
	 */
	if (argc > 1) {
		for (int i = 1; i < argc; i++) { 
			char buffer1[4], buffer2[64];
			int ret;
			string param, value;

			/**
			 * Converting wchar_t* to string and using it as a param
			 */
			ret = wcstombs( buffer1, argv[i], sizeof(buffer1) );
			if (ret == 4) buffer1[3]='\0';
			if (ret) param = buffer1;

			if (i + 1 != argc) {
				/**
				 * Converting wchar_t* to string and using it as a value
				 */
				ret = wcstombs( buffer2, argv[i+1], sizeof(buffer2) );
				if (ret == 64) buffer2[63]='\0';
				if (ret) value = buffer2;
			}

			if (param.compare("-a") == 0) {
				algorithm = value;
			} else if (param.compare("-m") == 0) {
				method = value;
			} else if (param.compare("-k") == 0) {
				key = value;
			} else if (param.compare("-i") == 0) {
				file = value;
			} else if (param.compare("-t") == 0) {
				text = value;
			} else if (param.compare("-h") == 0){
				help = true;
			} else if (param.compare("-v") == 0){
				version = true;
			}
		}
	} else {
		help = true;
	}

	if(help) {
		cout << "Usage: simplecrypt [options]..." << endl << endl;
		cout << "Options:" << endl;
		cout << "  -h                Display this information" << endl;
		cout << "  -v                Display version information" << endl;
		cout << "  -i <file>         Place the input file into <file>" << endl;
		cout << "  -a <algorithm>    Specify the algorithm into <algorithm>" << endl;
		cout << "  -m <method>       Specify the method into <method> {encrypt|decrypt}" << endl;
		cout << "  -k <key>          Set key in <key>" << endl;
		cout << "  -t <text>         Solid text (without spaces) into <text>" << endl << endl;

		cout << "Examples:" << endl;
		cout << "  simplecrypt -k 1234                                  Set key as default key" << endl;
		cout << "  simplecrypt -m encrypt -a vigenere -t Thisissometext Encrypt solid text with Vigenere and default key" << endl;
		cout << "  simplecrypt -m encrypt -a vigenere -i test.txt       Encrypt test.txt with Vigenere and default key" << endl << endl;

		cout << "For bug reporting, contact:" << endl;
		cout << "<kim.kostera@gmail.com, jarmo.erola@gmail.com>." << endl;
		return 0;
	} else if(version) {
		cout << "SimpleCrypt " << VERSION << endl;
		return 0;
	} else {
		cout << "Welcome to SimpleCrypt " << VERSION << endl;

		// Just a test for testing things
		if(method.compare("test") == 0){
			string readedKey, encrypted, decrypted;

			Registry *reg = new Registry(HKEY_CURRENT_USER, L"Software\\SimpleCrypt");
			reg->write(L"DefaultKey", key.c_str());

			readedKey = reg->read(L"DefaultKey");
			cout << "Readed key: #" << readedKey << "#" << endl;

			Vigenere *vig = new Vigenere(key);
			encrypted = vig->encrypt("This is some text to be encrypted!!");
			decrypted = vig->decrypt(encrypted);

			cout << "Text: " << "This is some text to be encrypted!!" << endl;
			cout << "Encrypted: " << encrypted << endl << "Decrypted: " << decrypted << endl;

			return 0;
		}

		/**
		 * If key is defined and method is empty, save the key to registry
		 */
		if(key.compare("") != 0 && method.compare("") == 0){
			if(!is_number(key)){
				Registry *reg = new Registry(HKEY_CURRENT_USER, L"Software\\SimpleCrypt");
				reg->write(L"DefaultKey", key.c_str());

				cout << "Default key set!" << endl;
			}else{
				cout << "Error: Numeric key is not yet supported." << endl;
				return 0;
			}
		}
		else if(method.compare("") != 0){
			if(algorithm.compare("") != 0){
				
				string encrypted, decrypted, data;

				if(file.compare("") != 0){
					//File *f = new File();
					data = "This is a test!!"; //f->read(file);
				}
				else if(text.compare("") == !0){
					data = text;
				}else{
					cout << "Error: file or text to be encrypted missing. Give it with -f or -t flag." << endl;
					return 0;
				}
				
				if(key.compare("") == 0){
					Registry *reg = new Registry(HKEY_CURRENT_USER, L"Software\\SimpleCrypt");
					key = reg->read(L"DefaultKey");
				}
				
				if(is_number(key)){
					cout << "Error: Numeric key is not yet supported." << endl;
					return 0;
				}

				if(algorithm.compare("vigenere") == 0){
					Vigenere *vig = new Vigenere(key);
					
					if(method.compare("encrypt") == 0){
						encrypted = vig->encrypt(data);
						cout << "Encrypted: " << encrypted << endl;
					}
					else if(method.compare("decrypt") == 0){
						decrypted = vig->decrypt(data);
						cout << "Decrypted: " << decrypted << endl;
					}
					else{
						cout << "Error: method is not supported." << endl;
						return 0;
					}
				}else{
					cout << "Error: algorithm '" << algorithm << "' is not supported." << endl;
					return 0;
				}
			}else{
				cout << "Error: algorithm is missing. Give it with -a flag." << endl;
				return 0;
			}
		}
	}

    return 0;
}

bool is_number(const std::string& s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
