#pragma once
class MovingAverage :public Filter
{
public:
	MovingAverage(int pWin) :Filter(pWin) {}
	void input(double pin) {
		_buffer.push_back(pin);
		if (_windowSize < _buffer.size())
		{
			_buffer.pop_front();
		}
	}
	double output() {
		double d = 0;
		if (_windowSize == _buffer.size())
		{
			for (auto it = _buffer.crbegin(); it != _buffer.crend(); ++it) {

				d += *it;
			}
		}
		return d / _buffer.size();
	}
};
