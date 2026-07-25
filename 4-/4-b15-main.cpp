/* 2452640 汽车 罗啦 */
#include <iostream>
#include<iomanip>
#include <limits>
#include <math.h>
using namespace std;


void fun1(double a, double b, double c);
void fun2(double a, double b, double c);
void fun3(double a, double b, double c);
void fun4(double a, double b, double c);
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
