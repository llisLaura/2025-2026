/* 2452640 汽车 罗啦 */
#include <iostream> 
#include<iomanip>
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

void calendar(int year, int month)
{
	/* 按需添加代码 */
	int d = zeller(year, month, 1);
	int dd;
	if (month == 1)
		dd = 31;
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		dd = 29;
	else if (month == 2)
		dd = 28;
	if (month == 3)
		dd = 31;
	if (month == 4)
		dd = 30;
	if (month == 5)
		dd = 31;
	if (month == 6)
		dd = 30;
	if (month == 7)
		dd = 31;
	if (month == 8)
		dd = 31;
	if (month == 9)
		dd = 30;
	if (month == 10)
		dd = 31;
	if (month == 11)
		dd = 30;
	if (month == 12)
		dd = 31;
	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */
	if (d != 0)
		cout << "    ";
	for (int i = 1; i < d; i++)
		cout << "        ";
	for (int i = d, j = 1; i < dd + d; i++, j++)
	{
		if ((i + 1) % 7 == 1)
		{
			cout << setiosflags(ios::right) << setw(4) << j;
		}
		else if ((i + 1) % 7 == 0 && j != dd)
			cout << setw(8) << j << endl;
		else
			cout << setw(8) << j;
	}
	cout << endl;
	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}


int main()
{
	int y, m;
	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> y >> m ;
		if (y >= 1900 && y <= 2100 && m >= 1 && m <= 12  && cin.good())
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
	}
	cout << endl;
	calendar(y, m);
	return 0;
}
