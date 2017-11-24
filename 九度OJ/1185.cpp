#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int s[1024];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++) scanf("%d",&s[i]);
		sort(s,s+n);
		if(n==1){
			printf("%d\n",s[0]);
			printf("-1\n");
		}
		else{
			printf("%d\n",s[n-1]);
			for(int i=0;i<n-2;i++) printf("%d ",s[i]);
			printf("%d\n",s[n-2]);
		}
	}
	return 0;
}

