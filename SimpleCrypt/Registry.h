
#include <Windows.h>

class Registry {
private:
	HKEY hKey;
public:
	Registry(HKEY hRootKey, wchar_t* strKey);
	~Registry();
	void write(LPCTSTR key, const char* value);
	const char* read(LPCTSTR key);
};
