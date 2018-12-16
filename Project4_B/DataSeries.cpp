#include "pch.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <stdlib.h>

#include "DataSeries.h"

DataSeries::DataSeries()
{
     _elemNo = 0 ;
}

DataSeries::DataSeries(string pFname)
{

    char temp [100] = { 0 } ;
    ifstream fileStream  ( pFname.c_str ( ) );
    fileStream.getline ( temp, 99 ) ;
    while ( !fileStream.eof ( ) )
    {
        _dataPoints.push_back ( string ( temp ) )  ;
        fileStream.getline ( temp, 99 ) ;
    }
    _elemNo = 0 ;
}

DataSeries::~DataSeries()
{
    //dtor
}

 int DataSeries::nextValue ( )
 {
     // based on: http://stackoverflow.com/questions/236129/split-a-string-in-c
    int tmp = -1 ;
    string tmpString ;
    if ( ( unsigned ) _elemNo < _dataPoints.size ( ) )
    {
        istringstream iss ( _dataPoints[_elemNo]) ;
        getline ( iss, tmpString, ',') ;
        // I know there must be a true C++ way to convert
        // a string to an int, and perhaps it is quite elegant.
        // But after 30 minutes of fooling with it, heck, I'll
        // just drop back into C for a moment.
        tmp = atoi ( tmpString.c_str ( ) ) ;
        _elemNo ++ ;
    }

    return tmp ;

 }

 int DataSeries::length ( )
 {
     return _dataPoints.size ( )  ;
 }
