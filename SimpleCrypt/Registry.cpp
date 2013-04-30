
#include <Windows.h>
#include <iostream>
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

DWORD Registry::read(LPCTSTR key){
	DWORD data;
	DWORD size = sizeof(data);
	DWORD type = REG_SZ;
	LONG nError = RegQueryValueEx(this->hKey, key, NULL, &type, (LPBYTE)&data, &size);

	if (nError==ERROR_FILE_NOT_FOUND)
		data = 0; // The value will be created and set to data next time SetVal() is called.
	else if (nError)
		cout << "Error: " << nError << " Could not get registry value " << (char*)key << endl;

	return data;
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
