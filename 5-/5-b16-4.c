/* 2452640 汽车 罗啦 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int tj_strcpy(char s1[], const char s2[])
{
	int i;
	for (i = 0; s2[i] != '\0'; i++)
		s1[i] = s2[i];
	s1[i] = '\0';
	return 0;
}
int tj_strcmp(const char s1[], const char s2[])
{
	int t = 0;
	int i;
	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
		if (s1[i] != s2[i]) {
			t = (s1[i] - s2[i]);
			break;
		}
	}
	return t;
}
int main() {
	char num[10][8], name[10][9];
	int score[10];
	for (int i = 0; i < 10; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", num[i], name[i], &score[i]);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (score[j]<score[j+1]) {
				int t = score[j];
				score[j] = score[j + 1];
				score[j + 1] = t;
				char tmp[9] = { 0 };
				tj_strcpy(tmp, num[j + 1]);
				tj_strcpy(num[j + 1], num[j]);
				tj_strcpy(num[j], tmp);
				tj_strcpy(tmp, name[j + 1]);
				tj_strcpy(name[j + 1], name[j]);
				tj_strcpy(name[j], tmp);
			}
		}
	}
	printf("\n全部学生(成绩降序):\n");
	for (int i = 0; i < 10; i++) {
			printf("%s %s %d\n", name[i], num[i], score[i]);
	}
	return 0;
}