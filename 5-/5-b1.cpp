/* 2452640 汽车 罗啦 */
#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

int main()
{
	int a[21];
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	int i = 0;
	for (; i < 20; i++) {
		cin >> a[i];
		if (a[i] <= 0)
			break;
	}
	if (a[0] <= 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	if (i == 20 && a[i - 1] >= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "原数组为：" << endl;
	for (int j = 0; j < i; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	cin >> a[i];
	int t = a[i];
	for (int j = 0; j < i; j++) {
		if (a[j] < a[i] && a[j + 1] >= a[i]) {
			for (int k = i; k > j + 1; k--) {
				a[k] = a[k - 1];
			}
			a[j + 1] = t;
			break;
		}
	}
	cout << "插入后的数组为：" << endl;
	for (int j = 0; j <= i; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
	return 0;
}

