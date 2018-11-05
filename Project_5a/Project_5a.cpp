// Project_5a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream> 
#include "LittleFileReader.h"
#include "Graph.h"

using namespace std;
int main()
{
    std::cout << "Hello World!\n"; 
	LittleFileReader reader{"./little_languages_graph_data"};
	string littleData = reader.ReadFile();
	Graph graph;
	graph.Parse(littleData);
}