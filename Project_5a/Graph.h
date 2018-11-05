#pragma once
#include <string>
#include <map>
#include <vector>
#include <regex>
#include "Coordinate.h"
using namespace std;

class Graph
{
public:
	Graph();
	void Parse(const string& little_langague_data);
private:

	string _label;
	map<string, vector<int>> _rangesAndTicks;
	vector<Coordinate> _coordinates;

	void ParseLabel(const string& little_langague_data);
	void ParseTicksAndRanges(const string& little_langague_data);
	void ParseCoordinates(const string& little_langague_data);

	vector<string> GetRegexMatches(const regex lookup, string data, int groupMatchIndex);
	vector<string> GetRegexMatches(const regex lookup, string data, vector<int> groupMatchIndexes = { 1 });
};

