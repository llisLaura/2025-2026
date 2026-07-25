/* 2452640 汽车 罗啦 */
#include <iostream>
#include <iomanip>
#include<limits>
using namespace std;

int max(int x1, int x2)
{
    int t;
    t = x1 > x2 ? x1 : x2;
    return t;
 }
int max(int x1, int x2, int x3)
{
	int t;
	t = x1 > x2 ? x1 : x2;
	t = t > x3 ? t : x3;
	return t;
}
int max(int x1, int x2, int x3,int x4)
{
    int t;
    t = x1 > x2 ? x1 : x2;
    t = t > x3 ? t : x3;
    t = t > x4 ? t : x4;
    return t;
}
int main()
{
	int n,x1=0,x2=0,x3=0,x4=0;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> n;
		if (n == 2)
			cin >> x1 >> x2;
		if (n == 3)
			cin >> x1 >> x2 >> x3;
		if (n == 4)
			cin >> x1 >> x2 >> x3 >> x4;
		if (n >= 2 && n <= 4 && cin.good())
		{
			if (n == 2 && x1 > 0 && x2 > 0)
				break;
			if (n == 3 && x1 > 0 && x2 > 0 && x3 > 0)
				break;
			if (n == 4 && x1 > 0 && x2 > 0 && x3 > 0 && x4 > 0)
				break;
		}
		else if ((n > 4 || n < 2)&&cin.good())
		{
			cout << "个数输入错误" << endl;
			break;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	}
	if (n == 2)
		cout<<"max="<<max(x1, x2)<<endl;
	if (n == 3)
		cout << "max=" << max(x1, x2, x3) << endl;
	if (n == 4)
		cout << "max=" << max(x1, x2, x3, x4)<< endl;
    return 0;
}