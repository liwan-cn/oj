#include<stdio.h>
int main(){
	int a[10][10],b[10][10],c[10][10],d[10][10];
	int t,n,k;
	int m=9973;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d %d",&n,&k);
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++){
					scanf("%d",&a[i][j]);
					c[i][j]=a[i][j];
				}
			k--;	
			while(k!=0){
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						b[i][j]=a[i][j];
						d[i][j]=c[i][j];
					}	
				}
				if(k%2==1){
					for(int i=0;i<n;i++){
						for(int j=0;j<n;j++){
							int ans=0;
							for(int k=0;k<n;k++)
								ans=(ans%m+(b[i][k]%m)*(c[k][j]%m))%m;
							a[i][j]=ans%m;
						}
					}
				}
				k/=2;
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						int ans=0;
						for(int k=0;k<n;k++)
							ans=(ans%m+(d[i][k]%m)*(d[k][j]%m))%m;
						c[i][j]=ans%m;
					}
				}
			}
			int cnt=0;
			for(int i=0;i<n;i++) cnt=(cnt+a[i][i])%m;
			printf("%d\n",cnt);
		} 
	}
	return 0;
}
