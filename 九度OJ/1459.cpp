#include<stdio.h>
#include<math.h>
int p[20];
bool flag[50];
bool judge(int x){
	if(x<=1) return false;
	int bound=sqrt(x)+1;
	for(int i=2;i<bound;i++){
		if(x%i==0) return false;
	}
	return true;
}
void fun(bool mark[20],int t,int n){	
	for(int i=2;i<=n;i++){
		if(!mark[i]&&flag[p[t-1]+i]){
			mark[i]=true;
			p[t]=i;
			if(t==n&&flag[p[t]+1]){
				for(int i=1;i<=n;i++){
					if(i!=1) printf(" ");
					printf("%d",p[i]);
				}
				printf("\n");
			}
			else fun(mark,t+1,n);
			mark[i]=false;
		}
		
	}
}
int main(){
	for(int i=0;i<50;i++)
		flag[i]=judge(i);
	int n;
	int k=0;
	while(scanf("%d",&n)!=EOF){
		bool mark[20];
		for(int i=1;i<=n;i++)
			mark[i]=false;
		mark[1]=true;
		p[1]=1;
		printf("Case %d:\n",++k);
		fun(mark,2,n);
		printf("\n");
	}
	return 0;
}
