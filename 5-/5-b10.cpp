/* 2452640 汽车 罗啦 */
#include <iostream>
#include <limits>
#include<iomanip>
using namespace std;
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
int maxday(int year,int month) 
{
	int dd=0;
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
	return dd;
}
void outm(int n,int st) {
for (int i = st*n+1; i <= st*n+n; i++) {
		if (i % n == 1)
			cout << "           " << setiosflags(ios::right)<<setw(2)<< i << "月";
		else
			cout << "                            " << setiosflags(ios::right) << setw(2) << i << "月";
	}
	cout << endl;
	for (int i = st*n+1; i <= st*n+n; i++) {
		if (i % n == 1)
			cout << "Sun Mon Tue Wed Thu Fri Sat" ;
		else
			cout << "     Sun Mon Tue Wed Thu Fri Sat" ;

	}
	cout << endl;
}
void outd(int y,int n, int st,int m[][43]) {
	outm(n, st);
	cout << resetiosflags(ios::right);
	int t = 0;
	int maxd = 0;
	int maxw = 5;
	for (int i = st*n+1; i <= st*n+n; i++) {
		maxd = (zeller(y, i, 1) + maxday(y, i)) > maxd ? (zeller(y, i, 1) + maxday(y, i)) : maxd;
	}
	if (maxd > 35)
		maxw = 6;
	while (t < 7 * maxw) {
		for (int i = st*n+1; i <= st*n+n; i++) {
			for (int j = t + 1; j <= t + 7; j++) {

				if (m[i][j] == 0) {
					cout << "    ";
				}
				else
					cout << setiosflags(ios::left) << setw(4) << m[i][j];
			}
			cout << "    ";
		}
		cout << endl;
		t += 7;
	}
	cout << endl;
}
int main()
{
	cout << "请输入年份[1900-2100]" << endl;
	int y;
	cin >> y;
	cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
	int n;
	cin >> n;
	cout << y << "年的日历:" << endl;
	cout << endl;
	int cnt = 12 / n;
	int m[13][43] = {0};
	for (int i = 1; i <= 12; i++) {
		int t= zeller(y, i, 1);
		int maxd = maxday(y, i);
		for (int j = 1; j <= maxd; j++)
		{
			m[i][++t] = j;
		}
	}
	for (int i = 0; i < cnt;i++) {
		outd(y, n, i, m);
	}
	cout << endl;
	return 0;
}