/** 
 * @file File.cpp
 * File class resource file
 * @author Kim Kostera
 * @version 0.1
 */
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
#include "File.h"

using  namespace std;

	/**
	* File Read and gather data to string.
	*/

	string File::read(string filename){

		std::string line;

		ifstream File("file.txt");
		if (File.is_open()){
			while (! File.eof()){

				std::getline(File,line);
				cout << line << endl;
				line.append(line);
			}
			File.close();
			line.append(line);
		}
		else cout << " Unable to open file ";
		
	}

	/**
	* File write from the gathered string data.
	*/

	void File::write(string filename, string data){

		ofstream File("file.txt");
		if(File.is_open()){

			File << endl;
			File.close();
	}
		else
		{
			cout << " Can't open the file! " << endl;
		}
	}

