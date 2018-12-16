#pragma once
#include <string>
#include <map>
#include <vector>
#include <regex>
#include "Coordinate.h"

using namespace std;

class GraphData
{
public:
	GraphData();
	void Parse(const string& little_langague_data);
	string GetLabel() { return _label; };
	map<string, vector<int>> GetRangesAndTicks() {
		return _rangesAndTicks;
	};
	vector<Coordinate> GetCoordinates() {
		return _coordinates;
	};
private:

	string _label;
	map<string, vector<int>> _rangesAndTicks;
	vector<Coordinate> _coordinates;

	void ParseLabel(const string& little_langague_data);
	void ParseTicksAndRanges(const string& little_langague_data);
	void ParseCoordinates(const string& little_langague_data);

	vector<string> GetRegexMatches(const regex lookup, const string data, int groupMatchIndex);
	vector<string> GetRegexMatches(const regex lookup, const string data, vector<int> groupMatchIndexes = { 1 });
};

