#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		unsigned int n;
		int er[64];
		scanf("%u",&n);
		int i=0;
		while(n>=1){
			er[i++] = n%2;
			n = n/2;
		}
		while(i--){
			printf("%d",er[i]);
		}
		printf("\n");
	}
	return 0;
}
