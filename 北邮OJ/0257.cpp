#include<stdio.h>
struct Node{
	int father,depth;
};
Node E[128];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			E[i].depth=0;
			E[i].father=-1;
		}
		E[1].depth=1;
		for(int i=1;i<n;i++){
			int f,c;
			scanf("%d %d",&f,&c);
			E[c].father=f;
			E[c].depth=E[f].depth+1;
		}
		scanf("%d",&m);
		while(m--){
			int c1,c2;
			scanf("%d %d",&c1,&c2);
			if(E[c1].depth>E[c2].depth) {
				int tmp=E[c1].depth-E[c2].depth;
				while(tmp--)
					c1=E[c1].father;
			}
			else if(E[c1].depth<E[c2].depth) {
				int tmp=E[c2].depth-E[c1].depth;
				while(tmp--)
					c2=E[c2].father;
			}
			while(c1!=c2){
				c1=E[c1].father;
				c2=E[c2].father;
			}
			printf("%d\n",c1);
		}
	}
}
