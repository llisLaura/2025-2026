/* 2452640 汽车 罗啦 */
#include <iostream> 
using namespace std;
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
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
		int a1,b1,b2,b3,b4,b5,b6,b7,b8,a4,b9,b10,b11,b12;
		a1= (int)(a / 10),
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
	if (b1 != 0)
	{
		daxie(b1,0);
		cout << "拾";
		daxie(b2,0);
		cout << "亿";
	}
	else if (b2 != 0)
	{
		daxie(b2,0);
		cout << "亿";
	}
	else
		Flag1 = 0;//表示没有亿位
	if (b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0)
		Flag2 = 0;
	daxie(b3, (Flag1 && Flag2));
	if (b3 != 0)
		cout << "仟";
	daxie(b4, (b3 != 0 && (b5 != 0 || b6 != 0)));
	if (b4 != 0)
		cout << "佰";
	daxie(b5, (b4 != 0 && b6 != 0));
	if (b5 != 0)
		cout << "拾";
	daxie(b6, 0);
	if (Flag2)
		cout << "万";
	if (b7 == 0 && b8 == 0 && b9 == 0 && b10 == 0)
		Flag3 = 0;
	else
		Flag3 = 1;
	daxie(0, (Flag1 && !Flag2 && Flag3));
	daxie(b7, (Flag2 && Flag3));
	if (b7 != 0)
		cout << "仟";
	daxie(b8, (b7 != 0 && (b9 != 0 || b10 != 0)));
	if (b8 != 0)
		cout << "佰";
	daxie(b9,(b8 != 0 && b10 != 0) );
	if (b9 != 0)
		cout << "拾";
	daxie(b10, 0);
	if (Flag3 || Flag2 || Flag1)
		cout << "圆";
	daxie(b11,(b12 != 0 && (Flag1 || Flag2 || Flag3)));
	if (b11 != 0)
		cout << "角";
	daxie(b12, !(Flag1 || Flag2 || Flag3 || b11));
	if (b12 == 0)
	{
		if ((Flag1 || Flag2 || Flag3 || b11))
			cout << "整";
		else
			cout << "圆整";
	}
	else
		cout << "分";
	cout << endl;
	return 0;
}