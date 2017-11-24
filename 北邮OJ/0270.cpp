#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int a[128];
		scanf("%d",&n);
		int num=1;
		int tmp=1;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int ans=a[0];
		for(int i=1;i<n;i++){
			if(a[i]!=a[i-1]){
				if(num<tmp){
					ans=a[i-1];
					num=tmp;
				}
				tmp=1;
			}
			else tmp++;
		}
		if(num<tmp) ans=a[n-1];
		printf("%d\n",ans);
	}
	return 0;
} 
