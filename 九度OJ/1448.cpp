#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
queue<int> Q;
vector<int> edge[501];
int main(){
	int in[501];
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0) break;
		for(int i=0;i<n;i++){
			in[i]=0;
			edge[i].clear();
		}
		while(m--){
			int a,b;
			scanf("%d %d",&a,&b);
			in[b]++;
			edge[a].push_back(b);
		}
		while(!Q.empty()) Q.pop();
		for(int i=0;i<n;i++){
			if(in[i]==0) Q.push(i);
		}
		int cnt=0;
		while(!Q.empty()){
			int nowP=Q.front();
			Q.pop();
			cnt++;
			for(int i=0;i<edge[nowP].size();i++){
				in[edge[nowP][i]]--;
				if(in[edge[nowP][i]]==0)
					Q.push(edge[nowP][i]);
			}
		}
		if(cnt==n) puts("YES");
		else puts("NO");
	}
	return 0;
}
 
