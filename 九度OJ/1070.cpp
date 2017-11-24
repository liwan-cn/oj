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
int buf[3001][13][32];
int main(){
	Date tmp;
	int cnt=0;
	tmp.day=1;
	tmp.month=1;
	tmp.year=0;
	while(tmp.year!=3001){
		buf[tmp.year][tmp.month][tmp.day]=cnt;
		tmp.nextday();
		cnt++;
	}
	int d,m,y;
	while(scanf("%d%d%d",&y,&m,&d)!=EOF){
		printf("%d\n",ABS(buf[y][m][d]-buf[y][1][1])+1);
	}
	return 0;
}
