/* 2452640 汽车 罗啦 */
#include"cmd_console_tools.h"
#include"color_linez.h"
using namespace std;
/* 空文件，给出的目的是为了防止把文件名弄错 */
/***************************************************************************
  函数名称：get_array
  功    能：内部数组生成
  输入参数：Gamein& arrayin,int num,bool is_next,bool gotonext
  返 回 值：void
  说    明：num是生成个数，is_next是是否预告（预告了就不能生成），gotonext是生成预告
***************************************************************************/
void get_array(Gamein& arrayin, int num, bool is_next, bool gotonext) {
	int cnt = 1, color;
	if (is_next) {
		for (int i = 1; i <= num; i++)
		{
			color = rand() % 7 + 1;
			arrayin.nextcolor[i] = color;
		}
	}
	else
	{
		while (cnt <= num) {
			int row = rand() % arrayin.row + 1;
			int col = rand() % arrayin.col + 1;
			if (gotonext)
				color = arrayin.nextcolor[cnt];
			else
				color = rand() % 7 + 1;
			if (arrayin.grid[row][col] != 0)
				continue;
			else {
				cnt++;
				arrayin.grid[row][col] = color;
			}
		}
	}
}
/***************************************************************************
  函数名称：out_array
  功    能：内部数组输出
  输入参数：Gamein结构体 arrayin
  返 回 值：void
  说    明：
***************************************************************************/
void out_array(Gamein& arrayin, bool is_grid, bool is_road) {
	int firstn = 1;
	char firstc = 'A';
	int x, y;
	cout << "  |";
	for (; firstn <= arrayin.col; firstn++)
		cout << setw(3) << firstn;
	cout << endl;
	cout << "--+";
	for (int i = 1; i <= arrayin.col; i++)
		cout << "---";
	cout << endl;
	for (int r = 1; r <= arrayin.row; r++) {
		cct_setcolor();
		cout << firstc << " |";
		for (int c = 1; c <= arrayin.col; c++) {
			cct_setcolor();
			cout << "  ";
			if (is_grid)
			{
				if (arrayin.grid[r][c] != 0) {
					cct_getxy(x, y);
					cct_showch(x, y, arrayin.grid[r][c] + 48, 14, arrayin.grid[r][c], 1);
				}
				else
					cout << arrayin.grid[r][c];
			}
			else if (is_road) {
				cout << arrayin.moveroad[r][c];
			}
			else {
				if (arrayin.moveroad[r][c] == '*') {
					cct_getxy(x, y);
					cct_showch(x, y, arrayin.grid[r][c] + 48, 14, 9, 1);
				}
				else
					cout << arrayin.grid[r][c];
			}
		}
		firstc++;
		cct_setcolor();
		cout << endl;
	}
	cct_setcolor();
	cout << endl;
}
/***************************************************************************
  函数名称：xyin_array
  功    能：输入要移动的球的坐标
  输入参数：Gamein结构体 arrayin,choose,src,dst
  返 回 值：void
  说    明：根据菜单分为两种：此为键盘输入，返回起始点和目标点的坐标
***************************************************************************/
void xyin_key_array(Gamein& arrayin) {
	int i = 0;
	while (i < 2)
	{
		cout << cinxy[i];
		int x, y;
		cct_getxy(x, y);
		cct_gotoxy(x, y);
		while (1) {
			char xy[3];
			cin.getline(xy, sizeof(xy));
			if (xy[0] > 96)
				xy[0] -= 32;
			if ((xy[0] >= 65 && xy[0] < 65 + arrayin.row)
				&& (xy[1] >= 49 && xy[1] < 49 + arrayin.col) &&
				(((arrayin.grid[xy[0] - 64][xy[1] - 48] != 0) && i == 0)
					|| ((arrayin.grid[xy[0] - 64][xy[1] - 48] == 0) && i == 1)))
			{
				arrayin.movexy[i][0] = xy[0] - 64;
				arrayin.movexy[i][1] = xy[1] - 48;
				cout << "输入为" << xy[0] << "行" << xy[1] << "列                  " << endl;
				i++;
				break;
			}
			else if (cin.good() && (((arrayin.grid[xy[0] - 64][xy[1] - 48] == 0) && i == 0)
				|| ((arrayin.grid[xy[0] - 64][xy[1] - 48] != 0) && i == 1))) {
				cout << cinerror[i] << endl;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				}
				cout << cinxy[i];
				cct_getxy(x, y);
			}
			else {
				cout << "输入错误，请重新输入";
				if (cin.fail())
				{
					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				}
				cct_gotoxy(x, y);
				cout << "        ";
				cct_gotoxy(x, y);
			}
		}
	}
}
