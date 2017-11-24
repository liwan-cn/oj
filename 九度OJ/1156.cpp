#include<stdio.h>
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		int data[256];
		int Hash[256]={0};
		for(int i=0;i<n;i++){
			scanf("%d",&data[i]);
			Hash[data[i]]++; 
		}
		for(int i=0;i<n;i++){
			if(Hash[data[i]]>1) printf("%d\n",Hash[data[i]]-1);
			else printf("BeiJu\n");
		}
	}
	return 0;
}
