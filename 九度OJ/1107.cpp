#include<stdio.h>
#include<queue>
using namespace std;
int main(){
	priority_queue<int ,vector<int>,greater<int> > Q;
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		while(!Q.empty()) Q.pop();
		while(n--){
			int x;
			scanf("%d",&x);
			Q.push(x);
		}
		int ans=0;
		while(Q.size()>1){
			int a=Q.top();
			Q.pop();
			int b=Q.top();
			Q.pop();
			ans+=a+b;
			Q.push(a+b);
		}
		printf("%d\n",ans);
	}
	return 0;
}
