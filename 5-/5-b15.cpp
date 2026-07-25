/* 2452640 汽车 罗啦 */
#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

int main() {
	char str[3][128];
	cout << "请输入第1行" << endl;
	cin.get(str[0], 128);
	getchar();
	cout << "请输入第2行" << endl;
	cin.get(str[1], 128);
	getchar();
	cout << "请输入第3行" << endl;
	cin.get(str[2], 128);
	getchar();
	int i = 0, j = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; str[i][j] != '\0'; j++) {
			if (str[i][j] <= 'Z' && str[i][j] >= 'A') {
				cnt1++;
				continue;
			}
			if (str[i][j] <= 'z' && str[i][j] >= 'a') {
				cnt2++;
				continue;
			}
			if (str[i][j] <= '9' && str[i][j] >= '0') {
				cnt3++;
				continue;
			}
			if (str[i][j] == ' ') {
				cnt4++;
				continue;
			}
			cnt5++;
		}
	}

	cout << "大写 : " << cnt1 << endl;
	cout << "小写 : " << cnt2 << endl;
	cout << "数字 : " << cnt3 << endl;
	cout << "空格 : " << cnt4 << endl;
	cout << "其它 : " << cnt5 << endl;
	return 0;
}
