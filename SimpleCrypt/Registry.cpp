/* 
 * @file Registry.cpp
 * Registry class resource file
 * @author Jarmo Erola
 * @version 0.1
 */

#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <tchar.h>

#include "Registry.h"

using namespace std;

/**
 * A constructor
 * @param hRootKey A handle to an open registry key.
 * @param strKey The name of the registry subkey to be opened. 
 */
Registry::Registry(HKEY hRootKey, wchar_t* strKey){
	HKEY hKey;

	/**
	 * Open specific registry key
	 */
	LONG nError = RegOpenKeyEx(hRootKey, strKey, NULL, KEY_ALL_ACCESS, &hKey);

	if (nError==ERROR_FILE_NOT_FOUND){
		cout << "Creating registry key: " << strKey << endl;

		/**
		 * Create registry key if it's not found
		 */
		nError = RegCreateKeyEx(hRootKey, strKey, NULL, NULL, REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL, &hKey, NULL);
	}

	if (nError){
		cout << "Error: " << nError << " Could not find or create " << strKey << endl;
	}

	this->hKey = hKey;
}

/**
 * Retrieves the data for the specified value name associated with an open registry key.
 * @param key The name of the key to be read.
 */
std::string Registry::read(LPCTSTR key){
	string output = "";

	/**
	 * Define the type as string (REG_SZ)
	 */
	DWORD type = REG_SZ;
	char buffer[64] = {0};
	DWORD lpcbData = sizeof(buffer);

	/**
	 * Retrieve a value of specific key and place it to buffer
	 */
	LONG nError = RegQueryValueEx(this->hKey, key, NULL, &type, (PBYTE)&buffer, &lpcbData);

	if (nError == ERROR_SUCCESS){
		/**
		 * Loop through buffer and place not-empty cells to output string
		 */
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

/**
 * Sets the data of a specified value under a registry key.
 * @param key The name of the value to be set.
 * @param strKey The data to be stored. 
 */
void Registry::write(LPCTSTR key, const char* value){
	string strValue(value);
	wstring wValue(strValue.begin(), strValue.end());

	LPCTSTR data = wValue.c_str();

	/**
	 * Set value to specific key
	 */
    LONG setRes = RegSetValueEx (hKey, key, 0, REG_SZ, (LPBYTE)data, _tcslen(data)*sizeof(TCHAR));

    if (setRes != ERROR_SUCCESS) {
        cout << "Error writing to Registry." << endl;
    }
}

/**
 * A destructor
 */
Registry::~Registry(){
	/**
	 * Closing opened registry
	 */
	RegCloseKey(this->hKey);
}
