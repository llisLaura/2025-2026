/* 2452640 汽车 罗啦 */
#include <iostream> 
#include<string.h>
using namespace std;
const char chnstr[] = "零壹贰叁肆伍陆柒捌玖";
string result;
void daxie(int num, int flag_of_zero)
{
	string t;
	t = string(chnstr + num * 2, 2);
	switch (num) {
	case 0:
		if (flag_of_zero)
			result += t;
		break;
	default:
		result += t;
		break;
	}
}

int main()
{
	double a = 1;
	int Flag1 = 1, Flag2 = 1, Flag3 = 1;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	cout << "大写结果是:" << endl;
	int a1, b1, b2, b3, b4, b5, b6, b7, b8, a4, b9, b10, b11, b12;
	a1 = (int)(a / 10),
		b1 = (a1 / 100000000) % 10,
		b2 = (a1 / 10000000) % 10,
		b3 = (a1 / 1000000) % 10,
		b4 = (a1 / 100000) % 10,
		b5 = (a1 / 10000) % 10,
		b6 = (a1 / 1000) % 10,
		b7 = (a1 / 100) % 10,
		b8 = (a1 / 10) % 10;
	double a2 = a - (double)b1 * 1000000000 - (double)b2 * 100000000 - (double)b3 * 10000000 - (double)b4 * 1000000;
	double a3 = a2 + (double)0.001;
	a4 = (int)(a3 * 1000),
		b9 = (a4 / 10000) % 10,
		b10 = (a4 / 1000) % 10,
		b11 = (a4 / 100) % 10,
		b12 = (a4 / 10) % 10;
		string r[11] = { "拾" ,"亿" ,"仟" ,"佰" , "拾" ,"万", "圆" ,"角" ,"分","整","圆整" };
	if (b1 != 0)
	{
		daxie(b1, 0);
		result+=r[0];
		daxie(b2, 0);
		result += r[1];
	}
	else if (b2 != 0)
	{
		daxie(b2, 0);
		result += r[1];
	}
	else
		Flag1 = 0;//表示没有亿位
	if (b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0)
		Flag2 = 0;
	daxie(b3, (Flag1 && Flag2));
	if (b3 != 0)
		result += r[2];
	daxie(b4, (b3 != 0 && (b5 != 0 || b6 != 0)));
	if (b4 != 0)
		result += r[3];
	daxie(b5, (b4 != 0 && b6 != 0));
	if (b5 != 0)
		result += r[4];
	daxie(b6, 0);
	if (Flag2)
		result += r[5];
	if (b7 == 0 && b8 == 0 && b9 == 0 && b10 == 0)
		Flag3 = 0;
	else
		Flag3 = 1;
	daxie(0, (Flag1 && !Flag2 && Flag3));
	daxie(b7, (Flag2 && Flag3));
	if (b7 != 0)
		result += r[2];
	daxie(b8, (b7 != 0 && (b9 != 0 || b10 != 0)));
	if (b8 != 0)
		result += r[3];
	daxie(b9, (b8 != 0 && b10 != 0));
	if (b9 != 0)
		result += r[4];
	daxie(b10, 0);
	if (Flag3 || Flag2 || Flag1)
		result += r[6];
	daxie(b11, (b12 != 0 && (Flag1 || Flag2 || Flag3)));
	if (b11 != 0)
		result += r[7];
	daxie(b12, !(Flag1 || Flag2 || Flag3 || b11));
	if (b12 == 0)
	{
		if ((Flag1 || Flag2 || Flag3 || b11))
			result += r[9];
		else
			result += r[10];
	}
	else
		result += r[8];
	cout << result << endl;
	return 0;
}