/* 2452640 汽车 罗啦 */
#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (x >= 0 && x <= 100 && cin.good())
			break;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
	}

	cout << "cin.fail()=" << cin.fail() << " x=" << x << endl; //此句不准动，并且要求输出时fail为0

	return 0;
}
