// override-1operator.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Clock {
private:
	int hour;
	int minute;
	int second;

public:
	Clock(int h = 0, int m = 0, int s = 0);
	void showTime() const;

	//重载前置++和后置++
	Clock &operator++();
	Clock operator++(int);
};

Clock::Clock(int h, int m, int s) {
	if (0 <= h && h < 24 && 0 <= m && m < 60 && 0 <= s && s < 60) {
		hour = h;
		minute = m;
		second = s;
	}else {
		cout << "Time error!" << endl;
	}
}

void Clock::showTime() const {
	cout << hour << ":" << minute << ":" << second << endl;
}

Clock &Clock::operator++() {
	second++;
	if (second >= 60) {
		second -= 60;
		minute++;
		if (minute >= 60) {
			minute -= 60;
			hour = (hour+1) % 24;
		}
	}
	return *this;
}

Clock Clock::operator++(int) {
	Clock old = *this;
	++(*this);

	return old;
}


int main()
{
	Clock c(19, 56, 50);
	cout << "Fist time output: ";
	c.showTime();
	cout << "Show c++:    ";
	(c++).showTime();
	cout << "Show ++c:    ";
	(++c).showTime();

    return 0;
}

