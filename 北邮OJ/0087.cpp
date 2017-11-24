#include<stdio.h>
# define ISYEAR(x) x%100!=0&&x%4==0||x%400==0?1:0
int DayOfMonth[13][2]={
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
struct Data{
	int year,month,day;
	void nextDay(){
		day++;
		if(day>DayOfMonth[month][ISYEAR(year)]){
			day=1;month++;
			if(month>12){
				month=1;
				year++; 
			}
		}
	}
};
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int year,month,day;
		scanf("%d%*c%d%*c%d",&year,&month,&day);
		Data tmp;
		tmp.year=year;
		tmp.month=1;
		tmp.day=1;
		int ans=1;
		while(!(tmp.year==year&&tmp.month==month&&tmp.day==day)){
			tmp.nextDay();
			ans++;
		}
		printf("%d\n",ans); 
	}
	return 0;
}

