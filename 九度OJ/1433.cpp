#include<stdio.h>
#include<algorithm>
using namespace std;
struct goods{
	double j;
	double f;
}buf[1000];
bool cmp(goods g1,goods g2){
	return (g1.j/g1.f)>(g2.j/g2.f);
}
int main(){
	double m;
	int n;
	while(scanf("%lf %d",&m,&n)!=EOF){
		if(m==-1&&n==-1) break;
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&buf[i].j,&buf[i].f);
		sort(buf,buf+n,cmp);
		int id=0;
		double ans=0;
		while(m>0&&id<n){
			if(m>buf[id].f){
				ans+=buf[id].j;
				m-=buf[id].f;
			}
			else{
				ans+=buf[id].j*m/buf[id].f;
				m=0;
			}
			id++;
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
