/* 2452640 汽车 罗啦 */
#pragma once
#include<iostream>
#include <conio.h>
#include<Windows.h>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#include<limits>
struct Gamein {
    int grid[20][20] = { 0 };
    int nextcolor[4] = { 0 };
    int movexy[2][2] = { 0 };
    char moveroad[10][10] = { 0 };
    int count[9] = {0};
    int over[9] = { 0 };
    int row;    
    int col; 
    int score=0;
};
const char cinxy[2][100] = { "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：","请以字母+数字形式[例：c2]输入要移动球的目的坐标：" };
const char cinerror[2][100] = { "起始位置为空，请重新输入.","目标位置非空，请重新输入." };
void to_be_continued(const char* prompt, const int X = 0, const int Y = 22);
int menu();
void rc_in(int choose);
void graph_act(int choose, Gamein& arrayin);
void draw_first(Gamein& arrayin, bool midline = 0, int start_x = 0, int start_y = 1);
int xyin_mouse_array(Gamein& arrayin);
void draw_move(Gamein& arrayin, int mx, int my);
void draw_menu(Gamein& arrayin);
void count(Gamein& arrayin);
void get_array(Gamein& arrayin, int num, bool is_next = false, bool gotonext = false);
void color_act(int choose, Gamein& arrayin);
void out_array(Gamein& arrayin, bool is_grid = 1, bool is_road = 0);
void xyin_key_array(Gamein& arrayin);
int mover(Gamein& arrayin);
int aftermove(Gamein& arrayin);
int blank_gameover(Gamein& arrayin);
/* 空文件，给出的目的是防止大家把文件名弄错 */
