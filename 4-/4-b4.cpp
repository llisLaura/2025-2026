/* 2452640 汽车 罗啦 */
#include <iostream>
#include <cstdio>
#include <conio.h>   //预置头文件，本程序可用，不算违规，其它程序不可用
#include <time.h>    //预置头文件，本程序可用，不算违规，其它程序不可用
#include <windows.h> //预置头文件，本程序可用，不算违规，其它程序不可用
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cct_cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void cct_gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void cct_showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	cct_gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	cct_gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		cct_showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int action(int x, int y, int choose, const HANDLE hout)
{
	while (1) {
		int move;
		move = _getch();
		if (move == 'q' || move == 'Q') {
			return 0;
		}
		if (move == 32) {
			putchar(move);
			cct_gotoxy(hout, x, y);
		}
		else {
			if (choose == 1 || choose == 2) {
				int t1 = x, t2 = y;
				if (move == 75)
					continue;
				if (move == 'I' || move == 'i')
					y--;
				else if (move == 'J' || move == 'j')
					x--;
				else if (move == 'L' || move == 'l')
					x++;
				else if (move == 'K' || move == 'k')
					y++;
				if (choose == 1) {

					if (x != 0 && x != 70 && y != 0 && y != 18)
					{
						cct_gotoxy(hout, x, y);
					}
					else {
						x = t1;
						y = t2;
						continue;
					}
				}
				if (choose == 2) {
					if (x != 0 && x != 70 && y != 0 && y != 18)
					{
						cct_gotoxy(hout, x, y);
					}
					else {
						if (x == 70)
							x = 1;
						if (x == 0)
							x = 69;
						if (y == 0)
							y = 17;
						if (y == 18)
							y = 1;
						cct_gotoxy(hout, x, y);
					}
				}
				
					}
			if (choose == 3 || choose == 4) {
				if (move == 224 || move == 0) {
					move = _getch();
					int t1 = x, t2 = y;
					if (move == 72)
						y--;
					else if (move == 75)
						x--;
					else if (move == 77)
						x++;
					else if (move == 80)
						y++;
					if (choose == 3) {

						if (x != 0 && x != 70 && y != 0 && y != 18)
						{
							cct_gotoxy(hout, x, y);
						}
						else {
							x = t1;
							y = t2;
							continue;
						}
					}
					if (choose == 4) {
						if (x != 0 && x != 70 && y != 0 && y != 18)
						{
							cct_gotoxy(hout, x, y);
						}
						else {
							if (x == 70)
								x = 1;
							if (x == 0)
								x = 69;
							if (y == 0)
								y = 17;
							if (y == 18)
								y = 1;
							cct_gotoxy(hout, x, y);
						}
					}
				}
			}
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	

	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	char ch;
	while (1) {
		cct_cls(hout);
		cout << "1.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界停止)" << endl;
		cout << "2.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界回绕)" << endl;
		cout << "3.用箭头键控制上下左右(按大写HPKM时不允许移动光标，边界停止)" << endl;
		cout << "4.用箭头键控制上下左右(按大写HPKM时不允许移动光标，边界回绕)" << endl;
		cout << "0.退出" << endl;
		cout << "[请选择0-4]";
		ch=_getch();
		if (ch == '0')
			return 0;
		if (ch <= 52 && ch >= 48)
			break;
	}
	
	srand((unsigned int)(time(0)));/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	cct_cls(hout);/* 此句的作用是调用系统的cls命令清屏 */
	init_border(hout);/* 显示初始的边框及其中的随机字符 */
	int x1 = 35, y1 = 9;
	cct_gotoxy(hout, x1, y1);
	int choose = ch - 48;
	action(x1, y1, choose,hout);
	cct_gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键退出." << endl;
	char end;
	while (1) {
		end=_getch();
		if (end == 13)
			break;
	}//暂停(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
	return 0;
}
