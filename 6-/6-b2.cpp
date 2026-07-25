/* 2452640 汽车 罗啦 */
#include <iostream>
using namespace std;

bool huiwen(const char* str)
{
    if (str == NULL || *str == '\0') 
        return true; 
    const char* l = str;
    const char* r = str;
    while (*r) r++;
    r--;
    while (l < r) {
        if (*l != *r)
            return false;
        l++;
        r--;
    }
    return true;
}

int main()
{
    char str[81];
    cout << "请输入一个长度小于80的字符串（回文串）" << endl;
    fgets(str, 81, stdin);
    for (char* p = str; *p; p++) {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
    }
    if (huiwen(str)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
    return 0;
}
