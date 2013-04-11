/* 
 * @file main.cpp
 * Harkka2013 salaussofta
 */

#include <iostream>
#include <windows.h>
#include "VigenereLib.h"

using namespace std;

/*int main(int argc, char** argv) {

    return 0;
}*/

int __stdcall WinMain(HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR lpCmdLine,
                      int nCmdShow){
    
    LPWSTR *szArgList;
    int argCount;
    
    szArgList = CommandLineToArgvW(GetCommandLine(), &argCount);
    if(szArgList == NULL){
        //MessageBox(NULL, L"Unable to parse command line", L"Error", MB_OK);
        cout << "Unable to parse commandline" << endl;
        return 10;
    }
    
    for(int i = 0; i < argCount; i++){
        //MessageBox(NULL, szArgList[i], L"Arglist contents", MB_OK);
        cout << szArgList[i] << endl;
    }
    
    LocalFree(szArgList);
    
    return 0;
    
    /*VigenereClass vigenere;
    vigenere.encrypt();
    
    return 0;
     */
}

