/* 2452640 汽车 罗啦 */
#include <iostream>
#include <conio.h>
#include "7-b6.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
bool Date::isLeapYear(int y) const
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
int Date::getDaysInMonth(int y, int m) const
{
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (m == 2 && isLeapYear(y)) {
		return 29;
	}
	return days[m - 1];
}
bool Date::isValidDate(int y, int m, int d) const
{
	if (y < 1900 || y > 2099) return false;
	if (m < 1 || m > 12) return false;
	if (d < 1 || d > getDaysInMonth(y, m)) return false;
	return true;
}
void Date::normalizeDate(int& y, int& m, int& d) const
{
	if (y < 1900 || y > 2099) {
		y = 2000;
	}
	if (m < 1 || m > 12) {
		m = 1;
	}
	if (d < 1 || d > getDaysInMonth(y, m)) {
		d = 1;
	}
}
int Date::dateToDays(int y, int m, int d) const
{
	int days = 0;
	for (int i = 1900; i < y; i++) {
		days += isLeapYear(i) ? 366 : 365;
	}
	for (int i = 1; i < m; i++) {
		days += getDaysInMonth(y, i);
	}
	days += d;
	return days;  
}
void Date::daysToDate(int days, int& y, int& m, int& d) const
{
	int remaining = days - 1; 
	for (y = 1900; y <= 2099; y++) {
		int yearDays = isLeapYear(y) ? 366 : 365;
		if (remaining < yearDays) break;
		remaining -= yearDays;
	}

	for (m = 1; m <= 12; m++) {
		int monthDays = getDaysInMonth(y, m);
		if (remaining < monthDays) break;
		remaining -= monthDays;
	}

	d = remaining + 1;
}

Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}
Date::Date(int days)
{
	if (days < 1) {
		days = 1;
	}
	int maxDays = dateToDays(2099, 12, 31);
	if (days > maxDays) {
		days = maxDays;
	}

	daysToDate(days, year, month, day);
}
Date::Date(int y, int m, int d)
{
	int newY = (y == 0) ? 2000 : y;
	int newM = (m == 0) ? 1 : m;
	int newD = (d == 0) ? 1 : d;

	if (newY < 1900 || newY > 2099) {
		newY = 2000;
	}
	if (newM < 1 || newM > 12) {
		newM = 1;
	}
	if (newD < 1 || newD > getDaysInMonth(newY, newM)) {
		newD = 1;
	}

	year = newY;
	month = newM;
	day = newD;
}
void Date::set(int y, int m, int d)
{
	int newY = (y == 0) ? year : y;
	int newM = (m == 0) ? month : m;
	int newD = (d == 0) ? day : d;

	if (newY < 1900 || newY > 2099) {
		newY = 2000;
	}
	if (newM < 1 || newM > 12) {
		newM = 1;
	}
	if (newD < 1 || newD > getDaysInMonth(newY, newM)) {
		newD = 1;
	}

	year = newY;
	month = newM;
	day = newD;
}

void Date::set(int y, int m)
{
	set(y, m, 0); 
}
void Date::set(int y)
{
	set(y, 0, 0);  
}
void Date::set(int y, int m, int d, int mode)
{
	if (mode == 0) {
		set(y, m, d); 
	}
}
void Date::get(int& y, int& m, int& d) const
{
	y = year;
	m = month;
	d = day;
}
void Date::show() const
{
	cout << year << "." << month << "." << day << endl;
}
/* 如果有需要的其它全局函数的实现，可以写于此处 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
