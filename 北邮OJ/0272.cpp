#include<stdio.h>
int G[55][55];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				G[i][j]=n;
			}
			G[i][i]=0;
		}	
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u][v]=G[v][u]=1;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					//if(G[i][k]==n||G[k][j]==n) continue;
					if(G[i][j]>G[i][k]+G[k][j])
						G[i][j]=G[i][k]+G[k][j];
				}
		int ans=1,min=9999;//>=50*50
		for(int i=1;i<=n;i++){
			int tmp=0;
			for(int j=1;j<=n;j++)
				tmp+=G[i][j];
			if(min>tmp){
				ans=i;
				min=tmp;
			} 
		}
		printf("%d\n",ans);						 
	} 
	return 0;
}
