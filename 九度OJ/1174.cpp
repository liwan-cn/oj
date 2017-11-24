#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int buf[1001];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++) scanf("%d",&buf[i]);
		sort(buf,buf+n);
		int m;
		scanf("%d",&m);
		int i,j;
		for(i=0,j=1;i<n-1,j<=m;i++){
			if(buf[i]!=buf[i+1]) j++;
		}
		printf("%d\n",buf[i-1]);
	}
	return 0;
}
/*
#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int ,vector<int>,greater<int> > Q; 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		while(!Q.empty()) Q.pop();
		while(n--){
			int x;
			scanf("%d",&x);
			Q.push(x);
		}
		int m;
		scanf("%d",&m);
		while(m--){
			if(m==1) printf("%d",Q.top());
			else Q.pop();
		}
	}
	return 0;
}
*/
