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
	int a,b,cost,flag;
	bool operator < (const Edge &E) const{
		return cost<E.cost;
	}
};
Edge edge[6000];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int t=n*(n-1)/2;
		for(int i=1;i<=t;i++)
			scanf("%d %d %d %d",&edge[i].a,&edge[i].b,&edge[i].cost,&edge[i].flag);
		sort(edge+1,edge+1+t);
		for(int i=1;i<=n;i++)
			Tree[i]=-1;
		int ans=0;
		for(int i=1;i<=t;i++){
			if(edge[i].flag==1){
				int a=findRoot(edge[i].a);
				int b=findRoot(edge[i].b);
				if(a!=b)
					Tree[a]=b;
			}
		} 
		for(int i=1;i<=t;i++){
			if(edge[i].flag==0){
				int a=findRoot(edge[i].a);
				int b=findRoot(edge[i].b);
				if(a!=b){
					Tree[a]=b;
					ans+=edge[i].cost;
				}
			}
		} 
		
		printf("%d\n",ans);
	}
	return 0;
}
