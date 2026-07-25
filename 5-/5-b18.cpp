/* 2452640 Æû³µ ÂŞÀ² */
/* 2551313 ÂóÉÜ½ú 2550325 ÎâÓÆ 2450255 èïÓıÓ± 2550904 Íõºèî£ 2554464 ÁõâùÁÕ 2553569 ×ŞË¼Í® */
#include <iostream>
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";
int tj_strlen(const char str[])
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i; 
}
int main() {
	cin.ignore(256, '\n');
	int len, num1, num2, num3, num4;
	char password[10][17];
	cin >> len;
	cin >> num1;
	cin >> num2;
	cin >> num3;
	cin >> num4;
	int j=0;
	int cnt1=0, cnt2=0, cnt3=0, cnt4=0;
	for (int i = 0; i < 10; i++)
		cin >> password[i];
	while (j < 10) {
		cnt1 = 0;
		cnt2 = 0; 
		cnt3 = 0;
		cnt4 = 0;
		if (tj_strlen(password[j]) != len)
		{
			cout << "´íÎó" << endl;
			return 0;
		}
		for (int i = 0; i < len; i++) {
			if (password[j][i] >= 'A' && password[j][i] <= 'Z')
				cnt1++;
			else if (password[j][i] >= 'a' && password[j][i] <= 'z')
				cnt2++;
			else if (password[j][i] >= '0' && password[j][i] <= '9')
				cnt3++;
			else {
				int Flag = 0;
				for (int k = 0; k < 15; k++) {
					if (password[j][i] == other[k])
						Flag = 1;
				}
				if (Flag)
					cnt4++;
				else
				{
					cout << "´íÎó" << endl;
					return 0;
				}
			}
		}
		if (cnt1 < num1 || cnt2 < num2 || cnt3 < num3 || cnt4 < num4)
		{
			cout << "´íÎó" << endl;
			return 0;
		}
		if (cnt1+cnt2+cnt3+cnt4!=len)
		{
			cout << "´íÎó" << endl;
			return 0;
		}
		j++;
	}
	cout << "ÕıÈ·" << endl;
	return 0;
}