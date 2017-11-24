#include<stdio.h>
int main(){
	int n;
	int a[100];
	while(scanf("%d",&n)!=EOF){
		while(n--){
			int m;
			scanf("%d",&m);
			for(int i=0;i<m;i++){
				scanf("%d",&a[i]);
			}
			bool flag=false;
			if(a[0]!=a[1]) {
				printf("0");
				flag=true;
			}
			for(int i=1;i<m-1;i++){
				if((a[i]-a[i+1])*(a[i]-a[i-1])>0){
					if(flag) printf(" %d",i);
					else {
						flag=true;
						printf("%d",i);
					}
				}
			} 
			if(a[m-2]!=a[m-1]){
				if(flag) printf(" ");
				printf("%d",m-1);
			}
			printf("\n");
		}	
	}
	return 0;
}
