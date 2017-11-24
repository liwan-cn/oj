#include<stdio.h>
int main(){
	int n,t;
	int count=0;
	while(scanf("%d",&n)!=EOF){
		count=0;
		while(n--){
			scanf("%d",&t);
			if(t%2) count++;
			else count--; 
		}
		if(count>=0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
