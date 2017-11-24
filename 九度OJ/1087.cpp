#include<stdio.h>
#include<math.h>
bool judge(int x){
	if(x<=1) return false;
	int bound = (int)sqrt(x)+1;
	for(int i=2;i<bound;i++)
		if(x%i==0) return false;
	return true;
}
bool flag[100001];
int prime[100001];
int size;
int main(){
	size=0;
	for(int i=0;i<=100000;i++){
		flag[i]=judge(i);
		if(flag[i]) prime[size++]=i;
	}
	int m;
	while(scanf("%d",&m)!=EOF&&m){
		while(m--){
			long long int n;
			scanf("%lld",&n);
			int t=1;
			for(int i=0;i<size;i++){
				int x=0;
				while(n%prime[i]==0){
					x++;
					n/=prime[i];
				}
				t*=x+1;
				if(n==1) break;
			}
			if(n!=1) t*=2;
			printf("%d\n",t);
		}
	}
	return 0;
}
