/* 2452640 汽车 罗啦 */
#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

int main()
{
	int a[101] = { 0 }, b[1000], i, cnt = 0;
	cout<<"请输入成绩（最多1000个），负数结束输入"<<endl;
	while (++cnt) {
		cin >> i;
		if (i < 0 || cnt>1000)
			break;
		b[cnt] = i;
		a[i]++;
	}
	if (cnt == 1) {
		cout<<"无有效输入"<<endl;
		return 0;
	}
	cout<<"输入的数组为:"<<endl;
	int j;
	for (j = 1; j < cnt; j++) {
		cout<<b[j]<<" ";
		if (j % 10 == 0)
			cout << endl;
	}
	if ((j - 1) % 10 != 0)
		cout<<endl;
	int sum = 1, t;
	cout<<"分数与名次的对应关系为:"<<endl;
	for (int j = 100; j >= 0; j--) {
		if (a[j] > 0) {
			t = a[j];
			a[j] = sum;
			for(int k=t;k>0;k--)
			cout<<j<<" "<< a[j]<<endl;
			sum += t;
		}		
	}
	return 0;
}