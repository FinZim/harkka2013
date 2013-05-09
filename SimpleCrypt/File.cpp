/** 
 * @file File.cpp
 * File class resource file
 * @author Kim Kostera
 * @version 0.1
 */

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>

#include "File.h"

using  namespace std;

int main()
{
	string myFile::read(string filename){

		ifstream myFile("file.txt");

		if (myFile.is_open())
		{
			while (! myFile.eof())
			{
				getline (myFile,line);

				cout << line << endl;
			}

			myFile.close();
		}

		else cout << " Unable to open file ";

	}
}

	void myFile::write(string filename, string data){

		ofstream myFile;

		myFile.open ("file.txt");

		if(myFile.is_open()){

			myFile << endl;

			myFile.close();
	}
		else
		{
			cout << " Can't open the file! " << endl;
		}
	}

	return 0;
}