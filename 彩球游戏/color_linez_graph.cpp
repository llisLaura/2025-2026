/* 2452640 汽车 罗啦 */
#include"cmd_console_tools.h"
#include"color_linez.h"
using namespace std;
/* 空文件，给出的目的是为了防止把文件名弄错 */

/***************************************************************************
  函数名称：graph_act
  功    能：菜单调度函数
  输入参数：choose，内部数组 arrayin
  返 回 值：void
  说    明：根据选项分配函数
***************************************************************************/
void graph_act(int choose, Gamein& arrayin) {
	for (int i = 1; i <= arrayin.row; i++) {
			for (int j = 1; j <= arrayin.col; j++) {
				if (arrayin.grid[i][j])
					arrayin.grid[i][j] += 7;
			}
	}
	if (choose == 4||choose==5)
	{
		cct_cls();
		for (int i = 1; i <= 3; i++)
	{
		if (arrayin.nextcolor[i])
			arrayin.nextcolor[i] += 7;
	}
		draw_first(arrayin,choose-4);
	}
	if (choose == 6) {
		cct_cls();
		cout << "鼠标移动，左键单击选择，右键退出";
		draw_first(arrayin, 1);
		xyin_mouse_array(arrayin);
		cct_setcursor(2);
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	}
	if (choose == 7) {
		bool Flag = 0;
		cct_cls();
		cout << "鼠标移动，左键单击选择，右键退出";
		for (int i = 1; i <= 3; i++)
		{
			if (arrayin.nextcolor[i])
				arrayin.nextcolor[i] += 7;
		}
		while(1)
		{
			draw_first(arrayin, 1);
			draw_menu(arrayin);
			int n = blank_gameover(arrayin);
			if (n == 0) {
				cout << endl;
				cct_gotoxy(0, 21);
				cout << "游戏结束" << endl;
				Flag = 1;
				break;
			}
			if (!xyin_mouse_array(arrayin))
				break;
			if (aftermove(arrayin))
			{
				continue;
			}
			else {
				get_array(arrayin, n > 3 ? 3 : n, 0, 1);
				get_array(arrayin, 3, 1);
				for (int i = 1; i <= 3; i++)
				{
					if (arrayin.nextcolor[i])
						arrayin.nextcolor[i] += 7;
				}
			}
		}
		cct_setcursor(2);
		if(Flag)
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		}
	}

}
/***************************************************************************
  函数名称：drawfirst
  功    能：绘制初始边框
  输入参数：内部数组 arrayin，框线选项
  返 回 值：void
  说    明：0无框线，1有框线
***************************************************************************/
void draw_first(Gamein& arrayin, bool midline,int start_x,int start_y) {
	int x, y;
	cct_showstr(start_x, start_y, "╔", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(start_x+2, start_y, "═", COLOR_HWHITE, COLOR_BLACK,arrayin.col+ (arrayin.col - 1) * midline);
	if (midline) {
		for (int j = 1; j <= arrayin.col; j++)
		{
			cct_showstr(start_x + 2 + 2 * (j - 1) + 2 * (j - 1) * midline + 2, start_y, "╦", COLOR_HWHITE, COLOR_BLACK, 1);
		}
	}
	cct_showstr(start_x + arrayin.col * 2 + 2 + (arrayin.col - 1) * 2 * midline, start_y, "╗", COLOR_HWHITE, COLOR_BLACK, 1);
	x = start_x;
	y = start_y + 1;
	for (int i = 1; i <= arrayin.row; i++) {
		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK, 1);
		for(int j=1;j<=arrayin.col;j++)
		{
			if (arrayin.grid[i][j] != 0) {
				cct_showstr(start_x + 2+2*(j-1)+2*(j-1)*midline, y, "〇", arrayin.grid[i][j], COLOR_HWHITE, 1);
			}
			else {
				cct_showstr(start_x + 2 + 2 * (j - 1) + 2 * (j - 1) * midline,y, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			if (midline)
				cct_showstr(start_x + 2 + 2 * (j - 1) + 2 * (j - 1) * midline + 2, y, "║", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		cct_showstr(start_x + arrayin.col * 2 + 2+( arrayin.col-1) * 2*midline, y, "║", COLOR_HWHITE, COLOR_BLACK, 1);
		y++;
		if (midline&& i< arrayin.row)
		{
			for (int j = 1; j <= arrayin.col; j++)
			{
					cct_showstr(x, y, "╠", COLOR_HWHITE, COLOR_BLACK, 1);
					cct_showstr(start_x + 2 + 2 * (j - 1) + 2 * (j - 1) * midline, y, "═", COLOR_HWHITE, COLOR_BLACK, 1);
					cct_showstr(start_x + 2 + 2 * (j - 1) + 2 * (j - 1) * midline + 2, y, "╬", COLOR_HWHITE, COLOR_BLACK, 1);
					cct_showstr(start_x + arrayin.col * 2 + 2 + (arrayin.col - 1) * 2 * midline, y, "╣", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			y += midline;
		}
	}
	cct_showstr(x, y, "╚", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(x + 2, y, "═", COLOR_HWHITE, COLOR_BLACK, arrayin.col + (arrayin.col - 1) * midline);
	if (midline) {
		for (int j = 1; j <= arrayin.col; j++)
		{
			cct_showstr(x + 2 + 2 * (j - 1) + 2 * (j - 1) * midline + 2, y, "╩", COLOR_HWHITE, COLOR_BLACK, 1);
		}
	}
	cct_showstr(x + arrayin.col * 2 + 2 + (arrayin.col - 1) * 2 * midline, y, "╝", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_setcolor();
	cout << endl;
}
/***************************************************************************
  函数名称：xyin_mouse_array
  功    能：读取鼠标
  输入参数：内部数组 arrayin
  返 回 值：void
  说    明：
***************************************************************************/
int xyin_mouse_array(Gamein& arrayin) {
	cct_enable_mouse();
	cct_setcursor(CCT_CURSOR_INVISIBLE);
	int MX, MY, MAction, keycode1, keycode2;
	int mx, my;
	int x = 0;
	int y = 2 + arrayin.row * 2;
	int score = 0;
	int selectedRow = 0, selectedCol = 0;
	bool selected = false;
	while (1) {
		bool Flag = false;
		int event = cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		if (event == CCT_MOUSE_EVENT) {
			int col = (MX - 2) / 2;
			int row = MY - 1;
			if (col % 2 == 0 && col / 2 < arrayin.col && row % 2 != 0 && row / 2 < arrayin.row)
			{
				char a = row / 2 + 'A';
				cct_gotoxy(x, y);
				cout << "[当前光标] " << a << "行" << col / 2 + 1 << "列            ";
				Flag = true;
			}
			else
			{
				cct_gotoxy(x, y);
				cout << "[当前光标] 位置非法                   ";
				Flag = false;
			}
			if (Flag)
			{
				switch (MAction) {
				case MOUSE_LEFT_BUTTON_CLICK:
					if (arrayin.grid[row / 2 + 1][col / 2 + 1] != 0) {
						if(selected)
						cct_showstr(mx, my, "〇", arrayin.grid[arrayin.movexy[0][0]][arrayin.movexy[0][1]], COLOR_HWHITE, 1);
						selected = true;
						cct_showstr(MX/2*2, MY, "◎", arrayin.grid[row / 2 + 1][col / 2 + 1], COLOR_HWHITE, 1);
						cct_setcolor();
						arrayin.movexy[0][0] = row / 2 + 1;
						arrayin.movexy[0][1] = col / 2 + 1;
						mx = MX / 2 * 2;
						my = MY;
					}
					else {
						if (selected) {
							arrayin.movexy[1][0] = row / 2 + 1;
							arrayin.movexy[1][1] = col / 2 + 1;
							if (mover(arrayin))
							{
								cct_gotoxy(x, y);
								cout << "[提示] 可以从["<<char(arrayin.movexy[0][0]+64) << arrayin.movexy[0][1] << "]移动到[" << char(arrayin.movexy[1][0]+64) << arrayin.movexy[1][1]<<"]       ";
								draw_move(arrayin,mx,my);
								cct_gotoxy(x, y);
								return 1;
							}
							else {
								cct_gotoxy(x, y);
								cout << "[错误] 无法从[" << char(arrayin.movexy[0][0] + 64) << arrayin.movexy[0][1] << "]移动到[" << char(arrayin.movexy[1][0]+ 64)  << arrayin.movexy[1][1] << "]       ";
							}

						}
					}
					break;
				case MOUSE_RIGHT_BUTTON_CLICK:
					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
					cct_disable_mouse();
					cct_gotoxy(x, y);
					return 0;
				case MOUSE_ONLY_MOVED:
					break;
				}

			}
		}
	}
}
/***************************************************************************
  函数名称：draw_move
  功    能：实现彩球移动
  输入参数：内部数组 arrayin
  返 回 值：void
  说    明：
***************************************************************************/
void draw_move(Gamein& arrayin,int mx,int my){
	int srcx = arrayin.movexy[0][0];
	int srcy = arrayin.movexy[0][1];
	int dstx = arrayin.movexy[1][0];
	int dsty = arrayin.movexy[1][1];
	int way=0;
	int set[] = { 1,-1 };
	arrayin.moveroad[srcx][srcy] = '0';
	while(1)
	{
		int i = 0;
		for (; i < 2; i++) {
			if (arrayin.moveroad[srcx + set[i]][srcy] == '*')
			{
				arrayin.moveroad[srcx + set[i]][srcy] = '0';
				way = 1;
				srcx += set[i];
				break;
			}
			if (arrayin.moveroad[srcx][srcy + set[i]] == '*')
			{
				arrayin.moveroad[srcx][srcy + set[i]] = '0';
				way = 3;
				srcy += set[i];
				break;
			}
		}
		way += i;
		if (way == 1) {//下
			for (int j = 1; j <= 2; j++)
			{
				if (j % 2)
					cct_showstr(mx, my, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(mx, my, "═", COLOR_HWHITE, COLOR_BLACK, 1);
				cct_showstr(mx, my + 1, "◎", arrayin.grid[arrayin.movexy[0][0]][arrayin.movexy[0][1]], COLOR_HWHITE, 1);
				cct_setcolor();
				my += 1;
				Sleep(100);
			}
		}
		if (way == 2) {//上
			for (int j = 1; j <= 2; j++)
			{
				if (j % 2)
					cct_showstr(mx, my, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(mx, my, "═", COLOR_HWHITE, COLOR_BLACK, 1);
				cct_showstr(mx , my-1, "◎", arrayin.grid[arrayin.movexy[0][0]][arrayin.movexy[0][1]], COLOR_HWHITE, 1);
				cct_setcolor();
				my -= 1;
				Sleep(100);
			}
		}
		if (way == 3) {//右
			for(int j=1;j<=4;j++)
			{
				if(j%3)
				cct_showstr(mx, my, " ",  COLOR_HWHITE,COLOR_BLACK, 1);
				else
				cct_showstr(mx, my, "║",  COLOR_HWHITE,COLOR_BLACK, 1);
				cct_showstr(mx + 1, my, "◎", arrayin.grid[arrayin.movexy[0][0]][arrayin.movexy[0][1]],COLOR_HWHITE,  1);
				cct_setcolor();
				mx += 1;
				Sleep(100);
			}
		}
		if (way == 4) {//左
			for (int j = 1; j <= 4; j++)
			{
				if (j % 4)
					cct_showstr(mx+1, my, " ", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(mx+1, my, "║", COLOR_HWHITE, COLOR_BLACK, 1);
				cct_showstr(mx - 1, my, "◎", arrayin.grid[arrayin.movexy[0][0]][arrayin.movexy[0][1]], COLOR_HWHITE, 1);
				cct_setcolor();
				mx -= 1;
				Sleep(100);
			}
		}
		if (srcx == dstx && srcy == dsty)
			break;
	}
}
/***************************************************************************
  函数名称：draw_menu
  功    能：g功能菜单绘制及更新
  输入参数：内部数组 arrayin
  返 回 值：void
  说    明：
***************************************************************************/
void draw_menu(Gamein& arrayin) {
	count(arrayin);
	int x=40, y=1;
	Gamein getscore;
	getscore.col = 5;
	getscore.row = 1;
	draw_first(getscore, 0, 40, 1);
	cct_showstr(x + 1, y + 1, " 得分：    ", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showint(x + 8, y + 1, arrayin.score, COLOR_HWHITE, COLOR_BLACK, 1);
	Gamein next;
	next.col = 3;
	next.row = 1;
	for (int i = 1; i < 4; i++) {
		next.grid[1][i] = arrayin.nextcolor[i];
	}
	draw_first(next,1,40,5);
	Gamein blank;
	blank.col = 12;
	blank.row = 8;
	blank.grid[1][1] = 15;
	for (int i = 8; i <= 14; i++) {
		blank.grid[i - 6][1] = i;
	}
	draw_first(blank, 0, 40, 9);
	for (int i = 1; i <= 8; i++) {
		cct_showstr(x + 4, y + 8+i, ":", COLOR_HWHITE, COLOR_BLACK, 1);
		cout << setfill('0') << setw(2) << arrayin.count[i];
		
		cout<< "/(" <<setfill(' ') << setw(5) << fixed << setprecision(2) << arrayin.count[i] * 1.0 / (arrayin.col * arrayin.row)*100 << "%) 消除-" << arrayin.over[i];
	}
	cct_setcolor();
	cct_gotoxy(0, 22);
}
