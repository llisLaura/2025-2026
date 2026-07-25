/* 2452640 汽车 罗啦 */
#include"7-b2.h"
#include"cmd_console_tools.h"
#include<string.h>
#include<iostream>
#include<iomanip>
using namespace std;
/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */

/* 例：声明仅本源程序文件需要的结构体，不要放到.h中
       仅为示例，不需要可删除 */

/***************************************************************************
  函数名称：laststring
  功    能：输出字符串并处理截断问题
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void laststring(int x, int y, const char* str,int bg_color, int fg_color, int max_width) {
    if (max_width <= 0) 
        return;
    cct_gotoxy(x, y);
    cct_setcolor(bg_color, fg_color);
    int c_width = 0;
    const char* p = str; 
    while (*p != '\0' && c_width < max_width) {
        bool is_chinese = ((unsigned char)(*p) >= 0xA1 && (unsigned char)(*p) <= 0xFE);
        if (is_chinese) {
            if (c_width + 2 <= max_width) {
                putchar(*p);
                p++;
                putchar(*p);
                p++;
                c_width += 2;
            }
            else {
                while (c_width < max_width) {
                    putchar(' ');
                    c_width++;
                }
                break; 
            }
        }
        else {
            putchar(*p);
            p++;
            c_width += 1;
        }
    }
    while (c_width < max_width) {
        putchar(' ');
        c_width++;
    }
}

/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    /*------参数修正-----*/
    if (original_para == NULL || menu == NULL)
        return 0;
    int start_x = original_para->start_x;
    int start_y = original_para->start_y;
    int width = original_para->width;	
    int high = original_para->high;	
    
    if (width < strlen(original_para->title))
        width = strlen(original_para->title);
    if (width % 2)
        width += 1;
    int h=0;
    
    while (menu[h][0]!=NULL && h < 1000) //这里可能有问题，但好像能跑
        h++;
    if (high > h)
        high = h;
    /*-------参数修正------*/





    /*-------边框和菜单绘制------*/

    int x, y;
    cct_showstr(start_x, start_y, "╔", original_para->bg_color, original_para->fg_color, 1);
    cct_showstr(start_x+2, start_y, "═", original_para->bg_color, original_para->fg_color, width/2);
    cct_getxy(x, y);
    cct_showstr(x, y, "╗", original_para->bg_color, original_para->fg_color, 1);
    //完成上边框!!!!


    int title_w=strlen(original_para->title);
         if (((width - title_w) / 2) % 2 != 0)
            cct_showstr(start_x +1 + ((width - title_w)/2), start_y, original_para->title, original_para->bg_color, original_para->fg_color, 1);
         else
             cct_showstr(start_x + 2 + ((width - title_w) / 2), start_y, original_para->title, original_para->bg_color, original_para->fg_color, 1);
    //标题


    x = start_x;
    y = start_y + 1;
    for (int i = 0; i < high; i++) {
        cct_showstr(x, y, "║", original_para->bg_color, original_para->fg_color, 1);
        laststring(x + 2, y, menu[i], original_para->bg_color, original_para->fg_color, width);
        cct_showstr(start_x + width+2, y, "║", original_para->bg_color, original_para->fg_color, 1);
        y++;
    }
    //中间边框


    cct_showstr(x, y, "╚", original_para->bg_color, original_para->fg_color, 1);
    cct_showstr(x + 2, y, "═", original_para->bg_color, original_para->fg_color, width / 2);
    cct_getxy(x, y);
    cct_showstr(x, y, "╝", original_para->bg_color, original_para->fg_color, 1);
    //下边框。


    /*-----边框和菜单绘制-----*/


    /*-----菜单交互-----*/

    cct_setcursor(CCT_CURSOR_INVISIBLE);
    if(high!=0)
    laststring(start_x + 2,start_y+1 , menu[0], original_para->fg_color, original_para->bg_color, width);
    int MX, MY,MA, keycode1, keycode2;
    int cmenu = 0;
    int offset = 0;
    while (1) {
        int event=cct_read_keyboard_and_mouse(MX,MY,MA,keycode1,keycode2);
        if (event != CCT_KEYBOARD_EVENT) {
            continue;
        }
        if (keycode1 == 0xe0 &&high!=0) {
            if(high==h)
            {
                laststring(start_x + 2, start_y + 1 + cmenu, menu[cmenu], original_para->bg_color, original_para->fg_color, width);
                switch (keycode2) {
                case KB_ARROW_UP:
                    cmenu--;
                    if (cmenu < 0)
                        cmenu = 0;
                    break;
                case KB_ARROW_DOWN:
                    cmenu++;
                    if (cmenu >= high)
                        cmenu = high - 1;
                    break;

                default:
                    break;
                }
                laststring(start_x + 2, start_y + 1 + cmenu, menu[cmenu], original_para->fg_color, original_para->bg_color, width);
            }
            else {
                laststring(start_x + 2, start_y + 1 + (cmenu - offset), menu[cmenu], original_para->bg_color, original_para->fg_color, width);
                int omenu = cmenu;
                switch (keycode2) {
                case KB_ARROW_UP:
                    if (cmenu > 0) 
                        cmenu--;
                    break;
                case KB_ARROW_DOWN:
                    if (cmenu < h - 1)
                        cmenu++;
                    break;
                default:
                    break;
                }
                if (cmenu == omenu) {
                    laststring(start_x + 2, start_y + 1 + (cmenu - offset), menu[cmenu],original_para->fg_color, original_para->bg_color, width);
                    continue;
                }
                if (cmenu < offset) {
                    offset = cmenu;
                    for (int i = 0; i < high; i++) {
                        int id = offset + i;
                        if (id >= h) break;
                        if (id == cmenu) {
                            laststring(start_x + 2, start_y + 1 + i, menu[id], original_para->fg_color, original_para->bg_color, width);
                        }
                        else {
                            laststring(start_x + 2, start_y + 1 + i, menu[id],original_para->bg_color, original_para->fg_color, width);
                        }
                    }
                }
                else if (cmenu >= offset + high) {
                    offset = cmenu - high + 1;
                    for (int i = 0; i < high; i++) {
                        int id = offset + i;
                        if (id >= h) break;
                        if (id == cmenu) {
                            laststring(start_x + 2, start_y + 1 + i, menu[id], original_para->fg_color, original_para->bg_color, width);
                        }
                        else {
                            laststring(start_x + 2, start_y + 1 + i, menu[id],original_para->bg_color, original_para->fg_color, width);
                        }
                    }
                }
                else {
                    laststring(start_x + 2, start_y + 1 + (cmenu - offset), menu[cmenu], original_para->fg_color, original_para->bg_color, width);
                }
            }
        }
        else {
            if (keycode1 == '\r' || keycode1 == '\n') {
                cct_setcursor(CCT_CURSOR_VISIBLE_NORMAL);
                if (high == 0)
                    cmenu = -1;
                break;
            }
        }
    }
    /*---- - 菜单交互---- - */

	return cmenu+1;
}
