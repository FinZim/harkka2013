

#include "stdafx.h"
#include <iostream>

#include "VigenereLibDLL.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){

	cout << "Welcome to SimpleCrypt" << endl;

	nsVigenere::Vigenere vig("123456");

	vig.setKey("98765442");
	char* txt = "This is some kind of test...";
	const char* asd = vig.encrypt(txt);

	cout << "Teksti: " << txt << "Kryptattu: '" << asd << "'" << endl;

	//nsVigenere::Vigenere vig("asd");

	//vig.encrypt("Tämä on vain jokin testi");
	
    return 0;
}
