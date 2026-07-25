/*2452640 汽车 罗啦*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	int a1 = (int)(a / 10),
		b1 = (a1 / 100000000) % 10,
		b2 = (a1 / 10000000) % 10,
		b3 = (a1 / 1000000) % 10,
		b4 = (a1 / 100000) % 10,
		b5 = (a1 / 10000) % 10,
		b6 = (a1 / 1000) % 10,
		b7 = (a1 / 100) % 10,
		b8 = (a1 / 10) % 10;
	double a2 = a - (double)b1 * 1000000000 - (double)b2 * 100000000 - (double)b3 * 10000000 - (double)b4 * 1000000,
		a3 = a2 + (double)0.001;
	int a4 = (int)(a3 * 1000),
		b9 = (a4 / 10000) % 10,
		b10 = (a4 / 1000) % 10,
		b11 = (a4 / 100) % 10,
		b12 = (a4 / 10) % 10;
	cout << "十亿位 : " << b1 << endl;
	cout << "亿位   : " << b2 << endl;
	cout << "千万位 : " << b3 << endl;
	cout << "百万位 : " << b4 << endl;
	cout << "十万位 : " << b5 << endl;
	cout << "万位   : " << b6 << endl;
	cout << "千位   : " << b7 << endl;
	cout << "百位   : " << b8 << endl;
	cout << "十位   : " << b9 << endl;
	cout << "圆     : " << b10 << endl;
	cout << "角     : " << b11 << endl;
	cout << "分     : " << b12 << endl;
	return 0;
}