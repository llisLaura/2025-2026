/*2452640 Æû³µ ÂÞÀ²*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i * j >= 10)
				printf("%dx%d=%d  ", j, i, i * j);
			else
				printf("%dx%d=%d   ", j, i, i * j);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}