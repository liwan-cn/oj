#include<stdio.h>
#include<vector>
#define MOD 100000
using namespace std;
struct  BigInt{
	bool digit[501];
	int size;
	void init(){
		for(int i=0;i<=500;i++)
			digit[i]=false;
		size=0;
	}
	void set(int x){
		digit[x]=true;
		size=size>(x+1)?size:(x+1);
	}
	void output(){
		int ans=0;
		int x=1;
		for(int i=0;i<size;i++){
			if(digit[i]){
				ans=(ans+x)%MOD;
			}
			x=x*2;
			x=x%MOD;
		}
		if(size==0) printf("-1\n");
		else printf("%d\n",ans);
	}
	bool operator <(const BigInt &x) const{
		if(size!=x.size) return size<x.size;
		for(int i=size-1;i>=0;i--){
			if(digit[i]!=x.digit[i])
				return  x.digit[i];
		}
	} 
};
struct E{
	int next;
	int c;
};
vector<E> edge[101];
bool mark[101];
BigInt Dis[101];
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			edge[i].clear();
			Dis[i].init();
			mark[i]=false;
		}		
		Dis[0].size=1;
		mark[0]=true;
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			E tmp;
			tmp.c=i;
			tmp.next=b;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);
		}
		int newP=0;
		//Dis[0].output();
		for(int i=0;i<n;i++){
			for(int j=0;j<edge[newP].size();j++){
				int t=edge[newP][j].next;
				int c=edge[newP][j].c;
				if(mark[t]) continue;
				BigInt tmp=Dis[newP];
				tmp.set(c);
				if(Dis[t].size==0||tmp<Dis[t])
					Dis[t]=tmp;
			}
			BigInt min;
			min.set(500);
			for(int j=0;j<n;j++){
				if(mark[j]) continue;
				if(Dis[j].size==0) continue;
				if(Dis[j]<min){
					min=Dis[j];
					newP=j;
				}
			}
			mark[newP]=true;
		}
		for(int i=1;i<n;i++){
			Dis[i].output();
		}
	}
	return 0;
}
