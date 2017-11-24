#include<stdio.h>
int main(){
	int t,n,a[105];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(n%2) printf("%d\n",a[n/2]);
		else{
			printf("%d",(a[n/2]+a[n/2-1])/2);
			if((a[n/2]+a[n/2-1])%2) 
				printf(".5");
			printf("\n");
		}
	}
	return 0;
}
