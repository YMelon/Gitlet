// virtual-func.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Base1 {
public:
	virtual void display() const;
};

void Base1::display() const {
	cout << "Base1::display()" << endl;
}

class Base2 : public Base1 {
public:
	void display() const;
};

void Base2::display() const {
	cout << "Base2::display()" << endl;
}

class Derived : public Base2 {
public:
	void display() const;
};

void Derived::display() const {
	cout << "Derived::display()" << endl;
}

void fun(Base1 *ptr) {
	ptr->display();
}

void func(Base1 b) {  //display()为虚函数时，
	//通过引用而不是对象调用也可以实现多态，不是虚函数则不可以
	b.display();
}


int main()
{
	Base1 b1;
	Base2 b2;
	Derived d;
	fun(&b1);
	fun(&b2);
	fun(&d);

	cout << "Call display() through object!" << endl;
	func(b1);
	func(b2);
	func(d);

    return 0;
}

