#include<stdio.h>
#include<math.h>
int main(){
	int n;
	int buf[1024];
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d",&buf[i]);
		int d;
		scanf("%d",&d);
		int s=int(pow(2.0,--d));
		int e=2*s;
		if(s>n) printf("EMPTY\n");
		else{
			for(;s<e-1&&s<n;s++)
				printf("%d ",buf[s]);
			printf("%d\n",buf[s]);
		}
	}
	return 0;
}
