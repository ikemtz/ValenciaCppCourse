#include "pch.h"
#include <string>
//#include "simple_svg_1.0.0.hpp"
#include "ImprovedLineChart.h"


using namespace std ;
//using namespace svg ;

ImprovedLineChart::ImprovedLineChart()
{
    //ctor
}

ImprovedLineChart::~ImprovedLineChart()
{
    //dtor
}

ImprovedLineChart::ImprovedLineChart(svg::Dimensions margin, double scale,
              svg::Stroke const & axis_stroke )
        : svg::LineChart ( margin, scale, axis_stroke )
{
    _diameter = 1 ;
    _color = svg::Color::Red ;
}

void ImprovedLineChart::setPointDiameter ( double pDiameter )
{
    _diameter = pDiameter ;
}

void ImprovedLineChart::setPointColor ( svg::Fill pColor )
{
    _color = pColor ;
}

string ImprovedLineChart::polylineToString(svg::Polyline const & polyline, svg::Layout const & layout) const
{
    svg::Polyline shifted_polyline = polyline;
    shifted_polyline.offset(svg::Point(margin.width, margin.height));

    std::vector<svg::Circle> vertices;
    for (unsigned i = 0; i < shifted_polyline.points.size(); ++i)
        // **** JR hacked the circle radius
        vertices.push_back(svg::Circle(shifted_polyline.points[i], _diameter, _color ));

    return shifted_polyline.toString(layout) + vectorToString(vertices, layout);
}
