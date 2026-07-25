/* 2452640 汽车 罗啦 */
#include <conio.h>
#include<iostream>
#include<limits>
#include<iomanip>
#include <windows.h>
#include"cmd_console_tools.h"
#include"cmd_hdc_tools.h"
#include"hanoi.h"
#include"hanoi_const_value.h"
using namespace std;
static int t,cnt=1;
static int topabc[4] = { 0 }, abc[4][11] = { 0 };
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
void hanoi_act(int choose, int n, char src, char tmp, char dst, int t);
void start_out(int n, char src, int x, int y);
void hanoi_out(int choose,int n, char src, char tmp, char dst);
void move48(int choose,char src, char dst);
void move348(int choose,int n,char src,char dst);
void draw56789();
void draw6789(char src);
void move789(char src, char dst, int tsrc, int srctop, int tdst);
void in9(char finaldst,int n);
int bool9(char src, char dst);
/***************************************************************************
  函数名称：hanoi
  功    能：汉诺塔核心函数
  输入参数：层数，起始柱，中间柱，结束柱
  返 回 值：void
  说    明：12348共用，不超过15行
***************************************************************************/
void hanoi(int choose,int n, char src, char tmp, char dst)
{
    if (n == 1) {
        hanoi_out(choose,1, src, tmp, dst);
        if (choose == 7)
            return;
    }
    else {
        hanoi(choose,n - 1, src, dst, tmp);
        if (choose == 7)
            return;
        hanoi_out(choose, n, src, tmp, dst);
        hanoi(choose,n - 1, tmp, src, dst);
    }
}


/***************************************************************************
  函数名称：hanoi_in
  功    能：汉诺塔输入函数
  输入参数：菜单选项，&层数，&起始柱，&结束柱
  返 回 值：void
  说    明：12345678共用，会改变延时t
***************************************************************************/
void hanoi_in(int choose, int* n, char* src, char* dst) {
    cnt = 1;
    for (int i = 0; i < 4; i++) {
        topabc[i] = 0;
        for (int j = 0; j < 11; j++) {
            abc[i][j] = 0;
        }
    }
    if (choose == 1 || choose == 2 || choose == 3 || choose == 4 || choose == 6 || choose == 7 || choose == 8 || choose == 9) {
        while (1) {
            cout << "请输入汉诺塔的层数(1-10)：" << endl;
            cin >> *n;
            if (((*n >= 1 && *n <= 10) && cin.good()))
                break;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');

        }
        while (1) {
            cout << "请输入起始柱(A-C)：" << endl;
            cin >> *src;
            if (((*src >= 'A' && *src <= 'C') || (*src >= 'a' && *src <= 'c')) && cin.good())
                break;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
        if (*src >= 97)
            *src -= 32;
        while (1) {
            cout << "请输入目标柱(A-C)：" << endl;
            cin >> *dst;
            if (((*dst >= 'A' && *dst <= 'C') || (*dst >= 'a' && *dst <= 'c')) && cin.good())
                break;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
        if (*dst >= 97)
            *dst -= 32;
        for (int i = *n; i > 0; i--) {
            switch (*src) {
            case 65:
                abc[1][*n - i] = i;
                topabc[1] = *n;
                break;
            case 66:
                abc[2][*n - i] = i;
                topabc[2] = *n;
                break;
            case 67:
                abc[3][*n - i] = i;
                topabc[3] = *n;
                break;
            }
        }
        
    }
    char tmp = 198 - *dst - *src;
    if (choose == 4 ) {
        while (1) {
            cout << "请输入移动速度(0-200：0-按回车单步演示 1-200:延时1-200ms) " ;
            cin >> t;
            if (t >= 0 && t <= 200 && cin.good())
                break;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
    }
    if ( choose == 7 || choose == 8 || choose == 9) {
        while (1) {
            cout << "请输入移动速度(0-20：0-按回车单步演示 1-20:延时1-20ms)";
            cin >> t;
            if (t >= 0 && t <= 20 && cin.good())
                break;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
    }
    hanoi_act(choose, *n, *src, tmp, *dst, t);
}

/***************************************************************************
  函数名称：hanoi_act
  功    能：汉诺塔执行函数
  输入参数：菜单选项，层数，起始柱，中间柱，结束柱，延时
  返 回 值：void
  说    明：12345678共用，跟据菜单调用函数；
***************************************************************************/
void hanoi_act(int choose, int n, char src, char tmp, char dst, int t) {
    switch (choose) {
    case 1:
    case 2:
    case 3:
        hanoi(choose, n, src, tmp, dst);
        break;
    case 4: 
    {
        cct_cls();
        cct_gotoxy(Status_Line_X, Status_Line_Y);
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << t << "ms";
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
        int x = MenuItem4_Start_X + Underpan_A_X_OFFSET, y = MenuItem4_Start_Y + Underpan_A_Y_OFFSET;
        start_out(n,src,x, y);
        hanoi(choose, n, src, tmp, dst);
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
        break;
    }
    case 5:
        cct_cls();
        hanoi_out(choose, n, src, tmp, dst);
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
        break;
    case 6:
        cct_cls();
        cct_gotoxy(Status_Line_X, Status_Line_Y);
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
        hanoi_out(choose, n, src, tmp, dst);
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
        break;
    case 7:
        cct_cls();
        cct_gotoxy(Status_Line_X, Status_Line_Y);
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
        hanoi(choose, n, src, tmp, dst);
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
        break;
    case 8:
    {
        cct_cls();
        cct_gotoxy(Status_Line_X, Status_Line_Y);
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << t << "ms（前7步，后面自动变为0ms）";
        cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y);
        int x = MenuItem8_Start_X + Underpan_A_X_OFFSET, y = MenuItem8_Start_Y + Underpan_A_Y_OFFSET;
        start_out(n, src, x, y);
        draw56789();
        draw6789(src);
        hanoi(choose, n, src, tmp, dst);
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
        break;
    }
    case 9:
    {
        cct_cls();
        cct_gotoxy(Status_Line_X, Status_Line_Y);
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
        if (t == 0)
            t = -1;
        cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y);
        int x = MenuItem9_Start_X + Underpan_A_X_OFFSET, y = MenuItem9_Start_Y + Underpan_A_Y_OFFSET;
        start_out(n, src, x, y);
        draw56789();
        draw6789(src);
        in9(dst,n);
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
        break;
    }
    }
   
}

/***************************************************************************
  函数名称：start_out
  功    能：输出初始纵向
  输入参数：层数，起始柱，xy坐标
  返 回 值：void
  说    明：
***************************************************************************/
void start_out(int n,char src,int x, int y) {
    cout << "初始:  A:";
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
    int n1 = n;
    cct_gotoxy(x, y);
    cout << "A";
    cct_gotoxy(x + Underpan_Distance, y);
    cout << "B";
    cct_gotoxy(x + 2 * Underpan_Distance, y);
    cout << "C";
    cct_gotoxy(x - 2, y - 1);
    for (int i = 0; i <= 2 * Underpan_Distance + 4; i++)
        cout << "=";
    y -= 1;
    while (n1 > 0) {
        switch (src) {
        case'A':
            cct_gotoxy(x, --y);
            break;
        case 'B':
            cct_gotoxy(x + Underpan_Distance, --y);
            break;
        case 'C':
            cct_gotoxy(x + 2 * Underpan_Distance, --y);
            break;
        }
        cout << n1--;
    }
}

/***************************************************************************
  函数名称：hanoi_out
  功    能：输出调度函数
  输入参数：
  返 回 值：void
  说    明：
***************************************************************************/
void hanoi_out(int choose,int n, char src, char tmp, char dst) {
    int srcc = src - 'A' + 1;
    int dstt = dst - 'A' + 1;
    int tsrc = topabc[srcc];
    int tdst = topabc[dstt];
    int srctop = abc[srcc][topabc[srcc]-1];
    if (choose == 8 && cnt >= 8)
        t = 0;
    if(choose==1)
    cout << n << "# " << src << "---->" << dst << endl;
    if (choose == 2)
        cout << "第" << setw(4) << cnt++ << " 步(" << setw(2) << n << "#: " << src << "-->" << dst <<")"<< endl; 
    
    if (choose == 3 || choose == 4 ||choose==8)               //横向输出 3/4/8
        move348(choose,n, src, dst);
      if (choose == 4 ||choose==8)                  //纵向输出函数4/8
        move48(choose,src, dst);
    if (choose == 5 ||choose==6||choose==7 )      //画柱子5/6/7/8/9
        draw56789();
    if (choose == 6||choose==7)     //画盘子6/7/8/9
        draw6789(src);
    if (choose == 7 ||choose==8)       //盘子移动函数7/8/9
        move789(src, dst,tsrc,srctop,tdst);
}

/***************************************************************************
  函数名称：move48
  功    能：纵向移动4/8
  输入参数：起始柱，结束柱
  返 回 值：void
  说    明：
***************************************************************************/
void move48(int choose,char src, char dst)
{
    int x, y;
    if(choose==4)
        x = MenuItem4_Start_X + Underpan_A_X_OFFSET, y = MenuItem4_Start_Y + Underpan_A_Y_OFFSET;
    else if(choose==8)
        x = MenuItem8_Start_X + Underpan_A_X_OFFSET, y = MenuItem8_Start_Y + Underpan_A_Y_OFFSET;
    else
        x = MenuItem9_Start_X + Underpan_A_X_OFFSET, y = MenuItem9_Start_Y + Underpan_A_Y_OFFSET;
    if (src == 65) {
        cct_gotoxy(x , y-2 - topabc[1]);
        cout << "  ";
    }
    if (src == 66) {
        cct_gotoxy(x + Underpan_Distance, y-2 - topabc[2]);
        cout << "  ";
    }
    if (src == 67) {
        cct_gotoxy(x + 2*Underpan_Distance, y-2 - topabc[3]);
        cout << "  ";
    }
    if (dst == 65) {
        cct_gotoxy(x , y-1 - topabc[1]);
        cout << abc[1][topabc[1] - 1];
    }
    if (dst == 66) {
        cct_gotoxy(x + Underpan_Distance, y-1 - topabc[2]);
        cout << abc[2][topabc[2] - 1];
    }
    if (dst == 67) {
        cct_gotoxy(x + 2*Underpan_Distance, y-1 - topabc[3]);
        cout << abc[3][topabc[3] - 1];
    }
}

/***************************************************************************
  函数名称：move348
  功    能：横向移动3/4/8
  输入参数：
  返 回 值：void
  说    明：
***************************************************************************/
void move348(int choose,int n,char src,char dst) {
    if (choose == 4) {
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
        if (t > 0)
            Sleep(t);
        else
        {
            while (1) {
                char h = _getch();
                if (h == 13)
                    break;
            }
        }
    } 
    if (choose == 8) {
        cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y);
        if (t > 0 || (t == 0 && cnt >= 8))
            Sleep(t);
        else
        {
            while (1) {
                char h = _getch();
                if (h == 13)
                    break;
            }
        }
    }
    if (choose == 9) {
        cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y);
        if (t > 0)
            Sleep(t);
        else
        {
            while (1) {
                char h = _getch();
                if (h == 13)
                    break;
            }
        }
    }
    cout << "第" << setw(4) << cnt++ << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
    int m;
    switch (src) {
    case 65:
        m = abc[1][topabc[1] - 1];
        abc[1][topabc[1] - 1] = 0;
        topabc[1]--;
        break;
    case 66:
        m = abc[2][topabc[2] - 1];
        abc[2][topabc[2] - 1] = 0;
        topabc[2]--;
        break;
    case 67:
        m = abc[3][topabc[3] - 1];
        abc[3][topabc[3] - 1] = 0;
        topabc[3]--;
        break;
    }
    switch (dst) {
    case 65:
        abc[1][topabc[1]++] = m;
        break;
    case 66:
        abc[2][topabc[2]++] = m;
        break;
    case 67:
        abc[3][topabc[3]++] = m;
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
}

/***************************************************************************
  函数名称：draw56789
  功    能：画柱子
  输入参数：
  返 回 值：void
  说    明：
***************************************************************************/
void draw56789() 
{
    hdc_init(HDC_COLOR[0], 0, 1200, 1200);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X, HDC_Start_Y, bw, HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X+ bw +HDC_Underpan_Distance, HDC_Start_Y, bw, HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X + 2*bw+2*HDC_Underpan_Distance, HDC_Start_Y, bw, HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X+11*HDC_Base_Width, HDC_Start_Y-h, HDC_Base_Width,h, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X + bw + HDC_Underpan_Distance+ 11 * HDC_Base_Width, HDC_Start_Y-h, HDC_Base_Width, h, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X + 2*bw + 2*HDC_Underpan_Distance + 11 * HDC_Base_Width, HDC_Start_Y - h, HDC_Base_Width, h, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
}
/***************************************************************************
  函数名称：draw6789
  功    能：画初始盘子
  输入参数：
  返 回 值：void
  说    明：
***************************************************************************/
void draw6789(char src) {
    int sX = 0, sY;
    int srcc = src - 'A' + 1;
    sY = HDC_Start_Y;
    switch (src) {
    case 'A':
        sX = HDC_Start_X;

        break;
    case 'B':
        sX = HDC_Start_X + bw + HDC_Underpan_Distance;
        break;
    case 'C':
        sX = HDC_Start_X + 2 * bw + 2 * HDC_Underpan_Distance;
        break;
    }
    for (int i=0,j=1 ; i <topabc[srcc]; i++,j++) {
        hdc_rectangle(sX + (bw - (1 + 2 * abc[srcc][i]) * HDC_Base_Width) / 2, sY-j* HDC_Base_High, (1 + 2 * abc[srcc][i]) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[abc[srcc][i]]);
        Sleep(HDC_Init_Delay);
    }
}
/***************************************************************************
  函数名称：move789
  功    能：盘子移动
  输入参数：起始柱，目标柱；
  返 回 值：void
  说    明：
***************************************************************************/

void move789(char src, char dst,int tsrc,int srctop,int tdst) {
    int sX=0,dX=0;
    switch (src) {
    case 'A':
        sX = HDC_Start_X;
        break;
    case 'B':
        sX = HDC_Start_X + bw + HDC_Underpan_Distance;
        break;
    case 'C':
        sX = HDC_Start_X + 2 * bw + 2 * HDC_Underpan_Distance;
        break;
    }
    switch (dst) {
    case 'A':
        dX = HDC_Start_X;
        break;
    case 'B':
        dX = HDC_Start_X + bw + HDC_Underpan_Distance;
        break;
    case 'C':
        dX = HDC_Start_X + 2 * bw + 2 * HDC_Underpan_Distance;
        break;
    }
    int srcc = src - 'A' +1;
    int dstt = dst - 'A' + 1;
    int locationX, locationY;//左上角标记
    int goalX, goalY;
    locationY = HDC_Start_Y - tsrc * HDC_Base_High;
    locationX = sX + (23 - (1 + 2 * srctop)) / 2 * HDC_Base_Width;
    while (locationY >= HDC_Top_Y) {    //向上
        hdc_rectangle(locationX,locationY+ HDC_Base_High- HDC_Step_Y, (1 + 2 * srctop) * HDC_Base_Width, HDC_Step_Y, HDC_COLOR[0]);
        if(locationY>= HDC_Start_Y-h- HDC_Base_High)
        hdc_rectangle(sX+11 * HDC_Base_Width, locationY + HDC_Base_High - HDC_Step_Y,HDC_Base_Width, HDC_Step_Y, HDC_COLOR[11]);
        hdc_rectangle(locationX, locationY - HDC_Step_Y, (1 + 2 * srctop) * HDC_Base_Width, HDC_Step_Y, HDC_COLOR[srctop]);
        locationY -= HDC_Step_Y;
        if (t > 0||(t==0&&cnt>=8))
            Sleep(t);
        else
        {
            while (1) {
                char h = _getch();
                if (h == 13)
                    break;
            }
        }
    }
    goalX= dX + (bw - (1 + 2 * srctop) * HDC_Base_Width) / 2;
    goalY= HDC_Start_Y - (tdst+1) * HDC_Base_High;
    if (goalX > locationX) {        //向右
        while (goalX > locationX) {
            hdc_rectangle(locationX, locationY,HDC_Step_X , HDC_Base_High, HDC_COLOR[0]);
            hdc_rectangle(locationX+ (1 + 2 * srctop) * HDC_Base_Width, locationY, HDC_Step_X, HDC_Base_High, HDC_COLOR[srctop]);
            locationX += HDC_Step_X;
            if (t > 0 || (t == 0 && cnt >= 8))
                Sleep(t);
            else
            {
                while (1) {
                    char h = _getch();
                    if (h == 13)
                        break;
                }
            }
        }
    }
    else {
        while (goalX < locationX) { //向左
            hdc_rectangle(locationX- HDC_Step_X, locationY, HDC_Step_X, HDC_Base_High, HDC_COLOR[srctop]);
            hdc_rectangle(locationX + (1 + 2 * srctop) * HDC_Base_Width- HDC_Step_X, locationY, HDC_Step_X, HDC_Base_High, HDC_COLOR[0]);
            locationX -= HDC_Step_X;
            if (t > 0 || (t == 0 && cnt >= 8))
                Sleep(t);
            else
            {
                while (1) {
                    char h = _getch();
                    if (h == 13)
                        break;
                }
            }
        }
    }
    while (locationY < goalY) {    //向下
        hdc_rectangle(locationX, locationY, (1 + 2 * srctop) * HDC_Base_Width, HDC_Step_Y, HDC_COLOR[0]);
        if (locationY >= HDC_Start_Y - h )
            hdc_rectangle(dX + 11 * HDC_Base_Width, locationY, HDC_Base_Width, HDC_Step_Y, HDC_COLOR[11]);
        hdc_rectangle(locationX, locationY + HDC_Base_High, (1 + 2 * srctop) * HDC_Base_Width, HDC_Step_Y, HDC_COLOR[srctop]);
        locationY += HDC_Step_Y;
        if (t > 0 || (t == 0 && cnt >= 8))
            Sleep(t);
        else
        {
            while (1) {
                char h = _getch();
                if (h == 13)
                    break;
            }
        }
    }

}

/***************************************************************************
  函数名称：in9
  功    能：菜单9输入
  输入参数：
  返 回 值：void
  说    明：
***************************************************************************/

void in9(char finaldst,int n) {
    char src;
    char dst;
    cct_gotoxy(Status_Line_X, Status_Line_Y-1);
    char a[22] = { 0 };
    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
    while (1) {
        for (int j = 0; j < 22; j++)
            a[j] = 0;
        int i = 0;
        for (i = 0; i < 20; i++) {
            char ch = _getche();
            a[i] = ch;
            if (a[i] == '\r')
                break;
        }
        a[i] = '\0';
        if (i == 20) {
            while (_kbhit()) _getch();
            cct_gotoxy(Status_Line_X + 60, Status_Line_Y - 1);
            cout << "                    ";
            cct_gotoxy(Status_Line_X + 60, Status_Line_Y - 1);
            continue;
        }
        if (i == 1 && (a[0] == 'q' || a[0] == 'Q')) {
            cout << endl;
            cout << "游戏中止!!!!!";
            break;
        }
        if (i == 2 && ((a[0] >= 'A' && a[0] <= 'C') || (a[0] >= 'a' && a[0] <= 'c')) && ((a[1] >= 'A' && a[1] <= 'C') || (a[1] >= 'a' && a[1] <= 'c'))) {
            src = a[0];
            dst = a[1];
            if (src >= 97)
                src -= 32;
            if (dst >= 97)
                dst -= 32;
                int srcc = src - 'A' + 1;
                int dstt = dst - 'A' + 1;
                int fdst = finaldst - 'A' + 1;
                int tsrc = topabc[srcc];
                int tdst = topabc[dstt];
                int srctop = abc[srcc][topabc[srcc] - 1];
            if (bool9(src, dst) == 2)
            {
                
                move348(9, abc[srcc][topabc[srcc]-1], src, dst);
                move48(9, src, dst);
                move789(src, dst, tsrc, srctop, tdst);
            }
            else if (bool9(src, dst) == 0) {
                cout << endl;
                cout << "源柱为空！";
                Sleep(1000);
                cct_gotoxy(Status_Line_X, Status_Line_Y);
                cout << "         ";
            }
            else if (bool9(src, dst) == 1) {
                cout << endl;
                cout << "大盘压小盘，非法移动！";
                Sleep(1000);
                cct_gotoxy(Status_Line_X, Status_Line_Y);
                cout << "                      ";
            }
            int Flag = 1;
            for (int j = n, k = 0; j > 0; j--, k++) {
                if (abc[fdst][k] != j)
                {
                    Flag = 0;
                    break;
                }
            }
            if (Flag == 1) {
                cct_gotoxy(Status_Line_X, Status_Line_Y);
                cout << "游戏结束!!!!!";
                break;
            }
               
        }
        while (_kbhit()) _getch();
        cct_gotoxy(Status_Line_X + 60, Status_Line_Y - 1);
        cout << "                    ";
        cct_gotoxy(Status_Line_X + 60, Status_Line_Y - 1);
    }
    
}
/***************************************************************************
  函数名称：bool9
  功    能：菜单9输入判断函数
  输入参数：
  返 回 值：int
  说    明：
***************************************************************************/

int bool9(char src, char dst) {
    int srcc = src - 'A' + 1;
    int dstt = dst - 'A' + 1;
    if (topabc[srcc] == 0)
        return 0;
    if (topabc[dstt] != 0 && abc[srcc][topabc[srcc] - 1] > abc[dstt][topabc[dstt] - 1])
        return 1;
    return 2;
}
