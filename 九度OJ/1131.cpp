#include<stdio.h>
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int list[128];
	int dp1[128];
	int dp2[128];
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=1;
		for(int i=0;i<n;i++){
			scanf("%d",&list[i]);
			int tmax=1;
			for(int j=0;j<i;j++){
				if(list[j]<list[i])
					tmax=max(tmax,dp1[j]+1);
			}
			dp1[i]=tmax;
		}
		for(int i=n-1;i>=0;i--){
			int tmax=1;
			for(int j=n-1;j>i;j--){
				if(list[j]<list[i])
					tmax=max(tmax,dp2[j]+1);
			}
			dp2[i]=tmax;
		}
		for(int i=0;i<n;i++){
			ans=max(ans,dp1[i]+dp2[i]-1);
		}
		printf("%d\n",n-ans);
	} 
	return 0;
}
