#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int js[128]={0};
		int x;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			js[x]++;
		}
		scanf("%d",&x);
		printf("%d\n",js[x]); 
	}
	return 0;
}
