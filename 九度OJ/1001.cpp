#include<stdio.h>
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		int A[10][10];
		bool row[10],column[10];
		for(int i=0;i<n;i++)
			row[i]=false;
		for(int i=0;i<m;i++)
			column[i]=false;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&A[i][j]);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int tmp;
				scanf("%d",&tmp);
				if(A[i][j]+tmp!=0){
					row[i]=true;
					column[j]=true;
				}
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(!row[i]) ans++;
		}
		for(int i=0;i<m;i++){
			if(!column[i]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
