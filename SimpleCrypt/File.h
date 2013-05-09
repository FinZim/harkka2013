/** 
 * @file File.h
 * File class header file
 * @author Kim Kostera
 * @version 0.1
 */
#include <Windows.h>
#include <string>
#include <fstream>

class File {

public:
	
	string readFile(string filename);{
		ifstream myFile();
	}
	
	void writeFile(string filename ){   
		ofstream myFile;
		myFile.open ("file.txt");
		myFile << endl;
		myFile.close();
		
	}

};