#include<stdio.h>
long long int flag[10]={
	1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000
};
int main(){
	int a,b,k;
	while(scanf("%d %d %d",&a,&b,&k)!=EOF&&(a!=0||b!=0)){
		if(a%flag[k]==b%flag[k]) puts("-1");
		else printf("%d\n",a+b);
	}
	return 0;
}
