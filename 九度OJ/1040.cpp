#include<stdio.h>
#include<math.h>
bool judge(int x){
	if(x<=1) return false;
	int bound = (int)sqrt(x)+1;
	for(int i=2;i<bound;i++)
		if(x%i==0) return false;
	return true;
}
int main(){
	int x;
	int buf[10001];
	for(int i=2,j=1;j<=10000;i++){
		if(judge(i)) buf[j++]=i;
	}
	while(scanf("%d",&x)!=EOF)
		printf("%d\n",buf[x]);
	return 0;
}
