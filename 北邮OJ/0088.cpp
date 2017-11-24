#include<stdio.h>
int main(){
	int t,n,tmp;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%d",&tmp);
		int max1=tmp,max2=tmp;
		while(--n){
			scanf("%d",&tmp);
			if(tmp>max1){
				max2=max1;
				max1=tmp;
			}
			
		}
		printf("%d %d\n",max1,max2);	
	}
	return 0;
} 
