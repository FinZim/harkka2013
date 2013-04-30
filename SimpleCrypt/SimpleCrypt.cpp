
#include "stdafx.h"
#include <iostream>
#include <string>

#include "VigenereLibDLL.h"

using namespace std;

int wmain(int argc, wchar_t *argv[], wchar_t *envp[]){

	string method, key, algorithm, file, ver;
	bool help, version;

	ver = "v.0.1";
	help = false;
	version = false;

	if (argc > 1) {
		for (int i = 1; i < argc; i++) { 
			char buffer1[4], buffer2[64];
			int ret;
			string param, value;

			ret = wcstombs( buffer1, argv[i], sizeof(buffer1) );
			if (ret == 4) buffer1[3]='\0';
			if (ret) param = buffer1;

			if (i + 1 != argc) {
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
		cout << "SimpleCrypt " << ver << endl;
		return 0;
	} else {
		cout << "Welcome to SimpleCrypt " << ver << endl;

	}

    return 0;
}
