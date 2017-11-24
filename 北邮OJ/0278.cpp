#include<stdio.h>
int go[8][2]={
	0,1,
	1,0,
	1,1,
	0,-1,
	-1,0,
	-1,-1,
	1,-1,
	-1,1
};
int n,m,d;
bool mark[101][101];
int G[101][101];
void DFS(int x,int y){
	mark[x][y]=true;
	for(int i=0;i<8;i++){
		int nx=x+go[i][0],ny=y+go[i][1];
		if(nx<0||nx>=n||ny<0||ny>=m) continue;
		if(mark[nx][ny]) continue;
		int c=G[nx][ny]-G[x][y];
		c=c>0?c:-c;
		if(c>d) continue;
		DFS(nx,ny);
 	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&d);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&G[i][j]);
				mark[i][j]=false; 
			}
		} 
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!mark[i][j]){
					DFS(i,j);
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

