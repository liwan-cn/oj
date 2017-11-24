#include<stdio.h>
int main(){
	char s[10000];
	while(scanf("%s",s)!=EOF){
		int x=0;
		if(s[0]=='0'&&s[1]==0) break;
		else{
			for(int i=0;s[i]!=0;i++)
				x+=s[i]-'0';
			while(x>=10){
				int ans=0;
				while(x!=0){
					ans+=x%10;
					x/=10;
				}
				x=ans;
			}
			printf("%d\n",x);
		}
	} 
	return 0;
}
