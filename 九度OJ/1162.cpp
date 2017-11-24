#include<stdio.h>
#include<vector>
using namespace std;
struct E{
	int next;
	int cost;
}; 
vector<E> edge[601];
bool mark[601];
int Dis[601];
int flag[601];
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		for(int i=1;i<=n;i++){
			edge[i].clear();
			Dis[i]=-1;
			mark[i]=false;
		}		
		while(m--){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			E tmp;
			tmp.cost=c;
			tmp.next=a;
			edge[b].push_back(tmp);
			tmp.next=b;
			edge[a].push_back(tmp);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&flag[i]);
		}
		Dis[1]=0;
		mark[1]=true;
		int newP=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<edge[newP].size();j++){
				int t=edge[newP][j].next;
				int c=edge[newP][j].cost;
				if(mark[t]) continue;
				if(flag[newP]>flag[t]) continue;
				if(Dis[t]==-1||Dis[t]>Dis[newP]+c)
					Dis[t]=Dis[newP]+c;
			}
			int min=999999999;
			for(int j=1;j<=n;j++){
				if(mark[j]) continue;
				if(Dis[j]==-1) continue;
				if(Dis[j]<min){
					min=Dis[j];
					newP=j;
				}
			}
			mark[newP]=true;
			if(newP==2) break;
		}
		printf("%d\n",Dis[2]);
	}
	return 0;
}
