/* 2452640 汽车 罗啦 */
#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";
static const char abc[] = "abcdefghijklmnopqrstuvwxyz";
static const char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char num[] = "1234567890";
int main() {
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	int len, num1, num2, num3, num4;
		cin >> len;
		if (!cin.good())
		{
			cout << "输入非法" << endl;
			return 0;
		}
		else if (len < 12 || len>16) {
			cout << "密码长度[" << len << "]不正确" << endl;
			return 0;
		}
		cin >> num1;
		if (!cin.good()) {
			cout << "输入非法" << endl;
			return 0;
		}
		else if (num1<2 || num1>len) {
			cout << "大写字母个数[" << num1 << "]不正确" << endl;
			return 0;
		}
		cin >> num2;
		if (!cin.good())
		{
			cout << "输入非法" << endl;
			return 0;
		}
		else if (num2<2 || num2>len) {
			cout << "小写字母个数[" << num2 << "]不正确" << endl;
			return 0;
		}
		cin >> num3;
		if (!cin.good())
		{
			cout << "输入非法" << endl;
			return 0;
		}
		else if (num3<2 || num3>len) {
			cout << "数字个数[" << num3 << "]不正确" << endl;
			return 0;
		}
		cin >> num4;
		if (!cin.good())
		{
			cout << "输入非法" << endl;
			return 0;
		}
		else if (num4<2 || num4>len) {
			cout << "其它符号个数[" << num4 << "]不正确" << endl;
			return 0;
		}
		if (num1 + num2 + num3 + num4 > len) {
			cout << "所有字符类型之和[" << num1 << "+" << num2 << "+" << num3 << "+" << num4 << "]大于总密码长度[" << len << "]" << endl;
			return 0;
		}
		cout << len << " " << num1 <<" " << num2 <<" "<< num3 <<" " << num4<<endl;
		srand(time(0));
		int j = 0;
			while (j < 10) {
				int len1, len2, len3, len4;
				if (num1 + num2 + num3 + num4 < len)
					len1 = rand() % (len - num1 - num2 - num3 - num4 + 1) + num1;
				else
					len1 = num1;
				if (len1 + num2 + num3 + num4 < len)
					len2 =  rand() % (len - len1 - num2 - num3 - num4 + 1) + num2;
				else
					len2 = num2;
				if (len1 + len2 + num3 + num4 < len)
					len3 = rand() % (len - len1 - len2 - num3 - num4 + 1) + num3;
				else
				{
					len3 = num3;
				}
					len4 = len-len1-len2-len3;
				char temp[128];
				int pos = 0;
				for (int i = 0; i < len1; i++) temp[pos++] = ABC[rand() % 26];
				for (int i = 0; i < len2; i++) temp[pos++] = abc[rand() % 26];
				for (int i = 0; i < len3; i++) temp[pos++] = num[rand() % 10];
				for (int i = 0; i < len4; i++) temp[pos++] = other[rand() % 15];
				for (int i = pos - 1; i > 0; i--) {
					int j = rand() % (i + 1);
					char tmp = temp[i];
					temp[i] = temp[j];
					temp[j] = tmp;
				}
				temp[pos] = '\0';
				cout << temp << endl;
				j++;
			}
	return 0;
}
