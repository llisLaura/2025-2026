/* 2452640 汽车 罗啦 */
#include <iostream> 
using namespace std;

int main()
{
	int y, m, d,sum=0;
	int d1 = 31, d2 = 28, d3 = 31, d4 = 30, d5 = 31, d6 = 30, d7 = 31, d8 = 31, d9 = 30, d10 = 31, d11 = 30, d12 = 31;
	cout << "请输入年，月，日" << endl;
	cin >> y >> m >> d;
	if ((y % 4 == 0 && y % 100 != 0)||y % 400 == 0)
	{
		d2 = 29;
	}
	if (m > 12 || m < 1)
		cout << "输入错误-月份不正确" << endl;
	else if ((m == 1 && d > d1) || (m == 2 && d > d2) || (m == 3 && d > d3) || (m == 4 && d > d4)
			|| (m == 5 && d > d5) || (m == 6 && d > d6) || (m == 7 && d > d7)
			|| (m == 8 && d > d8) || (m == 9 && d > d9) || (m == 10 && d > d10)
			|| (m == 11 && d > d11) || (m == 12 && d > d12) || d < 1)
			cout << "输入错误-日与月关系非法" << endl;
	else
	{
		if (m == 1)
			sum = d;
		else if (m == 2)
			sum = d1 + d;
		else if (m == 3)
			sum = d1 + d2 + d;
		else if (m == 4)
			sum = d1 + d2 + d3 + d;
		else if (m == 5)
			sum = d1 + d2 + d3 + d4 + d5 + d;
		else if (m == 6)
			sum = d1 + d2 + d3 + d4 + d5 + d6 + d;
		else if (m == 7)
			sum = d1 + d2 + d3 + d4 + d5 + d6 + d7 + d;
		else if (m == 8)
			sum = d1 + d2 + d3 + d4 + d5 + d6 + d7+ d8 + d;
		else if (m == 9)
			sum = d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9+ d;
		else if (m == 10)
			sum = d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 +d10+ d;
		else if (m == 11)
			sum = d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 +d10+ d;
		else if (m == 12)
			sum = d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 + d10 +d11+ d;
		cout << y << "-" << m << "-" << d << "是" << y << "年的第" << sum << "天" << endl;
	}

	return 0;
}
