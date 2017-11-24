#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int c;
	while(scanf("%d",&c)!=EOF){
		while(c--){
		
			int n,v,w;
			int buf[128];
			scanf("%d %d %d",&n,&v,&w);
			for(int i=0;i<n;i++)
				scanf("%d",&buf[i]);
			sort(buf,buf+n);
			double ans=0; 
			if(buf[0]>w) printf("0 0.00\n");
			else {
				ans+=buf[0]; 
				int i;
				for(i=1;i<n;i++){
					if((ans+buf[i])/(i+1)<=w){
						ans+=buf[i];
					}
					else break;
				} 
				printf("%d %.2lf\n",i*v,ans/i/100);
			}
		}
	}
	return 0;
}
