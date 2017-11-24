#include<stdio.h>
long long int F(int num){
	if(num==1) return 2;
	else return 3*F(num-1)+2;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",F(n));
	}
	return 0;
}
