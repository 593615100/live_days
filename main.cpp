#include<stdio.h>
#include<time.h>
#include "tool.h"
#include <iostream>
using namespace std;

int main()
{
	int now_year,now_month,now_day;
	int your_year,your_month,your_day;
	int front_index,back_index,i;
	int sum = 0;
	struct tm* ptm;
	long ts;
	ts = time(NULL);
	ptm = localtime(&ts);
	now_year = ptm->tm_year + 1900;
	now_month = ptm->tm_mon + 1;
	now_day = ptm->tm_mday;
	cout<<"请输入你的出生年月（格式为yyyy-nn-dd）:"<<endl;
	scanf("%d-%d-%d",&your_year,&your_month,&your_day);
	if(your_year != now_year)
	{
		for(i = your_year + 1;i < now_year;i++){
			if(is_leap_year(i))
				sum += 366;
			else
			  sum += 365;
		}
		if(is_leap_year(your_year))
			front_index =366 - day_year(your_year,your_month,your_day);
		else
		  front_index = 365 - day_year(your_year,your_month,your_day);
		back_index = day_year(now_year,now_month,now_day);
		sum = sum + front_index + back_index;
	}else{
			front_index = day_year(your_year,your_month,your_day);
			back_index = day_year(now_year,now_month,now_day);
			sum = back_index - front_index;
	}
	cout<<"you have live "<<sum<<" days"<<endl;
	return 0;
}
