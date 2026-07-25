/* 2452640 汽车 罗啦 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "read_stulist.h"
using namespace std;


#define MAX_FILENAME_LEN		512	//定义文件名的最大长度

/* stu_metge 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_merge {
private:
	int  stu_no;					//学号
	char stu_name[MAX_NAME_LEN];  //姓名

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	int in_round1;   
	int in_round2;
public:
	//本类不允许定义任何的公有数据成员及成员函数
	friend class stu_list;
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//第一轮选课的学生名单（不排序、不去重）
	int list_num_1;						//第一轮选课的学生人数

	student list_round_2[MAX_STU_NUM];	//第二轮选课的学生名单（不排序、不去重）
	int list_num_2;						//第二轮选课的学生人数

	stu_merge list_merge[MAX_STU_NUM];	//合并后的学生名单（去重，按升序排列）
	int list_merge_num;					//合并后的学生人数（目前不打印，但可用于内部管理，如果不需要，也不要删除）

	/* 允许按需加入private数据成员和成员函数
	   注意，不允许加入array / set / map / vector等STL容器 */
	static int compareByNo(const void* a, const void* b) {
		const student* s1 = (const student*)a;
		const student* s2 = (const student*)b;
		return s1->no - s2->no;
	}
	int uniqueSortedStudents(student* src, int srcCount, student* dst) {
		if (srcCount == 0) return 0;

		int dstCount = 1;
		dst[0] = src[0];

		for (int i = 1; i < srcCount; i++) {
			if (src[i].no != dst[dstCount - 1].no) {
				dst[dstCount++] = src[i];
			}
		}
		return dstCount;
	}
	int findStudentByNo(const student* list, int count, int no) {
		for (int i = 0; i < count; i++) {
			if (list[i].no == no) {
				return i;
			}
		}
		return -1;
	}
	void mergeAndSort();
	int getMaxNameLen();
public:
	stu_list();										//构造函数，按需完成初始化功能，如果不需要，保留空函数即可
	int read(const char* filename, const int round);	//从文件中读入选课信息，round为1/2，表示选课轮次
	int print(const char* prompt = NULL);				//打印最终的选课名单

	/* 允许按需加入其它public成员函数（提示：合并、去重、排序等）
	   不允许定义公有的数据成员
	   不允许在成员函数中使用array / set / map / vector等STL容器 */

};

/* --- 下面可以给出stu_merge/stu_list两个类的成员函数的体外实现 --- */


/***************************************************************************
  函数名称：
  功    能：从文件中读入选课信息，round为1/2，表示选课轮次
  输入参数：
  返 回 值：
  说    明：构造函数，按需完成初始化功能，如果不需要，保留空函数即可
***************************************************************************/
stu_list::stu_list()
{
	list_num_1 = 0;
	list_num_2 = 0;
	list_merge_num = 0;
}

/***************************************************************************
  函数名称：
  功    能：演示静态链接库的使用，本函数中调用静态链接库中的预置函数
  输入参数：
  返 回 值：
  说    明：本函数不需要修改 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* 读取第1/2轮的选课名单并打印 */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("第一轮选课名单：", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("第二轮选课名单：", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：打印最终的选课名单
***************************************************************************/
int stu_list::print(const char* prompt)
{
	mergeAndSort();

	int nameWidth = getMaxNameLen();
	if (nameWidth < 6) nameWidth = 6;

	if (prompt != NULL) {
		cout << prompt << endl;
	}

	cout << "=================================================" << endl;
	cout << " 序号  学号     姓名              第一轮  第二轮" << endl;
	cout << "=================================================" << endl;

	int serialNo = 1;
	for (int i = 0; i < list_merge_num; i++) {
		if (serialNo < 10) {
			cout << " " << serialNo << "     ";
		}
		else if (serialNo < 100) {
			cout << " " << serialNo << "    ";
		}
		else {
			cout << " " << serialNo << "   ";
		}
		cout << list_merge[i].stu_no << "  ";

		cout << list_merge[i].stu_name;
		size_t nameLen = strlen(list_merge[i].stu_name); 
		for (size_t j = nameLen; j < (size_t)nameWidth; j++) { 
			cout << " ";
		}
		cout << "  ";
		if (list_merge[i].in_round1) {
			cout << "Y";
		}
		else {
			cout << "/";
		}
		cout << "       ";
		if (list_merge[i].in_round2) {
			if (list_merge[i].in_round1) {
				cout << "Y";
			}
			else {
				cout << "补选";
			}
		}
		else {
			if (list_merge[i].in_round1) {
				cout << "退课";
			}
			else {
				cout << "/";
			}
		}

		cout << endl;
		serialNo++;
	}

	cout << "=================================================" << endl;

	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void stu_list::mergeAndSort()
{
	student temp[MAX_STU_NUM];
	int tempCount = 0;

	for (int i = 0; i < list_num_1; i++) {
		temp[tempCount++] = list_round_1[i];
	}

	for (int i = 0; i < list_num_2; i++) {
		temp[tempCount++] = list_round_2[i];
	}
	qsort(temp, tempCount, sizeof(student), compareByNo);
	student unique[MAX_STU_NUM];
	int uniqueCount = uniqueSortedStudents(temp, tempCount, unique);
	list_merge_num = uniqueCount;
	for (int i = 0; i < uniqueCount; i++) {
		list_merge[i].stu_no = unique[i].no;
		strcpy_s(list_merge[i].stu_name, unique[i].name);
		list_merge[i].in_round1 = 0;
		list_merge[i].in_round2 = 0;
	}
	for (int i = 0; i < list_num_1; i++) {
		int idx = findStudentByNo(unique, uniqueCount, list_round_1[i].no);
		if (idx >= 0) {
			list_merge[idx].in_round1 = 1;
		}
	}
	for (int i = 0; i < list_num_2; i++) {
		int idx = findStudentByNo(unique, uniqueCount, list_round_2[i].no);
		if (idx >= 0) {
			list_merge[idx].in_round2 = 1;
		}
	}
}

int stu_list::getMaxNameLen()
{
	int maxLen = 0;
	for (int i = 0; i < list_merge_num; i++) {
		int len = (int)strlen(list_merge[i].stu_name);
		if (len > maxLen) maxLen = len;
	}
	return maxLen;
}

int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1); //cin不能读有空格的文件

	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2);

	stu_list list;

	/* 读入数据 */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* 处理数据 */


	/* 打印 */
	list.print("最终选课名单");

	return 0;
}

