
#include <Windows.h>

static class Registry {
private:
	HKEY hKey;
public:
	Registry(HKEY hRootKey, wchar_t* strKey);
	~Registry();
	void write(LPCTSTR key, const char* value);
	DWORD read(LPCTSTR key);
};
