/** 
 * @file Registry.h
 * Registry class header file
 * @author Jarmo Erola
 * @version 0.1
 */

#include <Windows.h>
#include <string>

/** 
 * @class Registry
 * @brief A class to read and write the registry
 */
class Registry {
private:
	/**
	 * A private variable.
	 * Stores a registry handle.
	 */
	HKEY hKey;
public:
	/**
	 * A constructor
	 * @param hRootKey A handle to an open registry key.
	 * @param strKey The name of the registry subkey to be opened. 
	 */
	Registry(HKEY hRootKey, wchar_t* strKey);
	/**
	 * A destructor
	 */
	~Registry();
	/**
	 * Sets the data of a specified value under a registry key.
	 * @param key The name of the value to be set.
	 * @param value The data to be stored. 
	 */
	void write(LPCTSTR key, const char* value);
	/**
	 * Retrieves the data for the specified value name associated with an open registry key.
	 * @param key The name of the key to be read.
	 */
	std::string read(LPCTSTR key);
};
