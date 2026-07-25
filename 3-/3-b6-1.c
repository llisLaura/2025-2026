/*2452640 Æû³µ ÂÞÀ²*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double a=1;
	int Flag1 = 1,Flag2=1,Flag3=1;
		printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
		scanf("%lf", &a);
		printf("´óÐ´½á¹ûÊÇ:\n");
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
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			}
			printf("Ê°");
			switch (b2)
			{
			case 0:
				break;
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			}
			printf("ÒÚ");
		}
		else if (b2 != 0)
		{
			switch (b2)
			{
			case 0:
				break;
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			}
			printf("ÒÚ");
		}
		else
			Flag1 = 0;//±íÊ¾Ã»ÓÐÒÚÎ»
		if (b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 )
			Flag2 = 0;
		switch (b3)
		{
		case 0:
			if (Flag1&&Flag2)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Çª");
			break;
		case 2:
			printf("·¡Çª");
			break;
		case 3:
			printf("ÈþÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
		}
		switch (b4)
		{
		case 0:
			if (b3 != 0&&(b5!=0||b6!=0))
				printf("Áã");
			break;
		case 1:
			printf("Ò¼°Û");
			break;
		case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èþ°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
		}
		switch (b5)
		{
		case 0:
			if (b4 != 0&&b6 != 0)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈþÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
		}
		switch (b6)
		{
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èþ");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
		}
		if (Flag2)
			printf("Íò");
		if (b7 == 0 && b8 == 0 && b9 == 0 && b10 == 0 )
			Flag3 = 0;
		else
			Flag3 = 1;
		if (Flag1 && !Flag2 && Flag3)
			printf("Áã");
		switch (b7)
		{
		case 0:
			if (Flag2&&Flag3)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Çª");
			break;
		case 2:
			printf("·¡Çª");
			break;
		case 3:
			printf("ÈþÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
		}
		switch (b8)
		{
		case 0:
			if (b7 != 0&&(b9!=0||b10!=0))
				printf("Áã");
			break;
		case 1:
			printf("Ò¼°Û");
			break;
		case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èþ°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
		}
		switch (b9)
		{
		case 0:
			if (b8 != 0&&b10!=0)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈþÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
		}
		switch (b10)
		{
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èþ");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
		}
		if(Flag3||Flag2||Flag1)
			printf("Ô²");
		switch (b11)
		{
		case 0:
			if (b12 != 0 &&(Flag1||Flag2||Flag3))
				printf("Áã");
			break;
		case 1:
			printf("Ò¼½Ç");
			break;
		case 2:
			printf("·¡½Ç");
			break;
		case 3:
			printf("Èþ½Ç");
			break;
		case 4:
			printf("ËÁ½Ç");
			break;
		case 5:
			printf("Îé½Ç");
			break;
		case 6:
			printf("Â½½Ç");
			break;
		case 7:
			printf("Æâ½Ç");
			break;
		case 8:
			printf("°Æ½Ç");
			break;
		case 9:
			printf("¾Á½Ç");
		}
		switch (b12)
		{
		case 0:
			if ((Flag1 || Flag2 || Flag3 || b11))
				printf("Õû");
			else
				printf("ÁãÔ²Õû");
			break;
		case 1:
			printf("Ò¼·Ö");
			break;
		case 2:
			printf("·¡·Ö");
			break;
		case 3:
			printf("Èþ·Ö");
			break;
		case 4:
			printf("ËÁ·Ö");
			break;
		case 5:
			printf("Îé·Ö");
			break;
		case 6:
			printf("Â½·Ö");
			break;
		case 7:
			printf("Æâ·Ö");
			break;
		case 8:
			printf("°Æ·Ö");
			break;
		case 9:
			printf("¾Á·Ö");
		}
		printf("\n");
	return 0;
}