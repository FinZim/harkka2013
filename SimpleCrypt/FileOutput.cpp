/** 
 * @file FileOutput.cpp
 * File class resource file
 * @author Kim Kostera
 * @version 0.1
 */

#include <iostream>
#include <fstream>
#include <string>

#include "File.h"

using namespace std;

int main () {

  ofstream myfile;
  
  myfile.open ("file.txt");
  
  if(myfile.is_open()){

      myfile << endl;

      myfile.close();
  }
  else
  
  {
      cout << "Can't open the file!" << endl;
  }

  return 0;
}