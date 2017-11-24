#include<stdio.h>
#include<math.h>
bool flag[100001];
int prime[100001];
int size;
bool judge(int x){
	if(x<=1) return false;
	int bound = (int)sqrt(x)+1;
	for(int i=2;i<bound;i++)
		if(x%i==0) return false;
	return true;
}
int main(){
	size=0;
	for(int i=0;i<=100000;i++){
		flag[i]=judge(i);
		if(flag[i]) prime[size++]=i;
	}
	int n;
	int x=0;		
	while(scanf("%d",&n)!=EOF){
		x=0;
		for(int i=0;i<size;i++){
			while(n%prime[i]==0){
				x++;
				n/=prime[i];
			}
			if(n==1) break;
		}
		if(n!=1) x++;
		printf("%d\n",x);
	}
	return 0;
}


