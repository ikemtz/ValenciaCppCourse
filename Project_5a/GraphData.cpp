#include "pch.h"
#include <iostream>
#include "GraphData.h"
#include <regex>

GraphData::GraphData()
{
}

void GraphData::Parse(const string& little_langague_data)
{ 
	ParseLabel(little_langague_data);
	ParseTicksAndRanges(little_langague_data);
	ParseCoordinates(little_langague_data);
}

void GraphData::ParseLabel(const string& little_langague_data) {
	_label = GetRegexMatches(regex("label ([\\w ,-]+)"), little_langague_data)[0];
	cout << "Label: " << _label << endl;
}

void GraphData::ParseCoordinates(const string& little_langague_data) {
	regex coordinate{ "([0-9]+) ([0-9]+)" };
	const vector<int> matchingGroupIndex = { 1,2 };
	auto coordinates = GetRegexMatches(regex("\n([0-9]+) ([0-9]+)"), little_langague_data, 0);

	for (string x : coordinates) {
		auto matches = GetRegexMatches(coordinate, x, matchingGroupIndex);
		Coordinate c { stoi(matches[0]), stoi(matches[1]) };
		_coordinates.push_back(c);

		cout << "Coordinate parsed, x:" << c.x << " y: " << c.y << endl;
	}
}

void GraphData::ParseTicksAndRanges(const string& little_langague_data) {
	regex text{ "([a-z ]+)[a-z]" };
	regex numeric{ "[0-9]+" };
	auto dataPoints = GetRegexMatches(regex("[a-z ]+ [\\d ]+"), little_langague_data, 0);
	for (string x : dataPoints) {

		auto dataPoint = GetRegexMatches(text, x, 0)[0];
		cout << "Range and Tick parsed: " << dataPoint << endl;
		vector<int> values;
		auto string_numbers = GetRegexMatches(numeric, x, 0);
		for (string y : string_numbers) {
			int i = stoi(y);
			values.push_back(i);
			cout  << i << endl;
		}
		_rangesAndTicks.insert(pair<string, vector<int>>(dataPoint, values));

	}
}

vector<string> GraphData::GetRegexMatches(const regex lookup, string data, int groupMatchIndex) {
	return GetRegexMatches(lookup, data, vector<int> {groupMatchIndex});
}

vector<string> GraphData::GetRegexMatches(const regex lookup, const string data, vector<int> groupMatchIndexes) {
	auto text_iter = data.cbegin();
	smatch regexResuts;
	vector<string> results;
	while (regex_search(text_iter, data.cend(), regexResuts, lookup))
	{
		for (int x : groupMatchIndexes) {
			results.push_back(regexResuts[x]);
		}
		text_iter = regexResuts[0].second;
	}
	return results;
}
 
