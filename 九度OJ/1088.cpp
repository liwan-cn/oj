#include<stdio.h>
int Hash[10001];
int main(){
	int l,m;
	while(scanf("%d %d",&l,&m)!=EOF){
		for(int i=0;i<=l;i++) Hash[i]=1;
		while(m--){
			int low,high;
			scanf("%d %d",&low,&high);
			for(int i=low;i<=high;i++){
				if(Hash[i]==1) Hash[i]=0;
			}
		}
		int count=0;
		for(int i=0;i<=l;i++){
			if(Hash[i]==1) count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
