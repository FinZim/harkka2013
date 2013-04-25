/* 
 * @file main.cpp
 * SimpleCrypt salaussofta
 */

#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

#include "VigenereLib.h"

using namespace std;

// Swap trick
//template <typename T>
//void FreeAll( T & t ) {
//    T tmp;
//    t.swap( tmp );
//}

//int my_main(vector<string> args){
int main(int argc, char* argv[]){  
    cout << "Welcome to SimpleCrypt" << endl;
    
    /*for (vector<string>::size_type i = 0; i < args.size(); i++){
        cout << args.at(i) << endl;
    }*/
    for (int i = 0; i <= argc; i++){
        cout << argv[i] << endl;
    }
    
    string txt, output;
    txt = "This is a string";
    
    VigenereClass vigenere;
    output = vigenere.encrypt(txt);
    
    cout << output << endl;
    
    return 0;
}

/*int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    
    istringstream iss(lpCmdLine);
    vector<string> args;
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string> >(args));
    
    my_main(args);
    
    args.clear();
    
    return 0;
}*/

