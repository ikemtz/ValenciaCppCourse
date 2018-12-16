#pragma once
#include <fstream>
using namespace std;

class LittleFileReader
{
public:
	LittleFileReader(string filename) : _fileName(filename) {};
	string ReadFile();
private:
	ifstream _fileStream;
	string _fileName;
};

