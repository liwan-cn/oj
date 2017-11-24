#include<stdio.h>
#include<vector>
using namespace std;
vector<int> Edge[128];
bool mark[128];
void kill(int x){
	for(int i=0;i<Edge[x].size();i++)
		kill(Edge[x][i]);
	mark[x]=false;
	Edge[x].clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<128;i++){
			Edge[i].clear();
			mark[i]=false;
		}
		mark[0]=true;
		while(n--){
			char cmd[10];
			scanf("%s",cmd);
			if(cmd[0]=='F'){
				int pid1,pid2;
				scanf("%d %d",&pid1,&pid2);
				mark[pid2]=true;
				Edge[pid1].push_back(pid2);
			}
			else if(cmd[0]=='K'){
				int pid;
				scanf("%d",&pid); 
				kill(pid);
			}
			else{
				int pid;
				scanf("%d",&pid);
				puts(mark[pid]?"Yes":"No"); 
			}
		}
	}
	return 0;
} 
