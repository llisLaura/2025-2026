/* 2452640 汽车 罗啦 */
#include <iostream>
#include <iomanip>
#include<limits>
using namespace std;
int cnt = 1;
int topabc[4] = { 0 }, abc[4][11] = { 0 };
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        cout <<"第"<< setw(4) << cnt++ <<" 步("<<setw(2)<<1<< "): " << src << "-->" << dst;
        int t;
        switch (src) {
        case 65:
            t = abc[1][topabc[1]-1];
            abc[1][topabc[1] - 1] = 0;
            topabc[1]--;
            break;
        case 66:
            t = abc[2][topabc[2] - 1];
            abc[2][topabc[2] - 1] = 0;
            topabc[2]--;
            break;
        case 67:
            t = abc[3][topabc[3] - 1];
            abc[3][topabc[3] - 1] = 0;
            topabc[3]--;
            break;
        }
        switch (dst) {
        case 65:
            abc[1][topabc[1]++] = t;
            break;
        case 66:
            abc[2][topabc[2]++] = t;
            break;
        case 67:
            abc[3][topabc[3]++] = t;
            break;
        }
        cout<<" A:";
        for (int i = 0; i < topabc[1]; i++) {
            cout << setw(2) << abc[1][i];
        }
        for (int i = topabc[1] + 1; i <= 10; i++) {
            cout << "  ";
        }
        cout<<" B:";
        for (int i = 0; i < topabc[2]; i++) {
            cout << setw(2) << abc[2][i];
        }
        for (int i = topabc[2] + 1; i <= 10; i++) {
            cout << "  ";
        }
        cout<<" C:";
        for (int i = 0; i < topabc[3]; i++) {
            cout << setw(2) << abc[3][i];
        }
        for (int i = topabc[3] + 1; i <= 10; i++) {
            cout << "  ";
        }
        cout << endl;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        cout << "第" << setw(4) << cnt++ << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
        int t;
        switch (src) {
        case 65:
            t = abc[1][topabc[1] - 1];
            abc[1][topabc[1] - 1] = 0;
            topabc[1]--;
            break;
        case 66:
            t = abc[2][topabc[2] - 1];
            abc[2][topabc[2] - 1] = 0;
            topabc[2]--;
            break;
        case 67:
            t = abc[3][topabc[3] - 1];
            abc[3][topabc[3] - 1] = 0;
            topabc[3]--;
            break;
        }
        switch (dst) {
        case 65:
            abc[1][topabc[1]++] = t;
            break;
        case 66:
            abc[2][topabc[2]++] = t;
            break;
        case 67:
            abc[3][topabc[3]++] = t;
            break;
        }
        cout << " A:";
        for (int i = 0; i < topabc[1]; i++) {
            cout << setw(2) << abc[1][i];
        }
        for (int i = topabc[1] + 1; i <= 10; i++) {
            cout << "  ";
        }
        cout << " B:";
        for (int i = 0; i < topabc[2]; i++) {
            cout << setw(2) << abc[2][i];
        }
        for (int i = topabc[2] + 1; i <= 10; i++) {
            cout << "  ";
        }
        cout << " C:";
        for (int i = 0; i < topabc[3]; i++) {
            cout << setw(2) << abc[3][i];
        }
        for (int i = topabc[3] + 1; i <= 10; i++) {
            cout << "  ";
        }
        cout << endl;
        hanoi(n - 1, tmp, src, dst);
    }
}
int main()
{
    int n;
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (((n >= 1 && n <= 10) && cin.good()))
            break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    char src;
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c')) && cin.good())
            break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (src >= 97)
        src -= 32;
    char dst;
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c')) && cin.good())
            break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (dst >= 97)
        dst -= 32;
    char tmp = 198 - dst - src;
    for (int i = n; i > 0; i--) {
        switch (src) {
        case 65:
            abc[1][n - i] = i;
            topabc[1] = n;
            break;
        case 66:
            abc[2][n - i] = i;
            topabc[2] = n;
            break;
        case 67:
            abc[3][n - i] = i;
            topabc[3] = n;
            break;
        }
    }
    cout<<"初始:                A:";
    for (int i = 0; i < topabc[1]; i++) {
        cout << setw(2) << abc[1][i];
    }
    for (int i = topabc[1] + 1; i <= 10; i++) {
        cout << "  ";
    }
    cout << " B:";
    for (int i = 0; i < topabc[2]; i++) {
        cout << setw(2) << abc[2][i];
    }
    for (int i = topabc[2] + 1; i <= 10; i++) {
        cout << "  ";
    }
    cout << " C:";
    for (int i = 0; i < topabc[3]; i++) {
        cout << setw(2) << abc[3][i];
    }
    for (int i = topabc[3] + 1; i <= 10; i++) {
        cout << "  ";
    }
    cout << endl;
    hanoi(n, src, tmp, dst);
    return 0;
}
