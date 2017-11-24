#include<stdio.h>
struct E{
	int w,v;
};
E list[2001];
int dp[101];
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int s,n;
		scanf("%d %d",&s,&n);
		int cnt=0;
		for(int i=0;i<n;i++){
			int v,w,k;
			scanf("%d %d %d",&w,&v,&k);
			while(k--){
				list[cnt].w=w;
				list[cnt].v=v;
				cnt++;
			}
		}
		for(int i=0;i<=s;i++) dp[i]=0;
		for(int i=0;i<cnt;i++){
			for(int j=s;j>=list[i].w;j--){
				dp[j]=max(dp[j],dp[j-list[i].w]+list[i].v);
			}
		}
		printf("%d\n",dp[s]);
	}
	return 0;
}
