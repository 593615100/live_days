#include "tool.h"
bool is_leap_year(int year)
{
	if((year % 4 == 0 && year % 100 != 0) ||(year % 400 == 0))
	  return true;
	else
	  return false;
}

int day_year(int year,int month,int day)
{
	int val = 0;
	int i;
	int num[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	for(i = 0;i < (month - 1);i++)
	  val += num[i];
	if(is_leap_year(year) && month > 2)
	  val += 1;
	val += day;
	  return val;
}
