// Project4_B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <map>

#include "DataSeries.h"         // Enables loading data from a file -- supplied
#include "Filter.h"             // Abstract class for filtering data -- supplied
#include "simple_svg_1.0.0.hpp" // The SVG handling routines.  Be sure to use the one
								// I supply because I had to modify it a bit.

#include "ImprovedLineChart.h"  // Extends LineChart to allow setting the size and color of points
#include "MovingAverage.h"      // You create this one, extending Filter

using namespace std;

int main()
{
	// Add code here to load the data from file adsb_clean.out using 
	// an instance of the DataSeries class.
	DataSeries series("adsb_clean.out");

	// This is copied from the example file

	// Instantiate polylines to hold all the points
	Polyline polyline_1(Fill(Color::Transparent), Stroke(.25, Color::Blue));
	Polyline polyline_2(Fill(Color::Transparent), Stroke(.5, Color::Orange));
	Polyline polyline_3(Fill(Color::Transparent), Stroke(.25, Color::Red));
	
	// Instantiate your MovingAverage filters here
	MovingAverage movingAverage1(3);
	MovingAverage movingAverage2(15);
	MovingAverage movingAverage3(30);

	//An array to loop through it all
	tuple<MovingAverage, Polyline> averageLines[] = {
		make_tuple(movingAverage1, polyline_1),
		make_tuple(movingAverage2, polyline_2),
		make_tuple(movingAverage3, polyline_3)
	};

	//Variables to keep track of the X,Y dimensions
	const int maxX = series.length();
	double maxY;

	//Todo: calculate these based on desired width and height
	//Requires calculating maxX, maxY first.
	const double scaleFactorY = 0.025;
	const double scaleFactorX = 0.025;

	//Add points to polyline based on filters
	for (int i = 0; i < maxX; i++) {
		int value = series.nextValue();
		for (int l = 0; l < sizeof(averageLines) / sizeof(averageLines[0]); l++) {
			get<0>(averageLines[l]).input(value);

			double d = get<0>(averageLines[l]).output() * scaleFactorY;
			if (d > 0) {
				// Add each to the Polyline	
				maxY = max(maxY, d);
				get<1>(averageLines[l]) << Point(i, d);
			}
		}
	}

	Document doc("my_planes.svg", Layout(Dimensions(maxX + 100, maxY + 100), Layout::BottomLeft));

	// Instantiate an ImprovedLineChart here
	ImprovedLineChart chart(Dimensions(50, 50), scaleFactorX, Stroke(0));

	// Set the point color and the point diameter as desired
	chart.setPointDiameter(.05);
	chart.setPointColor(Color::Black);

	// Add the Polyline to your ImprovedLineChart object here
	for (int l = 0; l < sizeof(averageLines) / sizeof(averageLines[0]); l++) {
		chart << get<1>(averageLines[l]); 
	}

	//Blue image border.
	Polygon border(Stroke(1, Color::Blue));
	border << Point(50, 50) << Point(maxX + 50, 50)
		<< Point(maxX + 50, maxY + 75) << Point(50, maxY + 75);
	doc << border;

	//I would like to loop through these as well but I don't have access to the polyline color without reflection
	//This would require additional changes to the SVG library
	Text legend1(Point(50, 25), "Moving Average: " + to_string(movingAverage1.Get_windowSize()), Color::Blue, Font(12));
	doc << legend1;
	Text legend2(Point(200, 25), "Moving Average: " + to_string(movingAverage2.Get_windowSize()), Color::Orange, Font(12));
	doc << legend2;
	Text legend3(Point(350, 25), "Moving Average: " + to_string(movingAverage3.Get_windowSize()), Color::Red, Font(12));
	doc << legend3;
	
	// Add the chart to doc
	doc << chart;
	doc.save();
}
