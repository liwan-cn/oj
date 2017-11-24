#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(long long int l1,long long int l2){
	return l1>l2;
}
int main(){
	long long int l,buf[601];
	int n;
	while(scanf("%lld %d",&l,&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%lld",&buf[i]);
		sort(buf,buf+n,cmp);
		int i;
		for(i=0;i<n;i++){
			l-=buf[i];
			if(l<=0) break;
		}
		if(i<n) printf("%d\n",i+1);
		else printf("impossible\n");
	}
	return 0;
}
