/*2452640 汽车 罗啦*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入[0-100亿)之间的数字:\n");
	double a;
	scanf("%lf", &a);
	int a1 = (int)(a / 10),
		b1 = (a1 / 100000000) % 10,
		b2 = (a1 / 10000000) % 10,
		b3 = (a1 / 1000000) % 10,
		b4 = (a1 / 100000) % 10,
		b5 = (a1 / 10000) % 10,
		b6 = (a1 / 1000) % 10,
		b7 = (a1 / 100) % 10,
		b8 = (a1 / 10) % 10;
	double a2 = a - (double)b1 * 1000000000 - (double)b2 * 100000000 - (double)b3 * 10000000 - (double)b4 * 1000000,
		a3 = a2 + (double)0.001;
	int a4 = (int)(a3 * 1000),
		b9 = (a4 / 10000) % 10,
		b10 = (a4 / 1000) % 10,
		b11 = (a4 / 100) % 10,
		b12 = (a4 / 10) % 10;
	
	printf("十亿位 : %d\n", b1);
	printf("亿位   : %d\n", b2);
	printf("千万位 : %d\n", b3);
	printf("百万位 : %d\n", b4);
	printf("十万位 : %d\n", b5);
	printf("万位   : %d\n", b6);
	printf("千位   : %d\n", b7);
	printf("百位   : %d\n", b8);
	printf("十位   : %d\n", b9);
	printf("圆     : %d\n", b10);
	printf("角     : %d\n", b11);
	printf("分     : %d\n", b12);
	return 0;

}