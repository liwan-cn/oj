#include<stdio.h>
#include<string.h>
char str1[8],str2[8];
void fun(bool mark[8],int t,int n){	
	for(int i=0;i<n;i++){
		if(!mark[i]){
			mark[i]=true;
			str2[t]=str1[i];
			if(t+1==n) puts(str2);
			else fun(mark,t+1,n);
			mark[i]=false;
		}
		
	}
}
int main(){
	while(scanf("%s",str1)!=EOF){
		bool mark[8];
		int n=strlen(str1);
		for(int i=0;i<n;i++)
			mark[i]=false;
		str2[n]=0;
		fun(mark,0,n);
		puts("");
	}
	return 0;
}
