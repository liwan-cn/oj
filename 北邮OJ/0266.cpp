#include<stdio.h>
#include<math.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d %d",&a,&b);
		int max,min,c;
		if(a>b){
			max=a;
			min=b;
			c=a-b;
		}
		else{
			max=b;
			min=a;
			c=b-a;
		}
		if(a==b)
			printf("1/%d\n",(int)pow(2,a-1));
		else
			printf("%d/%d\n",1+(int)pow(2,c),(int)pow(2,max));
	}
	return 0;
} 
