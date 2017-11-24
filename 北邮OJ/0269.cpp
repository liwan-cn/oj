#include<stdio.h>
#include<vector>
using namespace std;
struct E{
	int next;
	int cost;
};
vector<E> edge[1001];
bool mark[1001];
int Dis[1001];
int ans[11][11];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++){
			edge[i].clear();
		}
		while(m--){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			E tmp;
			tmp.cost=w;
			tmp.next=u;
			edge[v].push_back(tmp);
			tmp.next=v;
			edge[u].push_back(tmp);
		}
		int e[11];
		for(int i=1;i<=)
	}
	return 0;
}
