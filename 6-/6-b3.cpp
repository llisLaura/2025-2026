/* 2452640 汽车 罗啦 */
#include <iostream>
using namespace std;
int main()
{
    char str[33];
    char* p;
    unsigned int a = 0;
    cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
    cin >> str;
    p = str;
    while (*p != '\0') {
        if (*p == '0' || *p == '1') {
            a = a * 2 + (*p - '0');
        }
        p++;
    }
    cout << a << endl;
    return 0;
}
