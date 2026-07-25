/* 2452640 Æû³µ ÂÞÀ² */
#include <iostream> 
using namespace std;

int main()
{
	double a = 1;
	int Flag1 = 1, Flag2 = 1, Flag3 = 1;
	cout<<"ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:"<<endl;
	cin>>a;
	cout<<"´óÐ´½á¹ûÊÇ:"<<endl;
	int a1 = (int)(a / 10),
		b1 = (a1 / 100000000) % 10,
		b2 = (a1 / 10000000) % 10,
		b3 = (a1 / 1000000) % 10,
		b4 = (a1 / 100000) % 10,
		b5 = (a1 / 10000) % 10,
		b6 = (a1 / 1000) % 10,
		b7 = (a1 / 100) % 10,
		b8 = (a1 / 10) % 10;
	double a2 = a - (double)b1 * 1000000000 - (double)b2 * 100000000 - (double)b3 * 10000000 - (double)b4 * 1000000,
		a3 = a2 + (double)0.001;
	int a4 = (int)(a3 * 1000),
		b9 = (a4 / 10000) % 10,
		b10 = (a4 / 1000) % 10,
		b11 = (a4 / 100) % 10,
		b12 = (a4 / 10) % 10;
	if (b1 != 0)
	{
		switch (b1)
		{
		case 1:
			cout<<"Ò¼";
			break;
		case 2:
			cout<<"·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Ê°";
		switch (b2)
		{
		case 0:
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "ÒÚ";
	}
	else if (b2 != 0)
	{
		switch (b2)
		{
		case 0:
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "ÒÚ";
	}
	else
		Flag1 = 0;//±íÊ¾Ã»ÓÐÒÚÎ»
	if (b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0)
		Flag2 = 0;
	switch (b3)
	{
	case 0:
		if (Flag1 && Flag2)
			cout << "Áã";
		break;
	case 1:
		cout << "Ò¼Çª";
		break;
	case 2:
		cout << "·¡Çª";
		break;
	case 3:
		cout << "ÈþÇª";
		break;
	case 4:
		cout << "ËÁÇª";
		break;
	case 5:
		cout << "ÎéÇª";
		break;
	case 6:
		cout << "Â½Çª";
		break;
	case 7:
		cout << "ÆâÇª";
		break;
	case 8:
		cout << "°ÆÇª";
		break;
	case 9:
		cout << "¾ÁÇª";
	}
	switch (b4)
	{
	case 0:
		if (b3 != 0 && (b5 != 0 || b6 != 0))
			cout << "Áã";
		break;
	case 1:
		cout << "Ò¼°Û";
		break;
	case 2:
		cout << "·¡°Û";
		break;
	case 3:
		cout << "Èþ°Û";
		break;
	case 4:
		cout << "ËÁ°Û";
		break;
	case 5:
		cout << "Îé°Û";
		break;
	case 6:
		cout << "Â½°Û";
		break;
	case 7:
		cout << "Æâ°Û";
		break;
	case 8:
		cout << "°Æ°Û";
		break;
	case 9:
		cout << "¾Á°Û";
	}
	switch (b5)
	{
	case 0:
		if (b4 != 0 && b6 != 0)
			cout << "Áã";
		break;
	case 1:
		cout << "Ò¼Ê°";
		break;
	case 2:
		cout << "·¡Ê°";
		break;
	case 3:
		cout << "ÈþÊ°";
		break;
	case 4:
		cout << "ËÁÊ°";
		break;
	case 5:
		cout << "ÎéÊ°";
		break;
	case 6:
		cout << "Â½Ê°";
		break;
	case 7:
		cout << "ÆâÊ°";
		break;
	case 8:
		cout << "°ÆÊ°";
		break;
	case 9:
		cout << "¾ÁÊ°";
	}
	switch (b6)
	{
	case 1:
		cout << "Ò¼";
		break;
	case 2:
		cout << "·¡";
		break;
	case 3:
		cout << "Èþ";
		break;
	case 4:
		cout << "ËÁ";
		break;
	case 5:
		cout << "Îé";
		break;
	case 6:
		cout << "Â½";
		break;
	case 7:
		cout << "Æâ";
		break;
	case 8:
		cout << "°Æ";
		break;
	case 9:
		cout << "¾Á";
	}
	if (Flag2)
		cout << "Íò";
	if (b7 == 0 && b8 == 0 && b9 == 0 && b10 == 0)
		Flag3 = 0;
	else
		Flag3 = 1;
	if (Flag1 && !Flag2 && Flag3)
		cout << "Áã";
	switch (b7)
	{
	case 0:
		if (Flag2 && Flag3)
			cout << "Áã";
		break;
	case 1:
		cout << "Ò¼Çª";
		break;
	case 2:
		cout << "·¡Çª";
		break;
	case 3:
		cout << "ÈþÇª";
		break;
	case 4:
		cout << "ËÁÇª";
		break;
	case 5:
		cout << "ÎéÇª";
		break;
	case 6:
		cout << "Â½Çª";
		break;
	case 7:
		cout << "ÆâÇª";
		break;
	case 8:
		cout << "°ÆÇª";
		break;
	case 9:
		cout << "¾ÁÇª";
	}
	switch (b8)
	{
	case 0:
		if (b7 != 0 && (b9 != 0 || b10 != 0))
			cout << "Áã";
		break;
	case 1:
		cout << "Ò¼°Û";
		break;
	case 2:
		cout << "·¡°Û";
		break;
	case 3:
		cout << "Èþ°Û";
		break;
	case 4:
		cout << "ËÁ°Û";
		break;
	case 5:
		cout << "Îé°Û";
		break;
	case 6:
		cout << "Â½°Û";
		break;
	case 7:
		cout << "Æâ°Û";
		break;
	case 8:
		cout << "°Æ°Û";
		break;
	case 9:
		cout << "¾Á°Û";
	}
	switch (b9)
	{
	case 0:
		if (b8 != 0 && b10 != 0)
			cout << "Áã";
		break;
	case 1:
		cout << "Ò¼Ê°";
		break;
	case 2:
		cout << "·¡Ê°";
		break;
	case 3:
		cout << "ÈþÊ°";
		break;
	case 4:
		cout << "ËÁÊ°";
		break;
	case 5:
		printf("ÎéÊ°");
		break;
	case 6:
		cout << "Â½Ê°";
		break;
	case 7:
		cout << "ÆâÊ°";
		break;
	case 8:
		cout << "°ÆÊ°";
		break;
	case 9:
		cout << "¾ÁÊ°";
	}
	switch (b10)
	{
	case 1:
		cout << "Ò¼";
		break;
	case 2:
		cout << "·¡";
		break;
	case 3:
		cout << "Èþ";
		break;
	case 4:
		cout << "ËÁ";
		break;
	case 5:
		cout << "Îé";
		break;
	case 6:
		cout << "Â½";
		break;
	case 7:
		cout << "Æâ";
		break;
	case 8:
		cout << "°Æ";
		break;
	case 9:
		cout << "¾Á";
	}
	if (Flag3 || Flag2 || Flag1)
		cout << "Ô²";
	switch (b11)
	{
	case 0:
		if (b12 != 0 && (Flag1 || Flag2 || Flag3))
			cout << "Áã";
		break;
	case 1:
		cout << "Ò¼½Ç";
		break;
	case 2:
		cout << "·¡½Ç";
		break;
	case 3:
		cout << "Èþ½Ç";
		break;
	case 4:
		cout << "ËÁ½Ç";
		break;
	case 5:
		cout << "Îé½Ç";
		break;
	case 6:
		cout << "Â½½Ç";
		break;
	case 7:
		cout << "Æâ½Ç";
		break;
	case 8:
		cout << "°Æ½Ç";
		break;
	case 9:
		cout << "¾Á½Ç";
	}
	switch (b12)
	{
	case 0:
		if ((Flag1 || Flag2 || Flag3 || b11))
			cout << "Õû";
		else
			cout << "ÁãÔ²Õû";
		break;
	case 1:
		cout << "Ò¼·Ö";
		break;
	case 2:
		cout << "·¡·Ö";
		break;
	case 3:
		cout << "Èþ·Ö";
		break;
	case 4:
		cout << "ËÁ·Ö";
		break;
	case 5:
		cout << "Îé·Ö";
		break;
	case 6:
		cout << "Â½·Ö";
		break;
	case 7:
		cout << "Æâ·Ö";
		break;
	case 8:
		cout << "°Æ·Ö";
		break;
	case 9:
		cout << "¾Á·Ö";
	}
	cout << endl;
	return 0;
}