/* 2452640 Æû³µ ÂÞÀ² */
#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

int main()
{
	int a[101] = { 0 };
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (j % i == 0)
				a[j] = a[j] == 1 ? 0 : 1;
		}
	}
	for (int i = 1; i <= 100; i++) {
		if (a[i] == 1 && i != 100)
			cout << i << " ";
		else if (i == 100)
			cout << i;
	}
	cout << endl;
	return 0;
}