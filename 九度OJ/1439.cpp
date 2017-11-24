#include<stdio.h>
long long int gcd(long long int a,long long int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			long long int a,b;
			int m;
			scanf("%d",&m);
			scanf("%lld",&a);
			m--;
			while(m--){
				scanf("%lld",&b);
				a=a*b/gcd(a,b);
			}
			printf("%lld\n",a);
		}
	}
	return 0;
}
