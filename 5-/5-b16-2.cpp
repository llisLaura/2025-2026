/* 2452640 汽车 罗啦 */
#include <iostream>
#include <string.h>
using namespace std;
int main() {
	string num[10], name[10];
	int score[10];
	for (int i = 0; i < 10; i++) {
		cout << "请输入第" << i + 1 <<"个人的学号、姓名、成绩"<<endl;
		cin >> num[i];
		cin >> name[i];
		cin >> score[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (score[j]>score[j+1]) {
				int t = score[j];
				score[j] = score[j + 1];
				score[j + 1] = t;
				string tmp;
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
				tmp = name[j];
				name[j] = name[j + 1];
				name[j + 1] = tmp;
			}
		}
	}
	cout << endl;
	cout << "不及格名单(成绩升序):" << endl;
	for (int i = 0; i < 10; i++) {
		if (score[i] < 60)
			cout<<name[i]<<" "<< num[i] <<" "<< score[i] << endl;
	}
	return 0;
}