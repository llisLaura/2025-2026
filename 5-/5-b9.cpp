/* 2452640 汽车 罗啦 */
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	
	int a[10][10];
	int i = 1,j=1;
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	while (i != 10) {
		while (1) {
			cin >> a[i][j];
			
			if (!cin.good()) {
				cout << "请重新输入第" << i << "行" << j << "列(行列均从1开始计数)的值" << endl;
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				continue;
			}
			else if (a[i][j] <= 0 || a[i][j] > 9) {
				cout << "请重新输入第" << i << "行" << j << "列(行列均从1开始计数)的值" << endl;
				continue;
			}
			else {
				j++;
			}
			if (j == 10)
				break;
		}
		j = 1;
		i++;
	}
	int Flag = 1;
	for (int k = 1; k <= 9; k++) {
		int b[10] = {0};
		int c[10] = { 0 };
		for (int m = 1; m <= 9; m++) {
			int t1 = a[k][m];
			b[t1]++;
			int t2 = a[m][k];
			c[t2]++;
		}
		for (int p = 1; p <= 9; p++) {
			if (b[p] != 1 || c[p] != 1)
				Flag = 0;
		}
		if (!Flag)
			break;
	}
	for (int n = 3; n < 10; n+=3) {
		for (int f = 3; f < 10; f += 3) {
			int d[10] = { 0 };
			for (int k = n - 2; k <= n; k++) {
				for (int m = f - 2; m <= f; m++) {
					int t3 = a[k][m];
					d[t3]++;
				}
			}
			for (int p = 1; p <= 9; p++) {
				if (d[p] != 1)
					Flag = 0;
			}
			if (!Flag)
				break;
		}
		if (!Flag)
			break;
	}
	if (Flag)
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;
	return 0;
}