/*2452640 汽车 罗啦*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double n;
	int a1=0, a2=0, a3=0, a4=0, a5=0, a6=0, a7=0, a8=0, a9=0, a10=0, sum = 0;
	printf("请输入找零值：\n");
	scanf("%lf", &n);
	double n1 = n + (double)0.001;
	int n2 = (int)(n1 * 1000),
		b1 = (n2 / 10000) % 10,
		b2 = (n2 / 1000) % 10,
		b3 = (n2 / 100) % 10,
		b4 = (n2 / 10) % 10;
	if (b1 >= 5)
	{
		b1 -= 5;
		a1++;
		sum++;
	}
	if (b1 >= 2)
	{
		if (b1 >= 4)
		{
			b1 -= 2;
			a2++;
			sum++;
		}
		b1 -= 2;
		a2++;
		sum++;
	}
	if (b1 >= 1)
	{
		b1 -= 1;
		a3++;
		sum++;
	}
	if (b2 >= 5)
	{
		b2 -= 5;
		a4++;
		sum++;
	}
	if (b2 >= 1)
	{
		if (b2 >= 2)
		{
			if (b2 >= 3)
			{
				if (b2 >= 4)
				{
					b2 -= 1;
					a5++;
					sum++;
				}
				b2 -= 1;
				a5++;
				sum++;
			}
			b2 -= 1;
			a5++;
			sum++;
		}
		b2 -= 1;
		a5++;
		sum++;
	}
	if (b3 >= 5)
	{
		b3 -= 5;
		a6++;
		sum++;
	}
	if (b3 >= 1)
	{
		if (b3 >= 2)
		{
			if (b3 >= 3)
			{
				if (b3 >= 4)
				{
					b3 -= 1;
					a7++;
					sum++;
				}
				b3 -= 1;
				a7++;
				sum++;
			}
			b3 -= 1;
			a7++;
			sum++;
		}
		b3 -= 1;
		a7++;
		sum++;
	}
	if (b4 >= 5)
	{
		b4 -= 5;
		a8++;
		sum++;
	}
	if (b4 >= 2)
	{
		if (b4 >= 4)
		{
			b4 -= 2;
			a9++;
			sum++;
		}
		b4 -= 2;
		a9++;
		sum++;
	}
	if (b4 >= 1)
	{
		b4 -= 1;
		a10++;
		sum++;
	}
	printf("共%d张找零，具体如下：\n", sum);
	if(a1)
		printf("50元 : %d张\n", a1);
	if (a2)
		printf("20元 : %d张\n", a2);
	if (a3)
		printf("10元 : %d张\n", a3);
	if (a4)
		printf("5元  : %d张\n", a4);
	if (a5)
		printf("1元  : %d张\n", a5);
	if (a6)
		printf("5角  : %d张\n", a6);
	if (a7)
		printf("1角  : %d张\n", a7);
	if (a8)
		printf("5分  : %d张\n", a8); 
	if (a9)
		printf("2分  : %d张\n", a9);
	if (a10)
		printf("1分  : %d张\n", a10);
	return 0;
}