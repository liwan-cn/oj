#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int ans=0;
		int a[100];
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				for(int k=0;k<m;k++)
					if(a[i]+a[j]==a[k]) ans++;
		printf("%d\n",ans);
	} 
	return 0; 
} 
