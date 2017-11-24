#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[501];
priority_queue<int,vector<int>,greater<int> > Q;
int main(){
	int in[501];
	//bool flag[501];
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			//flag[i]=false;
			in[i]=0;
			edge[i].clear();
		}
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			in[b]++;
			edge[a].push_back(b);
		}
		while(!Q.empty()) Q.pop();
		for(int i=1;i<=n;i++){
			if(in[i]==0) {
				Q.push(i);
			}
		}  
		int cnt=0;
		while(!Q.empty()){
			int nowP=Q.top();
			Q.pop();
			cnt++;
			for(int i=0;i<edge[nowP].size();i++){
				in[edge[nowP][i]]--;
				if(in[edge[nowP][i]]==0)
					Q.push(edge[nowP][i]);
			}
//			if(nowP==back){
//				for(int i=1;i<=n;i++){
//					if(in[i]==0&&flag[i]==false){
//						Q.push(i);
//						flag[i]=true;
//					}
//				}
//				back=Q.back();
//			}
			if(cnt<n) printf("%d ",nowP);
			else printf("%d\n",nowP);
		}
	}
	return 0;
} 
