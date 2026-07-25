/* 2452640 汽车 罗啦 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[101]={0},b[1000], i,cnt=0;
	printf("请输入成绩（最多1000个），负数结束输入\n");
	while (++cnt) {
		scanf("%d", &i);
		if (i < 0 || cnt>1000)
			break;
		b[cnt] = i;
		a[i]++;
	}
	if (cnt == 1) {
		printf("无有效输入\n");
		return 0;
	}
	printf("输入的数组为:\n");
	int j;
	for (j = 1; j < cnt; j++) {
		printf("%d ", b[j]);
		if (j % 10 == 0)
			printf("\n");
	}
	if((j-1) % 10!=0)
	printf("\n");
	printf("分数与人数的对应关系为:\n");
	for (int j = 100; j >= 0; j--) {
		if (a[j] > 0)
			printf("%d %d\n", j, a[j]);
	}
	return 0;
}

