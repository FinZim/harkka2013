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
	
		/**
		* Method for read
		*/
		std::string read(std::string filename);
		
		/**
		* Method for write
		*/				
		void write(std::string filename, std::string data);
			
	};