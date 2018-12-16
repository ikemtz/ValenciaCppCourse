#pragma once
#include "GraphData.h"  
#include "simple_svg_1.0.0.hpp"
using namespace svg;

class Grapher
{
public:
	Grapher(const GraphData graphData, const string fileName) :
		_graphData(graphData),
		_document(Document{ fileName,Layout(Dimensions(_chartWidth + (_marginX * 2), _chartHeight + (_marginY * 2)), Layout::BottomLeft) }) {	};


	void Graph()
	{
		CalculateChartFactor();
		vector<Point> points = ConvertCoordinatesToPoints();
		DrawBorder();
		DrawChart(points);
		DrawBottomTicks();
		DrawLeftTicks();
		DrawTitle();
		_document.save();
	}

	void CalculateChartFactor() {
		auto rangesAndTicks = this->_graphData.GetRangesAndTicks();

		auto range = rangesAndTicks.find("range")->second;
		_bottomTicks = rangesAndTicks.find("bottom ticks")->second;
		_leftTicks = rangesAndTicks.find("left ticks")->second;

		_leftX = range.at(0);
		_bottomY = range.at(1);

		double rangeX = range.at(2) - range.at(0);
		double rangeY = range.at(3) - range.at(1);

		_factorX = _chartWidth / rangeX;
		_factorY = _chartHeight / rangeY;
	}

	vector<Point> ConvertCoordinatesToPoints()
	{
		vector<Point> points;

		for (const auto xy : _graphData.GetCoordinates()) {
			double x = (xy.x - _leftX) * _factorX;
			double y = (xy.y - _bottomY) * _factorY;
			points.push_back(Point(x, y));
		}
		return points;
	}

	void DrawChart(const vector<Point> points) {

		LineChart chart(Dimensions(_marginX, _marginY));
		Polyline polyline_a(points, Fill(Color::Transparent), Stroke(.5, Color::Blue));
		chart << polyline_a;
		_document << chart;
	}

	void DrawBottomTicks() {
		for (const auto tickX : _bottomTicks) {
			Color axisColor = Color::Red;
			double x = (tickX - _leftX) * _factorX + _marginX;
			Line l(Point(x, _marginY), Point(x, _chartHeight + _marginY), Stroke(.5, axisColor));
			Text text(Point(x - 15, _marginY - _axisFontSize * 1.5), to_string(tickX), axisColor, Font(_axisFontSize));
			_document << text;
			_document << l;
		}
	}

	void DrawLeftTicks() {
		for (const auto tickY : _leftTicks) {
			Color axisColor = Color::Purple;
			double y = (tickY - _bottomY) * _factorY + _marginY;
			Line l(Point(_marginX, y), Point(_chartWidth + _marginX, y), Stroke(.5, axisColor));
			Text text(Point(10, y - (_axisFontSize / 2)), to_string(tickY), axisColor, Font(_axisFontSize));
			_document << text;
			_document << l;
		}
	}

	void DrawBorder() {
		Polygon border(Stroke(1, Color::Black));
		border << Point(_marginX, _marginY) << Point(_chartWidth + _marginX, _marginY)
			<< Point(_chartWidth + _marginX, _chartHeight + _marginY) << Point(_marginX, _chartHeight + _marginY);
		_document << border;
	}

	void DrawTitle() {
		int titleFontSize = 25;
		auto titleText = _graphData.GetLabel();
		Point titlePoint(_marginX, _chartHeight + _marginY + (titleFontSize / 2));
		Text title(titlePoint, titleText, Color::Black, Font(titleFontSize));

		_document << title;
	}
private:
	const int _marginX = 50;
	const int _marginY = 50;

	const int _chartWidth = 500;
	const int _chartHeight = 200;

	const int _axisFontSize = 10;

	vector<int> _bottomTicks;
	vector<int> _leftTicks;

	int _leftX;
	int _bottomY;

	double _factorX;
	double _factorY;

	GraphData _graphData;
	Document _document;
};

