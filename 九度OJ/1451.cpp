#include<stdio.h>
int main(){
	long long int F[20];
	F[1]=0;
	F[2]=1;
	for(int i=3;i<=20;i++)
		F[i]=(i-1)*(F[i-1]+F[i-2]);
	int n;
	while(scanf("%d",&n)!=EOF)
		printf("%lld\n",F[n]);
	return 0;
}
