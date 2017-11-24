#include<stdio.h>
int main(){
	long long int a,b;
	int m=8;
	while(scanf("%d",&a)!=EOF){
		int ans[50],size=0;
		while(a>=m){
			ans[size++]=a%m;
			a/=m;
		}
		ans[size]=a;
		for(int i=size;i>=0;i--)
			printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}
