/* 2452640 汽车 罗啦 */
#include <iostream> 
#include<limits>
using namespace std;

int zeller(int y, int m, int d)
{
	if (m == 1) {
		y--;
		m = 13;
	}
	if (m == 2) {
		y--;
		m = 14;
	}
	int c = y / 100;
	y = y % 100;
	int w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0) {
		w += 7;
	}
	return (w % 7);
}

int main()
{
	int y, m, d;
	while (1) {
		cout << "请输入年[1900-2100]、月、日："<<endl;
		cin >> y>>m>>d; 
		int dd=0;
		if (m == 1)
			dd = 31;
		if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
			dd = 29;
		else if (m == 2)
			dd = 28;
		if (m == 3)
			dd = 31; 
		if (m == 4)
			dd = 30; 
		if (m == 5)
			dd = 31; 
		if (m == 6)
			dd = 30; 
		if (m == 7)
			dd = 31; 
		if (m == 8)
			dd = 31; 
		if (m == 9)
			dd = 30; 
		if (m == 10)
			dd = 31; 
		if (m == 11)
			dd = 30;
		if (m == 12)
			dd = 31;
		if (y >= 1900 && y <= 2100 && m>=1 && m<=12 && d>0 &&d<=dd && cin.good())
			break;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
		}
		else if (!(y >= 1900 && y <= 2100))
			cout << "年份不正确，请重新输入" << endl;
		else if (!(m >= 1 && m <= 12))
			cout << "月份不正确，请重新输入" << endl;
		else if (!(d > 0 && d <= dd))
			cout << "日不正确，请重新输入" << endl;
		
	}
	cout << "星期";
	switch (zeller(y, m, d))
	{
	case 0:
		cout << "日";
		break;
	case 1:
		cout << "一";
		break;
	case 2:
		cout << "二";
		break;
	case 3:
		cout << "三";
		break;
	case 4:
		cout << "四";
		break;
	case 5:
		cout << "五";
		break;
	case 6:
		cout << "六";
		break;
	}
	cout << endl;

	return 0;
}
