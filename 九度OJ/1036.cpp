#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		int tmp=x*1000+y*100+z*10;
		int h,l;
		bool flag=false;
		for(int i=9;i>0;i--){
			for(int j=9;j>=0;j--){
				if((i*10000+tmp+j)%n==0){
					h=i;l=j;
					flag=true;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) 
			printf("%d %d %d\n",h,l,(h*10000+tmp+l)/n);
		else
			printf("0\n");
	}
	return 0;
}
