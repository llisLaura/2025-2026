/* 2452640 汽车 罗啦 */
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

double a, b, c;
void fun1();
void fun2();
void fun3();
void fun4();

int main()
{
    cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
    cin >> a >> b >> c;
    if (fabs(b) < 1e-6)
        b = 0;
    if (fabs(c) < 1e-6)
        c = 0;

    if (fabs(a) < 1e-6) {
        a = 0;
        fun1();
    }
    else if (b * b - 4 * a * c > 1e-6)
        fun2();
    else if (fabs(b * b - 4 * a * c) < 1e-6)
        fun3();
    else if (b * b - 4 * a * c < -1e-6)
        fun4();
    return 0;
}