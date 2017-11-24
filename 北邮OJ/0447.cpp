#include<stdio.h>
#define N 10001 
using namespace std;
int Tree[N];
int findRoot(int x){
	if(Tree[x]==-1) return x;
	else{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
} 
struct Edge{
	int a,b;
	int flag;
};
Edge edge[200001];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int tmp=m;
		for(int i=1;i<=m;i++)
			scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].flag);
		for(int i=1;i<=n;i++)
			Tree[i]=-1;
		int ans=0;
		for(int i=1;i<=m;i++){
			if(edge[i].flag==0){
				int a=findRoot(edge[i].a);
				int b=findRoot(edge[i].b);
				if(a!=b)
					Tree[a]=b;
			}
		} 
		for(int i=1;i<=m;i++){
			if(edge[i].flag==1){
				int a=findRoot(edge[i].a);
				int b=findRoot(edge[i].b);
				if(a!=b){
					Tree[a]=b;
					ans++;
				}
			}
		} 
		printf("%d\n",ans);
	}
	return 0;
}
