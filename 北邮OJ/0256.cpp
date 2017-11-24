#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,now,last,c,temp=2,max=2;
		scanf("%d",&n);
		if(n==1){scanf("%d",&now);printf("1\n");}
		else{
			scanf("%d%d",&last,&now);
			c=now-last;
			last=now;
			for(int i=2;i<n;i++){
				scanf("%d",&now);
				if(now-last==c) {
					temp++;
					max=max>temp?max:temp;
				}
				else {
					temp=2;
					c=now-last;
				}
				last=now;
			}
			printf("%d\n",max);
		}
	} 
	return 0;
}
