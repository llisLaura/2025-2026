/* 2452640 汽车 罗啦 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d)
{
	if (m == 1) {
		y--;
		m = 13;
	}
	if (m == 2) {
		y--;
		m = 14;
	}
	int c = y / 100;
	y = y % 100;
	int w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0) {
		w += 7;
	}
	return (w % 7);
}
void calendar(int year, int month)
{
	/* 按需添加代码 */
	int d = zeller(year, month, 1);
	int dd;
	if (month == 1)
		dd = 31;
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		dd = 29;
	else if (month == 2)
		dd = 28;
	if (month == 3)
		dd = 31;
	if (month == 4)
		dd = 30;
	if (month == 5)
		dd = 31;
	if (month == 6)
		dd = 30;
	if (month == 7)
		dd = 31;
	if (month == 8)
		dd = 31;
	if (month == 9)
		dd = 30;
	if (month == 10)
		dd = 31;
	if (month == 11)
		dd = 30;
	if (month == 12)
		dd = 31;
	printf("\n");
	printf("%d年%d月\n", year, month);
	/* 头部分隔线，不算打表 */
	printf("======================================================\n");
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	printf("======================================================\n");

	/* 按需添加代码 */
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
		else if ((i + 1) % 7 == 0 && j != dd)
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
	/* 尾部分隔线，不算打表 */
	printf("\n");
	printf("======================================================\n");
}


int main()
{
	int y, m;
	int ret1;
	while (1) {
		printf("请输入年[1900-2100]、月\n");
		ret1 = scanf("%d %d", &y, &m);
		if (ret1 == 2 && (y >= 1900 && y <= 2100 && m >= 1 && m <= 12))
			break;
		if (ret1 != 2) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("输入错误，请重新输入\n");
		}
		else if (!(y >= 1900 && y <= 2100))
			printf("年份不正确，请重新输入\n");
		else if (!(m >= 1 && m <= 12))
			printf("月份不正确，请重新输入\n");
	}
	calendar(y, m);
	return 0;
}

