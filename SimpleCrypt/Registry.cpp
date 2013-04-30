
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <tchar.h>

#include "Registry.h"

using namespace std;

Registry::Registry(HKEY hRootKey, wchar_t* strKey){
	HKEY hKey;
	LONG nError = RegOpenKeyEx(hRootKey, strKey, NULL, KEY_ALL_ACCESS, &hKey);

	if (nError==ERROR_FILE_NOT_FOUND){
		cout << "Creating registry key: " << strKey << endl;
		nError = RegCreateKeyEx(hRootKey, strKey, NULL, NULL, REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL, &hKey, NULL);
	}

	if (nError){
		cout << "Error: " << nError << " Could not find or create " << strKey << endl;
	}

	this->hKey = hKey;
}

const char* Registry::read(LPCTSTR key){
	const char* output = "";

	DWORD type = REG_SZ;
	char buffer[64] = {0};
	DWORD lpcbData = sizeof(buffer);

	LONG nError = RegQueryValueEx(this->hKey, key, NULL, &type, (PBYTE)&buffer, &lpcbData);

	if (nError == ERROR_SUCCESS){
		cout << "Success reading the Registry." << endl;

		for(int i=0; i<sizeof(buffer); i++){
			if(buffer[i] != NULL){
				output += buffer[i];
			}
		}
	}else{
		cout << "Error reading the Registry." << endl;
	}

	return output;
}

void Registry::write(LPCTSTR key, const char* value){
	string strValue(value);
	wstring wValue(strValue.begin(), strValue.end());

	LPCTSTR data = wValue.c_str();

    LONG setRes = RegSetValueEx (hKey, key, 0, REG_SZ, (LPBYTE)data, _tcslen(data)*sizeof(TCHAR));

    if (setRes == ERROR_SUCCESS) {
        cout << "Success writing to Registry." << endl;
    } else {
        cout << "Error writing to Registry." << endl;
    }
}

Registry::~Registry(){
	RegCloseKey(this->hKey);
}
