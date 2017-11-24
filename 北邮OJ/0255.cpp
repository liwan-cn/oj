#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int even=0,odd=0;
		int temp;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&temp);
			if(temp%2) odd+=temp;
			else even+=temp;
			
		}
		printf("%d %d\n",odd,even);
	}
	return 0;
} 
