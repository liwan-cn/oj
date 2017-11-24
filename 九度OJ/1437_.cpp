#include<stdio.h>
#include<algorithm>
using namespace std;
struct GasStation{
	double price;
	double distance;
}buf[512];
bool cmp(GasStation g1,GasStation g2){
	return g1.distance<g2.distance;
}
int main(){
	double cmax,d,davg;
	int n;
	while(scanf("%lf %lf %lf %d",&cmax,&d,&davg,&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&buf[i].price,&buf[i].distance);
		sort(buf,buf+n,cmp); 
		if(buf[0].distance>0){
			printf("The maximum travel distance = 0.00\n");
			continue;
		} 
		buf[n].distance=d;
		double remainGas=0,price=0;
		int i=0;
		for(i=0;i<n;){
			int next=i+1;
			if(cmax*davg<(buf[next].distance-buf[i].distance)) {
				printf("The maximum travel distance = %.2lf\n",buf[i].distance+cmax*davg);
				break;
			}
			while(buf[next].price>=buf[i].price&&next<n) {
				if(buf[next].distance-buf[i].distance>cmax*davg) break;	
				next++;
			}
			if(buf[next].distance-buf[i].distance>cmax*davg){
				price+=((cmax-remainGas)*buf[i].price);
				remainGas=cmax-(buf[i+1].distance-buf[i].distance)/davg;
				i++;
			}
			else{
				double tmp = (buf[next].distance-buf[i].distance)/davg-remainGas;
				if(tmp>0){
					price+=tmp*buf[i].price;
					remainGas=0;
					i=next;
				}
				else{
					remainGas-=(buf[i+1].distance-buf[i].distance)/davg;
					i++;
				}	
			}		 
		}
		if(i==n) printf("%.2lf\n",price); 
	}
	return 0;
}
