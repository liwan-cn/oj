#include<stdio.h>
int main(){
	int h;
	while(scanf("%d",&h)!=EOF){
		for(int i=1;i<=h;i++){
			int t=3*h-2;
			for(int j=1;j<=t;j++){
				if(j<=t-h-(i-1)*2) printf(" ");
				else printf("*");
			}
			printf("\n");
		}
	
	}
	return 0;
}
