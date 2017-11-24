#include<stdio.h>
int main(){
	int n;
	int m=200907;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			unsigned long long int a,b,c,k;
			scanf("%llu %llu %llu %llu",&a,&b,&c,&k);
			if(b-a==c-b){
				unsigned long long int d = (b-a)%m;
				a%=m;
				a+=((k-1)%m)*d%m;
				a%=m;	
			}
			else{
				unsigned long long int d = (b/a)%m;
				a%=m;
				unsigned long long int ans=1;
				k--;
				while(k!=0){
					if(k%2==1){
						ans*=d;
						ans%=m;
					}
					k/=2;
					d*=d;
					d%=m;
				}
				a=a*ans%m;
			}
			printf("%llu\n",a);
		}
	}
	return 0;
}
