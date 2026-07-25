/*2452640 汽车 罗啦*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	const double Pi = 3.14159;
	int a,b,n;
	cin >> a >> b>>n;
	cout <<setiosflags(ios::fixed)<<setprecision(3)<< "三角形面积为 : " << 0.5 * a * b * sin(n / 180.0 * Pi)<<endl;
	return 0;
}