#ifndef FILTER_H
#define FILTER_H

#include <deque>

using namespace std ;
class Filter
{
    public:
        Filter ( ) ;
		Filter(int pWin) :_windowSize(pWin) {}
        virtual ~Filter() {} ;
		int Get_windowSize() { return _windowSize; }
        void Set_windowSize(int val) { _windowSize = val; }

        virtual void input ( double pIn ) = 0 ;
        virtual double output ( ) = 0 ;

    protected:
        deque<double> _buffer;
        int _windowSize;

    private:

};

#endif // FILTER_H
