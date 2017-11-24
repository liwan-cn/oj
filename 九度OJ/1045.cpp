#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<=100;i++){
			for(int j=0;j<=100-i;j++){
				int k=100-i-j;
				if(i*15+j*9+k<=n*3){
					printf("x=%d,y=%d,z=%d\n",i,j,k);
				}
			}
		}
	}
	return 0;
}
