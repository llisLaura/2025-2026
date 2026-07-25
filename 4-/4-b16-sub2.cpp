/* 2452640 汽车 罗啦 */
#include <iostream>
#include<iomanip>
#include <limits>
#include <math.h>
using namespace std;

void fun2(double a, double b, double c)
{
	double x1, x2;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	double t = x1;
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
