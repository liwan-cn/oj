#include<stdio.h>
int main(){
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(m%i==0&&m/i<=n) 
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
