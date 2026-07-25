/* 2452640 Æû³µ ÂŞÀ² */
/* 2551313 ÂóÉÜ½ú 2552312 Ñîéğº­ 2550325 ÎâÓÆ 2450255 èïÓıÓ± 2550904 Íõºèî£ 2554464 ÁõâùÁÕ 2553569 ×ŞË¼Í® */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char a[12][28] = {0};
	int cnt = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 26; j++) {
			scanf("%c ", &a[i][j]);
			if (a[i][j] == '*')
				cnt++;
		}	
	}
	if (cnt != 50)
	{
		printf("´íÎó1\n");
		return 0;
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 26; j++) {
			if (a[i][j] != '*') {
				int sum = 0;
				if (a[i - 1][j - 1] == '*')
					sum++;
				if (a[i - 1][j] == '*')
					sum++;
				if (a[i - 1][j + 1] == '*')
					sum++;
				if (a[i][j - 1] == '*')
					sum++;
				if (a[i][j + 1] == '*')
					sum++;
				if (a[i + 1][j - 1] == '*')
					sum++;
				if (a[i + 1][j] == '*')
					sum++;
				if (a[i + 1][j + 1] == '*')
					sum++;
				if (a[i][j] != sum+'0') {
					printf("´íÎó2\n");
					return 0;
				}
			}

		}
	}
	printf("ÕıÈ·\n");
	return 0;
}
