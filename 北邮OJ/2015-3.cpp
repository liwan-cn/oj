#include<stdio.h>
#define max 1000
int min(int a,int b){
	return a<b?a:b;
}
struct DP{
	int line;
	int row;
	int l_r;
};
int a[max][max];
DP dp[max][max]; 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int tmp;
			scanf("%d",&tmp);
			a[i][j] &= tmp;
			if(i==0) dp[0][j].l_r=dp[0][j].row=a[i][j];
			if(j==0) dp[i][0].l_r=dp[i][0].line=a[i][j];
			if(a[i][j]==0) {
				dp[i][j].line=0;
				dp[i][j].row=0;
				dp[i][j].l_r=0;
			}
			else {
				if(j>0) dp[i][j].line=dp[i][j-1].line+1;
				if(i>0) dp[i][j].row=dp[i-1][j].row+1;
				if(i>0&&j>0) dp[i][j].l_r=min(dp[i-1][j-1].l_r+1,min(dp[i][j].line,dp[i][j].row));
			}
			ans=ans>dp[i][j].l_r?ans:dp[i][j].l_r;
 		}
	}
/*
	printf("array:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	} 
	printf("line:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",dp[i][j].line);
		}
		printf("\n");
	} 
	printf("row:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",dp[i][j].row);
		}
		printf("\n");
	} 
	printf("l_r:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",dp[i][j].l_r);
		}
		printf("\n");
	} 
*/
	printf("%d\n",ans);
	return 0;
} 
/* 
4
1 1 1 1
1 1 1 0
1 1 1 0
1 1 1 1
0 1 1 1
0 1 1 1
0 1 1 1
0 1 1 0
*/

