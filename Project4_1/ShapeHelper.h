#pragma once
#include "pch.h"
#include "simple_svg_1.0.0.hpp"

using namespace svg;
class ShapeHelper
{
	public:
		static Polygon arrowFactory(int startX, int startY, Fill const & fill = Fill(Color::Blue)) {
			startX += 5;
			startY += 7;
			Polygon polygon(fill);
			polygon << Point(startX, startY)
				<< Point(startX + 5, startY + 10)
				<< Point(startX + 3, startY + 10)
				<< Point(startX + 3, startY + 20)
				<< Point(startX + -3, startY + 20)
				<< Point(startX + -3, startY + 10)
				<< Point(startX - 5, startY + 10)
				<< Point(startX, startY);
			return polygon;
		}

		static Polygon planeFactory(int startX, int startY, Fill const & fill = Fill(Color::Blue)) {
			startX += 5;
			startY += 7;
			Polygon polygon(fill);
			polygon << Point(startX, startY)
				<< Point(startX + 2, startY + 2)
				<< Point(startX + 2, startY + 9)
				<< Point(startX + 10, startY + 12)
				<< Point(startX + 10, startY + 14)
				<< Point(startX + 2, startY + 13)
				<< Point(startX + 2, startY + 20)
				<< Point(startX + 5, startY + 21)
				<< Point(startX + 5, startY + 22)


				<< Point(startX + 1, startY + 22)
				<< Point(startX + 0, startY + 23)
				<< Point(startX - 1, startY + 22)

				<< Point(startX - 5, startY + 22) 
				<< Point(startX - 5, startY + 21)
				<< Point(startX - 2, startY + 20)
				<< Point(startX - 2, startY + 13)
				<< Point(startX - 10, startY + 14)
				<< Point(startX - 10, startY + 12)
				<< Point(startX - 2, startY + 9)
				<< Point(startX - 2, startY + 2)
				<< Point(startX, startY);
			return polygon;
		}
};