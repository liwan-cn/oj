#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,len=0;
		int a[128][2];
		char s[32];
		scanf("%d",&n);
		while(n--){
			scanf("%s",s);
			if(s[0]=='I'){
				int a0,a1;
				scanf("%d%*c%*c%d",&a0,&a1);
				int i=len;
				for(i=len;i>0;i--){
					if((a[i][0]*a[i][0]+a[i][1]*a[i][1]) > (a0*a0+a1*a1)){
						a[i+1][0]=a[i][0];
						a[i+1][1]=a[i][1];
					}
					else{
						a[i+1][0]=a0;
						a[i+1][1]=a1;
						break;
					}
					
				}
				printf("Size: %d\n",++len);
				if(i==0) {
					a[1][0]=a0;a[1][1]=a1;
				}
			}
			else{
				if(len>0) {
					printf("%d+i%d\n",a[len][0],a[len][1]);
					len--;
				}
				if(len>0) printf("Size: %d\n",len);
				else printf("Empty!\n");	
			}
		}
	}
	return 0;
}
