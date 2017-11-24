#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		n--;
		int min1,min2;
		int temp1,temp2;
		scanf("%d %d",&min1,&min2);
		while(n--){
			scanf("%d %d",&temp1,&temp2);
			if((temp1<min1)||(temp1==min1&&temp2<min2)){
				min1=temp1;min2=temp2;
			}
		}
		printf("%d %d\n",min1,min2);
	}
	return 0;
}
