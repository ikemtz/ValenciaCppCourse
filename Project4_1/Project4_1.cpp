// Project4_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "simple_svg_1.0.0.hpp"
#include "ShapeHelper.h"

using namespace svg;
int main()
{
	Dimensions dimensions(300, 300);
	Document doc("my_svg.svg", Layout(dimensions, Layout::BottomLeft));

	// Red image border.
	Polygon border(Stroke(1, Color::Red));
	border << Point(0, 0) << Point(dimensions.width, 0)
		<< Point(dimensions.width, dimensions.height) << Point(0, dimensions.height);
	doc << border;

	// Long notation.  Local variable is created, children are added to varaible.
	LineChart chart(5.0);
	Polyline polyline_a(Stroke(.5, Color::Blue));

	polyline_a << Point(0, 0) << Point(30, 90)
		<< Point(60, 120) << Point(90, 130) << Point(120, 129);
	doc
		<< ShapeHelper::arrowFactory(90, 130, Color::Green)
		<< ShapeHelper::arrowFactory(30, 90, Color::Yellow)
		<< ShapeHelper::planeFactory(120, 129, Color::Black);
	Text text(Point(200, 200), "Hello World", Color::Red);
	doc << text;
	chart << polyline_a;
	doc << chart;

	doc.save();
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
