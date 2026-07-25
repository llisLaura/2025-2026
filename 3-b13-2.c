/* 2452640 汽车 罗啦 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int y, m, d;
	int ret1,ret2;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret1=scanf("%d %d", &y,&m); 
		if (ret1 != 2) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
		if (ret1 == 2 && (y >= 2000 && y <= 2030 && m >= 1 && m <= 12))
			break;
		printf("输入非法，请重新输入\n");
	}
	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",y,m);
		ret2=scanf("%d", &d);
		if (ret2 != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
		if (ret2 == 1 && (d >= 0 && d <= 6))
			break;
		printf("输入非法，请重新输入\n");
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
	printf("\n");
	printf("%d年%d月的月历为:\n",y,m);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	printf("    ");
	for (int i = 1; i < d; i++)
		printf("        ");
	for (int i = d, j = 1; i < dd + d; i++, j++)
	{
		if ((i + 1) % 7 == 1)
		{
			if (j > 9)
				printf("  %d", j);
			else
				printf("   %d", j);
		}
		else if ((i + 1) % 7 == 0 &&j!=dd)
		{
			if (j > 9)
				printf("      %d\n", j);
			else
				printf("       %d\n", j);
		}
		else
		{
			if (j > 9)
				printf("      %d", j);
			else
				printf("       %d", j);
		}
	}
	printf("\n");

	return 0;
}

