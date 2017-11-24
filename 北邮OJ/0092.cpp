#include<stdio.h>
struct Node{
	int inAndout;
	int father;
};
Node E[1024];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			E[i].father=-1;
			E[i].inAndout=0;
		}
		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			E[b].father=a;
			E[a].inAndout++;
			E[b].inAndout++;
		}
		int count = 0;
		for(int i=0;i<n;i++){
			bool flag = true;
			for(int j=0;j<n;j++){
				if((i==E[j].father||j==E[i].father)&&E[i].inAndout<E[j].inAndout){
					//if(i==E[j].father) printf("%d:%dÊÇ%d:%d¸¸Ç×\n",i,E[i].inAndout,j,E[j].inAndout);
					//if(j==E[i].father) printf("%d:%dÊÇ%d:%d¶ù×Ó\n",i,E[i].inAndout,j,E[j].inAndout);
					flag=false;
					break;
				}
			}
			//printf("%d-",E[i].inAndout);
			//printf("==%d\n",n);
			if(flag) count++;
		}
		printf("%d\n",count);
	}
}
