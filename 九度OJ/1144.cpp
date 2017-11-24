#include<stdio.h>
#include<algorithm>
#include<math.h>
#define N 101
using namespace std;
int Tree[N];
int findRoot(int x){
	if(Tree[x]==-1) return x;
	else {
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
struct Edge{
	int a,b;
	double cost;
	bool operator < (const Edge &E) const{
		return cost<E.cost;
	} 
};
Edge edge[6000];
struct Point{
	double x,y;
	double getDistance(Point P){
		double tmp=(x-P.x)*(x-P.x)+(y-P.y)*(y-P.y);
		return sqrt(tmp);
	}
};
Point list[N];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%lf %lf",&list[i].x,&list[i].y);
		int size=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				edge[size].a=i;
				edge[size].b=j;
				edge[size].cost=list[i].getDistance(list[j]);
				size++;
			}
		}
		sort(edge,edge+size);
		for(int i=1;i<=n;i++){
			Tree[i]=-1;
		}
		double ans=0;
		for(int i=0;i<size;i++){
			int a=findRoot(edge[i].a);
			int b=findRoot(edge[i].b);
			if(a!=b){
				Tree[a]=b;
				ans+=edge[i].cost;
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
