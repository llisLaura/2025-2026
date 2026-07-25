/* 2452640 汽车 罗啦*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int n1, n2, n3, cnt = 1;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (j == i)
				continue;
			for (int k = 1; k < 10; k++) {
				if (k == i || k == j)
					continue;
				n1 = 100 * i + 10 * j + k;
				for (int a = i + 1; a < 10; a++) {
					if (a == j || a == k)
						continue;
					for (int b = 1; b < 10; b++) {
						if (b == a || b == i || b == j || b == k)
							continue;
						for (int c = 1; c < 10; c++) {
							if (c == b || c == a || c == i || c == j || c == k)
								continue;
							n2 = 100 * a + 10 * b + c;
							n3 = 1953 - n1 - n2;
							if (n3 >= 100 && n3 < 1000) {
								int t1 = n3 / 100, t2 = n3 / 10 % 10, t3 = n3 % 10;
								if (t1 > a && t1 != t2 && t1 != t3 && t2 != i && t2 != j && t2 != k && t2 != a && t2 != b && t2 != c && t2 != t3 && t3 != i && t3 != j && t3 != k && t3 != a && t3 != b && t3 != c && t2 != 0 && t3 != 0)
								{
									cout << "No." << setiosflags(ios::right) << setw(3) << cnt << " : " << n1 << "+" << n2 << "+" << n3 << "=1953" << endl;
									cnt++;
								}
							}


						}
					}
				}
			}
		}
	}
	cout << "total="<< cnt-1 << endl;
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}
