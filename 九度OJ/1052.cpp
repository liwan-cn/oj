#include<stdio.h>
int main(){
	int buf[256];
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&buf[i]);
		int x,point=-1;
		scanf("%d",&x);
		for(int i=0;i<n;i++){
			if(buf[i]==x){
				point=i;
				break;
			}
		}
		printf("%d\n",point);
	}
	return 0;
}
