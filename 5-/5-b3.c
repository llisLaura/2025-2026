/* 2452640 汽车 罗啦 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int yunnian(int y, int m, int d, int a[]) 
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
	{
		a[2] = 29;
	}
	if (m > 12 || m < 1)
		return 0;
	if(d<1||d>a[m])
		return 1;
	return 2;
}
int sum1(int m, int d, int a[]) 
{
	int sum = 0;
	for (int i = 1; i < m; i++) {
		sum += a[i];
	}
	return sum + d;
}
int main()
{
	int y, m, d;
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &y, &m, &d);
	if (yunnian(y, m, d, a) == 0)
		printf("输入错误-月份不正确\n");
	else if (yunnian(y, m, d, a) == 1)
		printf("输入错误-日与月关系非法\n");
	else if (yunnian(y, m, d, a) == 2) {
		printf("%d-%d-%d是%d年的第%d天\n",y,m,d,y,sum1(m,d,a));
	}
	return 0;
}

