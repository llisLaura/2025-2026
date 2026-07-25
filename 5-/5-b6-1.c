/* 2452640 汽车 罗啦 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt = 1;
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 },atop=0,btop=0,ctop=0;
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) 
    {
        int t;
        printf("第%4d 步(%2d): %c-->%c", cnt++, 1, src, dst);
        switch (src) {
        case 65:
            t = a[atop - 1];
            a[atop - 1] = 0;
            atop--;
            break;
        case 66:
            t = b[btop - 1];
            b[btop - 1] = 0;
            btop--;
            break;
        case 67:
            t = c[ctop - 1];
            c[ctop - 1] = 0;
            ctop--;
            break;
        }
        switch (dst) {
        case 65:
            a[atop++] = t;
            break;
        case 66:
            b[btop++] = t;
            break;
        case 67:
            c[ctop++] = t;
            break;
        }
        printf(" A:");
        for (int i = 0; i < atop; i++) {
            printf("%2d", a[i]);
        }
        for (int i = atop + 1; i <= 10; i++) {
            printf("  ");
        }
        printf(" B:");
        for (int i = 0; i < btop; i++) {
            printf("%2d", b[i]);
        }
        for (int i = btop + 1; i <= 10; i++) {
            printf("  ");
        }
        printf(" C:");
        for (int i = 0; i < ctop; i++) {
            printf("%2d", c[i]);
        }
        for (int i = ctop + 1; i <= 10; i++) {
            printf("  ");
        }
        printf("\n");
    }   
    else {
        hanoi(n - 1, src, dst, tmp);
        printf("第%4d 步(%2d): %c-->%c", cnt++, n, src, dst);
        int t;
        switch (src) {
        case 65:
            t = a[atop - 1];
            a[atop - 1] = 0;
            atop--;
            break;
        case 66:
            t = b[btop - 1];
            b[btop - 1] = 0;
            btop--;
            break;
        case 67:
            t = c[ctop - 1];
            c[ctop - 1] = 0;
            ctop--;
            break;
        }
        switch (dst) {
        case 65:
            a[atop++] = t;
            break;
        case 66:
            b[btop++] = t;
            break;
        case 67:
            c[ctop++] = t;
            break;
        }
        printf(" A:");
        for (int i = 0; i < atop; i++) {
            printf("%2d", a[i]);
        }
        for (int i = atop + 1; i <= 10; i++) {
            printf("  ");
        }
        printf(" B:");
        for (int i = 0; i < btop; i++) {
            printf("%2d", b[i]);
        }
        for (int i = btop + 1; i <= 10; i++) {
            printf("  ");
        }
        printf(" C:");
        for (int i = 0; i < ctop; i++) {
            printf("%2d", c[i]);
        }
        for (int i = ctop + 1; i <= 10; i++) {
            printf("  ");
        }
        printf("\n");
        hanoi(n - 1, tmp, src, dst);
    }
}


int main()
{
    int n;
    int ret1, ret2, ret3;
    while (1) {
        printf("请输入汉诺塔的层数(1-10)\n");
        ret1 = scanf("%d", &n);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if (ret1 == 1 && (n >= 1 && n <= 10))
            break;
    }
    char src;
    while (1) {
        printf("请输入起始柱(A-C)\n");
        ret2 = scanf("%c", &src);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if (ret2 == 1 && ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c')))
            break;

    }
    if (src >= 97)
        src -= 32;
    char dst;
    while (1) {
        printf("请输入目标柱(A-C)\n");
        ret3 = scanf("%c", &dst);
        if (ret3 == 1 && ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c')))
            break;
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    if (dst >= 97)
        dst -= 32;
    for (int i = n; i > 0; i--) {
        switch (src) {
        case 65:
            a[n - i] = i;
            atop = n ;
            break;
        case 66:
            b[n - i] = i;
            btop = n;
            break;
        case 67:
            c[n - i] = i;
            ctop = n;
            break;
        }
    }
    printf("初始:                A:");
    for (int i = 0; i <atop; i++) {
        printf("%2d",a[i]);
    }
    for (int i = atop+1; i <= 10; i++) {
        printf("  ");
    }
    printf(" B:");
    for (int i = 0; i < btop; i++) {
        printf("%2d", b[i]);
    }
    for (int i = btop+1; i <= 10; i++) {
        printf("  ");
    }
    printf(" C:");
    for (int i = 0; i < ctop; i++) {
        printf("%2d", c[i]);
    }
    for (int i = ctop+1; i <= 10; i++) {
        printf("  ");
    }
    printf("\n");
    char tmp = 198 - dst - src;
    hanoi(n, src, tmp, dst);
    return 0;
}
