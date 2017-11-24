#include<stdio.h>
#include<cstring>
#define ISYEAR(x) x%100!=0 && x%4==0 || x%400==0?1:0

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
char monthName[13][20]={
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
char weekName[7][20]={
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
}; 
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
	char s[20];
	while(scanf("%d%s%d",&d,s,&y)!=EOF){
		for(m=1;m<13;m++){
			if(strcmp(s,monthName[m])==0)
			break;
		}
		int days=buf[y][m][d]-buf[2017][2][6]+1;
		puts(weekName[(days%7+7)%7]);
		//printf("%d\n",ABS(buf[y2][m2][d2]-buf[y1][m1][d1])+1);
	}
	return 0;
}
