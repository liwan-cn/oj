#include<stdio.h>
int main(){
	
	int x;
	while(scanf("%d",&x)!=EOF){
		bool flag=true;
		int y=x*x;
        int a=y%10,b=x%10;
        while(x!=0){
            if(a!=b) {
                flag=false;
                break;    
            }    
            else{
                y=y/10;a=y%10;
                x=x/10;b=x%10;
            }
        }
		puts(flag?"Yes!":"No!");
	}
	return 0;
}
