/* 2452640 汽车 罗啦 */
#include <iostream>
#include<iomanip>
#include <limits>
#include <math.h>
using namespace std;

void fun4(double a, double b, double c)
{
	double x11, x12, x21, x22;
	x11 = -b / (2 * a);
	x12 = sqrt(4 * a * c - b * b) / (2 * a);
	x21 = -b / (2 * a);
	x22 = -sqrt(4 * a * c - b * b) / (2 * a);
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
	if (x11 != 0 || fabs(x11) >= 1e-6)
		cout << x11;
	if (fabs(x12 - 1) < 1e-6)
		cout << "i" << endl;
	else if (fabs(x11) < 1e-6)
		cout << x12 << "i" << endl;
	else
		cout << showpos << x12 << "i" << endl;
	cout << noshowpos;
	cout << "x2=";
	if (x21 != 0 || fabs(x21) >= 1e-6)
		cout << x21;
	if (fabs(x22 + 1) < 1e-6)
		cout << "-i" << endl;
	else
		cout << showpos << x22 << "i" << endl;
	cout << noshowpos;
}