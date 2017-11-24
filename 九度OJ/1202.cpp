#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int s[128];
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++) scanf("%d",&s[i]);
		sort(s,s+n);
		for(int i=0;i<n;i++) printf("%d ",s[i]);
		printf("\n");
	}
	return 0;
} 
