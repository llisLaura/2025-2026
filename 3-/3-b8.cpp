/*2452640 汽车 罗啦*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int x, n;
	double sum = 0, cnt = 1;
	for (;;)
	{
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
		if (x >= -10 && x <= 65)
			break;
		cout << "输入非法，请重新输入" << endl;
	}
	for (int i = 1;; i++)
	{
		sum += cnt;
		cnt = 1;
		for (int j = i; j > 0; j--)
		{
			cnt *= x;
			cnt /= j;
		}
		if (fabs(cnt) < 1e-6)
		{
			n = i;
			break;
		}
	}
	cout << "迭代终值 n=" << n << " |x^" << n << "/" << n << "!|=" << setprecision(10) << cnt << endl;
	cout << "e^" << x << "=" << setprecision(10) << sum << endl;
	return 0;
}