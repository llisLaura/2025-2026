/* 2452640 汽车 罗啦 */
#include <iostream>
#include<iomanip>
#include <limits>
#include <math.h>
using namespace std;


void fun1(double a, double b, double c)
{
	cout << "不是一元二次方程" << endl;
}
void fun2(double a, double b, double c)
{
	double x1, x2;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	double t=x1;
	x1 = x1 > x2 ? x1 : x2;
	x2 = x1 > x2 ? x2 : t;
	if (fabs(x1) < 1e-6)
		x1 = 0; 
	if (fabs(x2) < 1e-6)
		x2 = 0;
	cout << "有两个不等实根：" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

void fun3(double a, double b, double c)
{
	double x;
	x = -b  / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x << endl;
}
void fun4(double a, double b, double c)
{
	double x11,x12,x21,x22;
	x11 = -b / (2 * a);
	x12 = sqrt( 4 * a * c-b * b)/(2*a);
	x21 = -b / (2 * a);
	x22 = -sqrt(4 * a * c-b * b)/(2*a);
	double t = x12;
	x12 = x12 > x22 ? x12 : x22;
	x22 = x12 > x22 ? x22 : t;
	if (fabs(x11) < 1e-6)
		x11 = 0; 
	if (fabs(x12) < 1e-6)
		x12 = 0; 
	if (fabs(x21) < 1e-6)
		x21 = 0; 
	if (fabs(x22) < 1e-6)
		x22 = 0;
	cout << "有两个虚根：" << endl;
	cout << "x1=";
	if (x11 != 0||fabs(x11)>=1e-6)
		cout <<x11;
	if(fabs(x12-1)<1e-6)
	cout<< "i" << endl;
	else if(fabs(x11)<1e-6)
		cout << x12 << "i" << endl;
	else
		cout<< showpos << x12 << "i" <<endl;
	cout << noshowpos;
	cout << "x2=";
	if (x21 != 0||fabs(x21)>=1e-6)
		cout << x21;
	if (fabs(x22+1) <1e-6)
		cout << "-i" << endl;
	else 
		cout << showpos << x22 << "i"<<endl;
	cout << noshowpos;
}
int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	double a, b, c;
	cin >> a >> b >> c;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;
	if (fabs(a) < 1e-6) {
		a = 0;
		fun1(a, b, c);
	}
	else if (b * b - 4 * a * c > 1e-6)
		fun2(a, b, c);
	else if (b * b - 4 * a * c == 1e-6)
		fun3(a, b, c);
	else if (b * b - 4 * a * c < 1e-6)
		fun4(a, b, c);
	return 0;
}
