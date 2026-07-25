/* 2452640 汽车 罗啦 */
#include "5-b7.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <conio.h>   //预置头文件，本程序可用，不算违规，其它程序不可用
#include <windows.h> //预置头文件，本程序可用，不算违规，其它程序不可用
using namespace std;
void move(char src, char dst);
int t;
int Flag;
int cnt = 1;
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 }, atop = 0, btop = 0, ctop = 0;
/***************************************************************************
  函数名称：hanoi
  功    能：输出汉诺塔移动流程
  输入参数：.......
  返 回 值：无
  说    明：......
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        int m;
        cct_gotoxy(20,25);
        if (t >= 0)
            Sleep(t);
        else
            _getch();
        cout << "第" << setw(4) << cnt++ << "步(" << 1 << "#: " << src << "-->" << dst<<")";
        switch (src) {
        case 65:
            m = a[atop - 1];
            a[atop - 1] = 0;
            atop--;
            break;
        case 66:
            m = b[btop - 1];
            b[btop - 1] = 0;
            btop--;
            break;
        case 67:
            m = c[ctop - 1];
            c[ctop - 1] = 0;
            ctop--;
            break;
        }
        switch (dst) {
        case 65:
            a[atop++] = m;
            break;
        case 66:
            b[btop++] = m;
            break;
        case 67:
            c[ctop++] = m;
            break;
        }
        if (Flag) {
            cout<<"  A:";
            for (int i = 0; i < atop; i++) {
               cout<<setw(2)<< a[i];
            }
            for (int i = atop + 1; i <= 10; i++) {
                cout<<"  ";
            }
            cout<<" B:";
            for (int i = 0; i < btop; i++) {
                cout << setw(2) << b[i];
            }
            for (int i = btop + 1; i <= 10; i++) {
                cout<<"  ";
            }
            cout<<" C:";
            for (int i = 0; i < ctop; i++) {
                cout << setw(2) << c[i];
            }
            for (int i = ctop + 1; i <= 10; i++) {
                cout<<"  ";
            }
        }
        move(src, dst);
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        cct_gotoxy(20, 25);
        if (t >= 0)
            Sleep(t);
        else
            _getch();
        cout << "第" << setw(4) << cnt++ << "步(" << n << "#: " << src << "-->" << dst << ")";
        int m;
        switch (src) {
        case 65:
            m = a[atop - 1];
            a[atop - 1] = 0;
            atop--;
            break;
        case 66:
            m = b[btop - 1];
            b[btop - 1] = 0;
            btop--;
            break;
        case 67:
            m = c[ctop - 1];
            c[ctop - 1] = 0;
            ctop--;
            break;
        }
        switch (dst) {
        case 65:
            a[atop++] = m;
            break;
        case 66:
            b[btop++] = m;
            break;
        case 67:
            c[ctop++] = m;
            break;
        }
        if (Flag) {
            cout << "  A:";
            for (int i = 0; i < atop; i++) {
                cout << setw(2) << a[i];
            }
            for (int i = atop + 1; i <= 10; i++) {
                cout << "  ";
            }
            cout << " B:";
            for (int i = 0; i < btop; i++) {
                cout << setw(2) << b[i];
            }
            for (int i = btop + 1; i <= 10; i++) {
                cout << "  ";
            }
            cout << " C:";
            for (int i = 0; i < ctop; i++) {
                cout << setw(2) << c[i];
            }
            for (int i = ctop + 1; i <= 10; i++) {
                cout << "  ";
            }
        }
        move(src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}
/***************************************************************************
  函数名称：move
  功    能：图像移动
  输入参数：.......
  返 回 值：无
  说    明：......
***************************************************************************/
void move(char src,char dst)
{
    if (src == 65) {
        cct_gotoxy(12, 19 - atop);
        cout << "  ";
    }
    if (src == 66) {
        cct_gotoxy(22, 19 - btop);
        cout << "  ";
    }
    if (src == 67) {
        cct_gotoxy(32, 19 - ctop);
        cout << "  ";
    }
    if (dst == 65) {
        cct_gotoxy(12, 20 - atop);
        cout << a[atop-1];
    }
    if (dst == 66) {
        cct_gotoxy(22, 20 - btop);
        cout << b[btop-1];
    }
    if (dst == 67) {
        cct_gotoxy(32, 20 - ctop);
        cout << c[ctop-1];
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
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');

    }
    char src;
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c')) && cin.good())
            break;
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
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
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
    if (dst >= 97)
        dst -= 32;
    char tmp = 198 - dst - src;
    for (int i = n; i > 0; i--) {
        switch (src) {
        case 65:
            a[n - i] = i;
            atop = n;
            break;
        case 66:
            b[n - i] = i;
            btop = n;
            break;
        case 67:
            c[n - i] = i;
            ctop = n;
            break;
        }
    }
    while (1) {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> t;
        if (t>=0&& t <=5 && cin.good())
            break;
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
    while (1) {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> Flag;
        if ((Flag==0||Flag==1) && cin.good())
            break;
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
    cct_cls();
    cout << "从 "<<src<<" 移动到 " <<dst<<"，共 "<<n<< " 层，延时设置为 " <<t;
    if (Flag)
        cout << "，显示内部数组值" << endl;
    else
        cout << "，不显示内部数组值" << endl;
    switch (t) {
        case 0:
            t = -1;
            break;
        case 1: 
            t = 1000; 
            break;
        case 2:
            t = 500;
            break;
        case 3:
            t = 200;
            break;
        case 4:
            t = 50;
            break;
        case 5:
            t = 0;
            break;
    }
    int n1 = n,x,y=19;
    if (src == 65)
        x = 12;
    if (src == 66)
        x = 22;
    if (src == 67)
        x = 32;
    cct_gotoxy(x, y);
    while (n1 > 0) {
        cout << n1--;
        cct_gotoxy(x, --y);
    }
    cct_gotoxy(10, 20);
    cout << "=========================";
    cct_gotoxy(10, 21);
    cout << "  A         B         C";
    hanoi(n, src, tmp, dst);
    cout << endl;
    cct_gotoxy(20, 35);
	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}
