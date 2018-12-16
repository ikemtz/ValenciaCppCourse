// This class represents a series of data points as stored
// in a data file.

#include <string>
#include <vector>

#ifndef DATASERIES_H
#define DATASERIES_H
using namespace std ;

class DataSeries
{
    protected:
        vector<string> _dataPoints ;
        int _elemNo ;

    public:
        DataSeries ( ) ;
        DataSeries(string pFname);
        virtual ~DataSeries();

        int nextValue ( ) ;
        void reset ( ) ;
        int length ( ) ;
};

#endif // DATASERIES_H
