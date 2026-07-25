/* 2452640 Æû³µ ÂÞÀ² */
#include <iostream> 
#include<time.h>
#include<stdlib.h>
using namespace std;
int main()
{
	char a[12][28] = {0};
	int cnt = 0;
	srand(time(0));
	while (1) {
		int x = rand() % 10+1;
		int y = rand() % 26+1;
		if (a[x][y] == '*')
			continue;
		a[x][y] = '*';
		cnt++;
		if (cnt == 50)
			break;
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 26; j++) {
			if (a[i][j] != '*') {
				int sum = 0;
				if (a[i - 1][j-1] == '*')
					sum++;
				if (a[i - 1][j] == '*')
					sum++;
				if (a[i - 1][j+1] == '*')
					sum++;
				if (a[i ][j-1] == '*')
					sum++;
				if (a[i ][j+1] == '*')
					sum++; 
				if (a[i +1][j-1] == '*')
					sum++; 
				if (a[i +1][j] == '*')
					sum++; 
				if (a[i +1][j+1] == '*')
					sum++;
				a[i][j] = sum+'0';
			}
			
		}
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 26; j++) {
				cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}