#include<stdio.h>
#include<algorithm>
#include<math.h>
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
	//int buf[512];
	while(scanf("%lf %lf %lf %d",&cmax,&d,&davg,&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&buf[i].price,&buf[i].distance);
		sort(buf,buf+n,cmp); 
		
		buf[n].distance=d;
		
		double remainGas=0;
		double price=0;
		int i=0;
		bool flag=true;
		for(i=0;i<n;){
			int next=i+1;
			if(cmax*davg<(buf[next].distance-buf[i].distance)) {
				//printf("%d加满油也到不了\n",i);
				flag=false;
				break;
			}
			while(buf[next].price>=buf[i].price&&next<n) {
				if(buf[next].distance-buf[i].distance>cmax*davg) break;	
				next++;
			}
			if(buf[next].distance-buf[i].distance>cmax*davg){
				//printf("%d加满油到下一站 花费 %lf\n",i,(cmax-remainGas)*buf[i].price);
				price+=((cmax-remainGas)*buf[i].price);//加满油 
				remainGas=cmax-(buf[i+1].distance-buf[i].distance)/davg;
				i++;
			}  
			else{
				if(remainGas>(buf[next].distance-buf[i].distance)/davg){
					remainGas-=(buf[i+1].distance-buf[i].distance)/davg;
					//printf("%d不加油到下一站\n",i);
					i++;
				}
				else{
					//printf("%d加适量油到%d 花费 %lf\n",i,next,((buf[next].distance-buf[i].distance)/davg-remainGas)*buf[i].price);
					price+=(((buf[next].distance-buf[i].distance)/davg-remainGas)*buf[i].price);
					remainGas=0;
					i=next;
				} 	
			} 
		}
		if(buf[0].distance>0) printf("The maximum travel distance = 0.00\n");
		else if(flag) printf("%.2lf\n",price);
		else printf("The maximum travel distance = %.2lf\n",buf[i].distance+cmax*davg);
	}
	return 0;
}
