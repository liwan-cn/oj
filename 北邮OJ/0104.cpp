#include<stdio.h>
int score[1024];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<1024;i++) score[i]=-1;
		int n;
		scanf("%d",&n);
		while(n--){
			char s[8];
			scanf("%s",s);
			if(s[0]=='I'){
				int id;
				scanf("%d",&id);
				scanf("%d",&score[id]);
			}
			else{
				int id;
				scanf("%d",&id);
				if(score[id]==-1) printf("No result!\n");
				else printf("name:%d score:%d\n",id,score[id]);
			}
		}
	}
	return 0;
}
