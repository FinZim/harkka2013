/* 
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

namespace nsVigenere {
	/** 
	 * @class Vigenere
	 * @brief Vigenere encryption class for encrypting and decrypting data
	 */
	class __declspec (dllexport) Vigenere {
	private:
		/** 
		 * Private variable to store a key 
		 */
		char* key;
	public: 
		/**
		 * A constructor
		 * @param key Default key for encryption.
		 */
		Vigenere(char* key);
		/**
		 * Sets a key to private variable
		 * @param key A key.
		 */
		void setKey(char* key);
		/**
		 * Encrypt given text
		 * @param txt A text to encrypt.
		 */
		const char* encrypt(char* txt); 
		/**
		 * Decrypt given text
		 * @param txt A text to decrypt.
		 */
		const char* decrypt(char* txt); 
	};
}
