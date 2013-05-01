/* 
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

#include "VigenereLibDLL.h"
#include "Registry.h"

#define VERSION "v.0.1"

using namespace std;

/**
 * A main function
 * @param argc An integer specifying how many arguments are passed to the program from the command line.
 * @param argv An array of null-terminated strings.
 * @param envp A pointer to an array of environment strings.
 */
int wmain(int argc, wchar_t *argv[], wchar_t *envp[]){

	string method, key, algorithm, file;
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
		cout << "  -k <key>          Set key in <key>" << endl << endl;
		cout << "For bug reporting, contact:" << endl;
		cout << "<kim.kostera@student.lamk.fi, jarmo.erola@gmail.com>." << endl;
		return 0;
	} else if(version) {
		cout << "SimpleCrypt " << VERSION << endl;
		return 0;
	} else {
		cout << "Welcome to SimpleCrypt " << VERSION << endl;

		if(key != ""){
			string readedKey;

			Registry *reg = new Registry(HKEY_CURRENT_USER, L"Software\\SimpleCrypt");
			reg->write(L"DefaultKey", key.c_str());

			readedKey = reg->read(L"DefaultKey");
			cout << "Readed key: #" << readedKey << "#" << endl;
		}

	}

    return 0;
}
