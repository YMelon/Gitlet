// experiment-1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class Animal {
public:
	int age;
};

class Dog : public Animal {
public:
	void setAge(int n) {
		age = n;
	}
};

int main()
{
	Dog d;
	d.setAge(3);

    return 0;
}

