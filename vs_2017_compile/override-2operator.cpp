// override-2operator.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Complex {
private:
	double real;
	double imag;

public:
	Complex(double r=0, double i=0)
		:real(r), imag(i) { }
	Complex operator+(const Complex &c) const;
	Complex operator- (const Complex &c) const;

	//实现实数+/-复数操作，重载为非成员函数
	friend Complex operator+(double r, const Complex &c);
	friend Complex operator-(double r, const Complex &c);

	//重载<<运算符
	friend ostream &operator<<(ostream &out, const Complex &c);

	void display() const;
};

Complex Complex::operator+(const Complex &c) const {
	return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator- (const Complex &c) const {
	return Complex(real - c.real, imag - c.imag);
}

void Complex::display() const {
	cout << "(" << real << ", " << imag << ")" << endl;
}

Complex operator+(double r, const Complex &c) {
	return Complex(r + c.real, c.imag);
}
Complex operator-(double r, const Complex &c) {
	return Complex(r - c.real, -c.imag);
}

ostream &operator<<(ostream &out, const Complex &c) {
	out << "(" << c.real << ", " << c.imag << ")";
	return out;
}

int main()
{
	Complex c1(5, 4), c2(2, 10), c3;
	double real = 6;
	cout << "c1= "; c1.display();
	cout << "overide '<<' output: " << "c1= " << c1 << endl;
	cout << "c2= "; c2.display();
	cout << "overide '<<' output: " << "c2= " << c2 << endl;

	c3 = c1 - c2;
	cout << "c1-c2= "; c3.display();
	c3 = c1 + c2; 
	cout << "c1+c2= "; c3.display();

	c3 = real - c1;
	cout << "real-c1= "; c3.display();
	c3 = real + c1;
	cout << "real+c1= "; c3.display();

    return 0;
}

