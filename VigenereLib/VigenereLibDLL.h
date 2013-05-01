/** 
 * @file VigenereLibDLL.h
 * Vigenere DLL library header file
 * @author Jarmo Erola
 * @version 0.1
 */

#ifdef VIGENERELIBDLL_EXPORTS
#define VIGENERELIBDLL_API __declspec(dllexport) 
#else
#define VIGENERELIBDLL_API __declspec(dllimport) 
#endif

/** 
 * @class Vigenere
 * @brief Vigenere encryption class for encrypting and decrypting data
 */
class __declspec (dllexport) Vigenere {
private:
	/** 
	 * Private variable to store a key 
	 */
	std::string key;
public:
	/**
	 * A constructor
	 * @param key Default key for encryption.
	 */
	Vigenere(std::string key);
	/**
	 * Sets a key to private variable
	 * @param key A key.
	 */
	void setKey(std::string key);
	/**
	 * Encrypt given text
	 * @param txt A text to encrypt.
	 */
	std::string encrypt(std::string txt); 
	/**
	 * Decrypt given text
	 * @param txt A text to decrypt.
	 */
	std::string decrypt(std::string txt); 
};
