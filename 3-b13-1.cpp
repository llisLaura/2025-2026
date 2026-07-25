/* 2452640 汽车 罗啦 */
#include <iostream>
#include<iomanip>
#include <limits>
#include <math.h>
using namespace std;

int main()
{
	int y,m,d;

	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> y>>m;  
		if (y >= 2000 && y <= 2030 && m>=1 && m<=12 && cin.good())
			break;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "输入非法，请重新输入" << endl;

	}
	while (1) {
		cout << "请输入"<<y<<"年"<<m<<"月1日的星期(0-6表示星期日-星期六) : ";
		cin >> d;
		if (d>=0 && d<=6 && cin.good())
			break;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "输入非法，请重新输入" << endl;

	}
	int dd;
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
	cout << endl;
	cout << y << "年" << m << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六"<<endl;
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
		else if ((i + 1) % 7 == 0 && j!=dd)
			cout << setw(8) << j << endl;
		else
			cout << setw(8) << j;
	}
	cout << endl;
	return 0;
}
