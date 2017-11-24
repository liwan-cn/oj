#include<stdio.h>
#define abs(x) x<0?-x:x
int pd(int n,int i,int j){
	if(n==0) return 0;
	if(i==n&&j==n) return 2;
	int t=i>j?i:j; 
	return (t%2);
}
int main(){
	char a[3];
	int n;
	a[2]=' ';
	bool flag=false;
	while(scanf("%d %c %c",&n,&a[0],&a[1])!=EOF){
		if(flag) printf("\n");
		else flag=true;
		int t=n/2;
		for(int i=-t;i<=t;i++){
			for(int j=-t;j<=t;j++){
				printf("%c",a[pd(t,abs(i),abs(j))]);
			}
			printf("\n");
		}
		
	}
	return 0;
} 
