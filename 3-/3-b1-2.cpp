/*2452640 汽车 罗啦*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout<< "请输入半径和高度" << endl;
	const double Pi = 3.14159;
	double r, h;
	cin >> r >> h;
	cout << setiosflags(ios::left)<<setiosflags(ios::fixed);
	cout << setw(11) << "圆周长" << ": " << setprecision(2)<<2 * Pi * r<<endl;
	cout << setw(11) << "圆面积" << ": " << setprecision(2) << Pi * r*r<<endl;
	cout << setw(11) << "圆球表面积" << ": " << setprecision(2) << 4 * Pi * r * r<<endl;
	cout << setw(11) << "圆球体积" << ": " << setprecision(2) << 4.0/3.0 * Pi * r*r*r<<endl;
	cout << setw(11) << "圆柱体积" << ": " << setprecision(2) << Pi * r*r*h<<endl;
	return 0;
}