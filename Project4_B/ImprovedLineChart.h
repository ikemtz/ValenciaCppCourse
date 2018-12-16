#ifndef IMPROVEDLINECHART_H
#define IMPROVEDLINECHART_H

#include <string>
#include "simple_svg_1.0.0.hpp"

// Notice how straightforward it is to extend the functionality
// of the LineChart class by sub-classing it and over-riding
// the polyLineToString ( ) method so that the size of the points
// is alterable.

using namespace std ;
using namespace svg ;

class ImprovedLineChart : public svg::LineChart
{
    public:
        ImprovedLineChart();
        virtual ~ImprovedLineChart();

        void setPointDiameter ( double pDiameter ) ;
        void setPointColor ( svg::Fill pColor ) ;

        ImprovedLineChart(svg::Dimensions margin = svg::Dimensions(), double scale = 1,
                  svg::Stroke const & axis_stroke = svg::Stroke(.5, svg::Color::Purple)) ;
    protected:
    private:
        double _diameter ;
        svg::Fill _color ;

        string polylineToString(svg::Polyline const & polyline, svg::Layout const & layout) const ;
};

#endif // IMPROVEDLINECHART_H
