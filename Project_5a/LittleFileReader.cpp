#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include "LittleFileReader.h"
#include <fstream>
using namespace std;


string LittleFileReader::ReadFile()
{
	_fileStream.open(this->_fileName);
	if (!_fileStream) {
		cout << "Unable to open file " << this->_fileName << ".";
		exit(1);   // call system to stop
	}

	stringstream strStream;
	strStream << _fileStream.rdbuf();
	string result = strStream.str();

	_fileStream.close();
	return result;
}
