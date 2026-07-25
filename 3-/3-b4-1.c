/*2452640 汽车 罗啦*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	const double Pi = 3.14159;
	printf("请输入三角形的两边及其夹角(角度)\n");
	int a,b,n;
	scanf("%d %d %d", &a, &b, &n);
	printf("三角形面积为 : %.3f", 0.5*a * b * sin(n/180.0*Pi));
	return 0;

}
