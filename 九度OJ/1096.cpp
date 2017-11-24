#include<stdio.h>
#define ISYEAR(x) x%100!=0 && x%4==0 || x%400==0?1:0
#define ABS(x) x<0?-x:x
int dayofMonth[13][2]={
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};
struct Date{
	int year;
	int month;
	int day;
	void nextday(){
		day++;
		if(day>dayofMonth[month][ISYEAR(year)]){
			day=1;
			month++;
			if(month>12){
				month=1;
				year++;
			}
		}
	}
};
int buf[5001][13][32];
int main(){
	Date tmp;
	int cnt=0;
	tmp.day=1;
	tmp.month=1;
	tmp.year=0;
	while(tmp.year!=5001){
		buf[tmp.year][tmp.month][tmp.day]=cnt;
		tmp.nextday();
		cnt++;
	}
	int d1,d2,m1,m2,y1,y2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF){
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",ABS(buf[y2][m2][d2]-buf[y1][m1][d1])+1);
	}
	return 0;
}
