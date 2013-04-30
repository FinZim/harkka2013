
#ifdef VIGENERELIBDLL_EXPORTS
#define VIGENERELIBDLL_API __declspec(dllexport) 
#else
#define VIGENERELIBDLL_API __declspec(dllimport) 
#endif

namespace nsVigenere {
	class __declspec (dllexport) Vigenere {
	private:
		char* key;
	public: 
		Vigenere(char* key);
		void setKey(char* key);
		const char* encrypt(char* txt); 
		static const char* decrypt(char* txt); 
	};
}
