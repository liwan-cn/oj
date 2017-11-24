#include<stdio.h>
#include<algorithm>
#define N 101 
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
	int a,b,cost;
	bool operator < (const Edge &E) const{
		return cost<E.cost;
	}
};
Edge edge[6000];
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF&&n!=0){
		//int t=n*(n-1)/2;
		for(int i=1;i<=n;i++)
			scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].cost);
		sort(edge+1,edge+1+n);
		for(int i=1;i<=m;i++)
			Tree[i]=-1;
		int ans=0;
		for(int i=1;i<=n;i++){
			int a=findRoot(edge[i].a);
			int b=findRoot(edge[i].b);
			if(a!=b){
				Tree[a]=b;
				ans+=edge[i].cost;
			}
		}
		int flag=0;
		for(int i=1;i<=m;i++){
			if(Tree[i]==-1) flag++;
		} 
		if(flag==1)
			printf("%d\n",ans);
		else
			printf("?\n");
	}
	return 0;
}
