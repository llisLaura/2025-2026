/* 2452640 汽车 罗啦 */
#include"cmd_console_tools.h"
#include"color_linez.h"
using namespace std;
int menu() {
	cout << "--------------------------------------------" << endl;
	cout << "A.内部数组，随机生成初始5个球" << endl;
	cout << "B.内部数组，随机生成60%的球，寻找移动路径" << endl;
	cout << "C.内部数组，完整版" << endl;
	cout << "D.画出n*n的框架（无分隔线），随机显示5个球" << endl;
	cout << "E.画出n*n的框架（有分隔线），随机显示5个球" << endl;
	cout << "F.n*n的框架，60%的球，支持鼠标，完成一次移动" << endl;
	cout << "G.cmd图形界面完整版" << endl;
	cout << "Q.退出" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "[请选择:] ";
	while (1) {
		char choose = _getch();
		if (choose == 'Q'||choose=='q')
		{
			cout << choose << endl;
			cct_cls();
			return 0;
		}
		if ((choose >= 'A' && choose <= 'G') || (choose >= 'a' && choose <= 'g')) {
			cout << choose << endl;
			choose >= 97 ? choose -= 32 : choose;
			return int(choose - 64);
		}
	}
}

/***************************************************************************
  函数名称：rc_in
  功    能：行列输入
  输入参数：choose
  返 回 值：void
  说    明：根据菜单选项处理后续输入，交接给color_act调度
***************************************************************************/
void rc_in(int choose) {
	Gamein arrayin;
	cct_cls();
	if (choose == 1||choose==2||choose==3||choose==4||choose==5||choose==6||choose==7) {
		while (1) {
			cout << "请输入行数(7-9)：" << endl;
			cin >> arrayin.row;
			if (((arrayin.row >= 7 && arrayin.row <= 9) && cin.good()))
				break;
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		}
		while (1) {
			cout << "请输入列数(7-9)：" << endl;
			cin >> arrayin.col;
			if (((arrayin.col >= 7 && arrayin.col <= 9) && cin.good()))
				break;
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		}
	}
	color_act(choose, arrayin);
	if (choose == 2) {
		int x, y;
		cct_getxy(x, y);
		to_be_continued(NULL,0,y+1);
	}
	else if(choose!=6&&choose!=7)
		to_be_continued(NULL);
	graph_act(choose, arrayin);
}
/* 空文件，给出的目的是为了防止把文件名弄错 */
