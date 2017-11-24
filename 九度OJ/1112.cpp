#include<stdio.h>
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int list[26];
	int dp[26];
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=1;
		for(int i=0;i<n;i++){
			scanf("%d",&list[i]);
			int tmax=1;
			for(int j=0;j<i;j++){
				if(list[j]>=list[i])
					tmax=max(tmax,dp[j]+1);
			}
			dp[i]=tmax;
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	} 
	return 0;
}
