/* 2452640 汽车 罗啦 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) 
        return 0;
    const char* p = str;
    while (*p) {
        p++;
    }
    return p - str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL) 
        return NULL;
    if (s2 == NULL) 
        return s1;
    char* p = s1;
    while (*p) {
        p++;
    }
    const char* q = s2;
    while (*q) {
        *p = *q;
        p++;
        q++;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL) 
        return NULL;
    if (s2 == NULL) 
        return s1;
    char* p = s1;
    while (*p) {
        p++;
    }
    const char* q = s2;
    int count = 0;
    while (*q && count < len) {
        *p = *q;
        p++;
        q++;
        count++;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL) 
        return NULL;
    if (s2 == NULL) {
        *s1 = '\0';
        return s1;
    }
    char* p = s1;
    const char* q = s2;
    while (*q) {
        *p = *q;
        p++;
        q++;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    if (s1 == NULL) 
        return NULL;
    if (s2 == NULL) 
        return s1;
    char* p = s1;
    const char* q = s2;
    int count = 0;
    while (*q && count < len) {
        *p = *q;
        p++;
        q++;
        count++;
    }
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL) 
        return 0;
    if (s1 == NULL) 
        return -1;
    if (s2 == NULL) 
        return 1;
    const char* p1 = s1;
    const char* p2 = s2;
    while (*p1 && *p2 && *p1 == *p2) {
        p1++;
        p2++;
    }
    return *p1 - *p2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL) 
        return 0;
    if (s1 == NULL) 
        return -1;
    if (s2 == NULL) 
        return 1;
    const char* p1 = s1;
    const char* p2 = s2;
    while (*p1 && *p2) {
        char c1 = *p1;
        char c2 = *p2;
        if (c1 >= 'A' && c1 <= 'Z')
            c1 = c1 + ('a' - 'A');
        if (c2 >= 'A' && c2 <= 'Z') 
            c2 = c2 + ('a' - 'A');
        if (c1 != c2) 
            break;
        p1++;
        p2++;
    }
    char c1 = *p1;
    char c2 = *p2;
    if (c1 >= 'A' && c1 <= 'Z') 
        c1 = c1 + ('a' - 'A');
    if (c2 >= 'A' && c2 <= 'Z') 
        c2 = c2 + ('a' - 'A');
    return c1 - c2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL) 
        return 0;
    if (s1 == NULL) 
        return -1;
    if (s2 == NULL) 
        return 1;
    const char* p1 = s1;
    const char* p2 = s2;
    int count = 0;
    while (*p1 && *p2 && count < len && *p1 == *p2) {
        p1++;
        p2++;
        count++;
    }
    if (count == len) 
        return 0;
    return *p1 - *p2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL) 
        return 0;
    if (s1 == NULL) 
        return -1;
    if (s2 == NULL) 
        return 1;
    const char* p1 = s1;
    const char* p2 = s2;
    int count = 0;
    while (*p1 && *p2 && count < len) {
        char c1 = *p1;
        char c2 = *p2;
        if (c1 >= 'A' && c1 <= 'Z') c1 = c1 + ('a' - 'A');
        if (c2 >= 'A' && c2 <= 'Z') c2 = c2 + ('a' - 'A');
        if (c1 != c2) break;
        p1++;
        p2++;
        count++;
    }
    if (count == len) return 0;
    char c1 = *p1;
    char c2 = *p2;
    if (c1 >= 'A' && c1 <= 'Z') c1 = c1 + ('a' - 'A');
    if (c2 >= 'A' && c2 <= 'Z') c2 = c2 + ('a' - 'A');
    return c1 - c2;
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) return NULL;
    char* p = str;
    while (*p) {
        if (*p >= 'a' && *p <= 'z') {
            *p = *p - ('a' - 'A');
        }
        p++;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) 
        return NULL;
    char* p = str;
    while (*p) {
        if (*p >= 'A' && *p <= 'Z') {
            *p = *p + ('a' - 'A');
        }
        p++;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) 
        return 0;
    const char* p = str;
    int ps = 1;
    while (*p) {
        if (*p == ch) {
            return ps;
        }
        p++;
        ps++;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL) 
        return 0;
    if (*substr == '\0') 
        return 0;
    const char* p = str;
    int ps = 1;
    while (*p) {
        const char* p1 = p;
        const char* p2 = substr;
        while (*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }
        if (*p2 == '\0') {
            return ps;
        }
        p++;
        ps++;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) 
        return 0;
    const char* p = str;
    int lastp = 0;
    int ps = 1;
    while (*p) {
        if (*p == ch) {
            lastp = ps;
        }
        p++;
        ps++;
    }
    return lastp;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL) 
        return 0;
    if (*substr == '\0')
        return 0;
    const char* p = str;
    int lastp = 0;
    int ps = 1;
    while (*p) {
        const char* p1 = p;
        const char* p2 = substr;
        while (*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }
        if (*p2 == '\0') {
            lastp = ps;
        }
        p++;
        ps++;
    }
    return lastp;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) 
        return NULL;
    if (*str == '\0') 
        return str;
    char* l = str;
    char* r = str;
    while (*r) {
        r++;
    }
    r--;
    while (l < r) {
        char t = *l;
        *l = *r;
        *r = t;
        l++;
        r--;
    }
    return str;
}
