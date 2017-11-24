#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int last;
		scanf("%d",&last);
		bool flag=true;
		while(--n){
			int now;
			scanf("%d",&now);
			if(now<last) flag=false;
			last=now;
		}
		puts(flag?"Yes":"No");
	}
	return 0;
}
