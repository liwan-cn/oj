#include<stdio.h>
#include<math.h>
bool flag[1001];
int prime[1001];
int size;
bool judge(int x){
	if(x<=1) return false;
	int bound = (int)sqrt(x)+1;
	for(int i=2;i<bound;i++)
		if(x%i==0) return false;
	return true;
}
int cnt[1001],cnt2[1001];

int main(){
	size=0;
	for(int i=0;i<=1000;i++){
		flag[i]=judge(i);
		if(flag[i]) prime[size++]=i;
	}
	int n,a;
	while(scanf("%d %d",&n,&a)!=EOF){
		for(int i=0;i<size;i++)
			cnt[i]=cnt2[i]=0;
		for(int i=0;i<size;i++){
			int t=n;
			while(t){
				cnt[i]+=t/prime[i];
				t/=prime[i];
			}
		}
		int ans=123456789;
		for(int i=0;i<size;i++){
			while(a%prime[i]==0){
				cnt2[i]++;
				a/=prime[i];
			}
			if(cnt2[i]!=0&&cnt[i]/cnt2[i]<ans)
				ans=cnt[i]/cnt2[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
