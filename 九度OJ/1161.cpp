#include<stdio.h>
int h[6][8]={
	0,0,0,0,0,0,0,0,//0
	1,1,1,1,1,1,1,1,//1
	1,2,4,8,16,32,64,128,//2
	1,3,9,27,81,243,729,2187,//3
	1,4,16,64,256,1024,4096,0,//4
	1,5,25,125,625,3125,15625,0
};
int flag[5][5];
char c;
int n;
int q;
int tc(int t,int i,int j){
	if(t==0) return flag[i][j];
	else return (flag[i/h[n][t]][j/h[n][t]]*tc(t-1,i%h[n][t],j%h[n][t]));
}
int  main(){

	while(scanf("%d",&n)!=EOF&&n!=0){
		for(int i=0;i<5;i++){
			for(int j=0;j<n;j++){
				flag[i][j]=0;
			}
		}
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				char temp;
				temp=getchar();
				if(temp!=' ') {
					c=temp;
					flag[i][j]=1;
					
				}
			}
			getchar();
		}
		scanf("%d",&q);
		
		for(int i=0;i<h[n][q];i++){ 
			for(int j=0;j<h[n][q];j++){
				if(tc(q-1,i,j)==0) printf(" ");
				else printf("%c",c);
			}
			printf("\n");
		}
	}
	return 0;
} 
