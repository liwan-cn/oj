#include<stdio.h>
#include<math.h>
bool flag[10001];
bool judge(int x){
	if(x<=1) return false;
	int bound = (int)sqrt(x)+1;
	for(int i=2;i<bound;i++)
		if(x%i==0) return false;
	return true;
}
int main(){
	int x;
	for(int i=2;i<=10000;i++){
			flag[i]=judge(i);
	}
	while(scanf("%d",&x)!=EOF){
		bool f=false;
		for(int i=2;i<x;i++){
			if(flag[i]&&i%10==1){
				if(f) {
					printf(" %d",i);	
				}
				else{
					printf("%d",i);
					f=true;
				}
			} 
		}
		if(!f) printf("-1");
		printf("\n");
	}
	return 0;
}
