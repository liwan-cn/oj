#include<stdio.h>
int main(){
	int n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	int a[1024],b[1024];
	for(int i=0;i<1024;i++) {a[i]=0;b[i]=-1;}
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x]++;
		b[y]=x;
	}
	l=b[l];
	double ans=1;
	while(l>=0){
		ans*=a[l];
		l=b[l];
	}
	printf("%.6lf\n",1/ans);
	return 0;
}
