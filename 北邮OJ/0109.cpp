#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
struct STRING{
	char str[101];
};
vector<int> edge[101];
char str[101];
STRING s[101];
int n;
int cnt;
bool flag[101];
bool cmp(STRING s1,STRING s2){
	return strcmp(s1.str,s2.str)<0;
}
void traver(int t,int x){
	if(flag[x]) return;
	flag[x]=true;
	int i=0;
	for(i=0;i<edge[x].size();i++){
		if(!flag[edge[x][i]]) break;
	} 
	if(i<edge[x].size()) traver(t,edge[x][i]);
	s[t].str[cnt++]=str[x];//printf("-%d",x);
	for(;i<edge[x].size();i++){
		if(flag[edge[x][i]]) continue;
		traver(t,edge[x][i]);
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		scanf("%s",str);
		for(int i=0;i<n;i++) edge[i].clear();
		int e[101][101];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				e[i][j]=0;
		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			e[a][b]=1;
			e[b][a]=1;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(e[i][j]==1){
					edge[i].push_back(j);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				flag[j]=false;
			cnt=0;
			traver(i,i);
			s[i].str[n]=0;
		}
		sort(s,s+n,cmp);
		//for(int i=0;i<n;i++)
		printf("%s\n",s[0].str);	
	}
	return 0;
}
