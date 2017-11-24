#include<stdio.h>
int main(){
	int t;
	int hour1,min1,hour2,min2;
	scanf("%d",&t);
	while(t--){
		scanf("%d%*c%d",&hour1,&min1);
		scanf("%d%*c%d",&hour2,&min2);
		printf("%d\n",((hour2*60-hour1*60+min2-min1)+(24*60))%(24*60));
	}
	return 0;
}
