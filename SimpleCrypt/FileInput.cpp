/** 
 * @file FileInput.cpp
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
	string line;

	ifstream myfile ("file.txt");

	if (myfile.is_open())
	{
		while (! myfile.eof() )
		{
			getline (myfile,line);

			cout << line << endl;
		}

		myfile.close();
	}

	else cout << " Unable to open file ";
	

	return 0;
}