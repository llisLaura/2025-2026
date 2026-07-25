/* 2452640 汽车 罗啦 */
#include"cmd_console_tools.h"
#include"color_linez.h"
using namespace std;
/* 加入必要的头文件、命名空间、你觉得应该属于工具类的其它函数 */
/***************************************************************************
  函数名称：
  功    能：显示提示信息
  输入参数：
  返 回 值：
  说    明：如果读不懂，暂时放着，等指针和引用学习完成后再阅读
***************************************************************************/
void to_be_continued(const char* prompt, const int X, const int Y )
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "，按回车键继续...";
	else
		cout << "按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;
	cout << endl;
	//cct_cls();

	return;
}
/***************************************************************************
  函数名称：color_act
  功    能：菜单调度函数
  输入参数：choose，内部数组 arrayin
  返 回 值：void
  说    明：根据选项分配函数
***************************************************************************/
void color_act(int choose, Gamein& arrayin) {
	if (choose == 1||choose==4||choose==5) {
		get_array(arrayin,5);
		cout << endl;
		cout << "初始数组：" << endl;
		out_array(arrayin);
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	}
	if (choose == 2) {
		int k;
		k = arrayin.row * arrayin.col * 3/5;
		get_array(arrayin, k);
		cout << endl;
		cout << "当前数组：" << endl;
		out_array(arrayin);
		get_array(arrayin, 3, 1);
		cout << "下3个彩球的颜色分别是：";
		for (int i = 1; i <= 3; i++) {
			cout << arrayin.nextcolor[i] << " ";
		}
		cout << endl;
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		xyin_key_array(arrayin);
		int if_move=mover(arrayin);
		if (if_move) {
			cout << endl;
			cout << "查找结果数组：" << endl;
			out_array(arrayin, 0, 1);
			cout << endl;
			cout << "查找结果数组：" << endl;
			out_array(arrayin, 0, 0);
		}
		else
			cout << "无法找到移动路径" << endl;
	}
	if (choose == 3) {
		int addscore=0;
		int Flag = 0;
		int n = 0;
		get_array(arrayin, 5);
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		do
		{
		cct_setcolor();
		cout << endl;
		cout << "当前数组：" << endl;
		out_array(arrayin);
		if(!Flag)
		{
			get_array(arrayin, 3, 1);
		}
			cout << "下3个彩球的颜色分别是：";
			for (int i = 1; i <= 3; i++) {
				cout << arrayin.nextcolor[i] << " ";
			}
			n = blank_gameover(arrayin);
			if (n==0) {
				cout << endl;
				cout << "无空位可移动，游戏结束!"<<endl ;
				break;
			}
			cout << endl;
			xyin_key_array(arrayin);
			int if_move = mover(arrayin);
			if (if_move) {
				addscore = arrayin.score;
				Flag = aftermove(arrayin);
				addscore = arrayin.score - addscore;
				cct_setcolor();
				cout << endl;
				cout << "移动后的数组(不同色标识)：" << endl;
				out_array(arrayin);
				cout << "本次得分：" << addscore << " 总得分：" << arrayin.score << endl;
				if (!Flag) {
					get_array(arrayin, n > 3 ? 3 : n, 0, 1);
				}
			}
			else
			{
				cout << "无法找到移动路径" << endl;
				Flag = 1;
			}
		} while (1);
	}
	if (choose == 6)
	{
		get_array(arrayin, arrayin.row*arrayin.col*3/5);
	}
	if(choose==7)
	{
		get_array(arrayin, 5);
		get_array(arrayin, 3, 1);
	}
}


/***************************************************************************
  函数名称：moveroad
  功    能：路径搜寻
  输入参数：Gamein结构体 arrayin
  返 回 值：int
  说    明：有路返回1，没路返回0
***************************************************************************/
int mover(Gamein& arrayin) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			arrayin.moveroad[i][j] = '0';
	int startRow = arrayin.movexy[0][0];
	int startCol = arrayin.movexy[0][1];
	int endRow = arrayin.movexy[1][0];
	int endCol = arrayin.movexy[1][1];
	int visited[10][10] = { 0 };
	int prevRow[10][10];
	int prevCol[10][10];

	for (int i = 1; i <= arrayin.row; i++) {
		for (int j = 1; j <= arrayin.col; j++) {
			prevRow[i][j] = -1;
			prevCol[i][j] = -1;
		}
	}
	int queueRow[100], queueCol[100];
	int front = 0, rear = 0;

	queueRow[rear] = startRow;
	queueCol[rear] = startCol;
	rear++;
	visited[startRow][startCol] = 1;

	int dr[] = { -1, 1, 0, 0 };
	int dc[] = { 0, 0, -1, 1 };
	bool found = false;

	while (front < rear && !found) {
		int curRow = queueRow[front];
		int curCol = queueCol[front];
		front++;

		for (int dir = 0; dir < 4; dir++) {
			int newRow = curRow + dr[dir];
			int newCol = curCol + dc[dir];

			if (newRow < 1 || newRow > arrayin.row ||
				newCol < 1 || newCol > arrayin.col) {
				continue;
			}
			if (visited[newRow][newCol]) {
				continue;
			}
			if (newRow == endRow && newCol == endCol) {
				prevRow[newRow][newCol] = curRow;
				prevCol[newRow][newCol] = curCol;
				found = true;
				break;
			}
			if (arrayin.grid[newRow][newCol] == 0) {
				visited[newRow][newCol] = 1;
				prevRow[newRow][newCol] = curRow;
				prevCol[newRow][newCol] = curCol;
				queueRow[rear] = newRow;
				queueCol[rear] = newCol;
				rear++;
			}
		}
	}

	if (found) {
		arrayin.moveroad[startRow][startCol] = '*';
		arrayin.moveroad[endRow][endCol] = '*';
		int r = endRow, c = endCol;
		while (!(r == startRow && c == startCol)) {
			int nextR = prevRow[r][c];
			int nextC = prevCol[r][c];
			if (!(nextR == startRow && nextC == startCol)) {
				arrayin.moveroad[nextR][nextC] = '*';
			}
			r = nextR;
			c = nextC;
		}
		return 1;
	}
	else {
		return 0;
	}
}
/***************************************************************************
  函数名称：aftermove
  功    能：内部数组移动及消除判断,算分
  输入参数：Gamein结构体 arrayin，score
  返 回 值：int
  说    明：如果可以移动，交换两点坐标并判断是否消除,没有返回0，消除返回1
***************************************************************************/
int aftermove(Gamein& arrayin) {
	int tmp;
	tmp = arrayin.grid[arrayin.movexy[0][0]][arrayin.movexy[0][1]];
	arrayin.grid[arrayin.movexy[0][0]][arrayin.movexy[0][1]] = arrayin.grid[arrayin.movexy[1][0]][arrayin.movexy[1][1]];
	arrayin.grid[arrayin.movexy[1][0]][arrayin.movexy[1][1]] = tmp;
	int totalScore = 0;
	int toEliminate[10][10] = { 0 };
	int scored[10][10] = { 0 }; 

	for (int r = 1; r <= arrayin.row; r++) {
		for (int c = 1; c <= arrayin.col; c++) {
			int color = arrayin.grid[r][c];
			if (color == 0) continue;

			int dr[] = { 0, 1, 1, 1 };
			int dc[] = { 1, 0, 1, -1 };

			for (int dir = 0; dir < 4; dir++) {
				int count = 1;
				for (int step = 1; step <= 5; step++) {
					int nr = r + dr[dir] * step;
					int nc = c + dc[dir] * step;
					if (nr < 1 || nr > arrayin.row || nc < 1 || nc > arrayin.col) break;
					if (arrayin.grid[nr][nc] == color) count++;
					else break;
				}
				for (int step = 1; step <= 5; step++) {
					int nr = r - dr[dir] * step;
					int nc = c - dc[dir] * step;
					if (nr < 1 || nr > arrayin.row || nc < 1 || nc > arrayin.col) break;
					if (arrayin.grid[nr][nc] == color) count++;
					else break;
				}

				if (count >= 5) {
					int prevR = r - dr[dir];
					int prevC = c - dc[dir];
					if (prevR >= 1 && prevR <= arrayin.row &&
						prevC >= 1 && prevC <= arrayin.col &&
						arrayin.grid[prevR][prevC] == color) {
						continue;
					}

					int addScore = (count - 1) * (count - 2);
					totalScore += addScore;
					toEliminate[r][c] = 1;
					for (int step = 1; step <= 5; step++) {
						int nr = r + dr[dir] * step;
						int nc = c + dc[dir] * step;
						if (nr < 1 || nr > arrayin.row || nc < 1 || nc > arrayin.col) break;
						if (arrayin.grid[nr][nc] == color) toEliminate[nr][nc] = 1;
						else break;
					}
					for (int step = 1; step <= 5; step++) {
						int nr = r - dr[dir] * step;
						int nc = c - dc[dir] * step;
						if (nr < 1 || nr > arrayin.row || nc < 1 || nc > arrayin.col) break;
						if (arrayin.grid[nr][nc] == color) toEliminate[nr][nc] = 1;
						else break;
					}
				}
			}
		}
	}

	if (totalScore > 0) {
		int eliminateByColor[8] = { 0 }; 
		for (int r = 1; r <= arrayin.row; r++) {
			for (int c = 1; c <= arrayin.col; c++) {
				if (toEliminate[r][c]) {
					int color = arrayin.grid[r][c];
					int actualColor = color > 7 ? color - 7 : color;
					if (actualColor >= 1 && actualColor <= 7) {
						eliminateByColor[actualColor]++;
					}
				}
			}
		}
		for (int i = 1; i <= 7; i++) {
			arrayin.over[i+1] += eliminateByColor[i];
		}
		for (int r = 1; r <= arrayin.row; r++) {
			for (int c = 1; c <= arrayin.col; c++) {
				if (toEliminate[r][c]) {
					arrayin.grid[r][c] = 0;
				}
			}
		}
		arrayin.score += totalScore;
		return 1;
	}
	return 0;
}
/***************************************************************************
  函数名称：blank_gameover
  功    能：算数组内部还有几个空位
  输入参数：Gamein结构体 arrayin，n
  返 回 值：bool
  说    明：n<=3gameover，返回0
***************************************************************************/
int blank_gameover(Gamein& arrayin) {
	int n = 0; 
	for (int r = 1; r <= arrayin.row; r++) {
		for (int c = 1; c <= arrayin.col; c++) {
			if (arrayin.grid[r][c] == 0) {
				n++;
			}
		}
	}
	return n;
}
/***************************************************************************
  函数名称：count
  功    能：计数
  输入参数：内部数组 arrayin
  返 回 值：void
  说    明：计数
***************************************************************************/
void count(Gamein& arrayin) {
	for (int i = 1; i <= 8; i++) {
		arrayin.count[i] = 0;
	}
	for (int r = 1; r <= arrayin.row; r++) {
		for (int c = 1; c <= arrayin.col; c++) {
			int color = arrayin.grid[r][c];
			if (color == 0) {
				arrayin.count[1]++;
			}
			else if (color >= 8 && color <= 14) {
				arrayin.count[color - 6]++;
			}
		}
	}
}
