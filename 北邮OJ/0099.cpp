#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t); 
	while(t--){
		int count=0;
		char c;
		char s[1024];
		getchar();
		scanf("%c",&c);
		scanf("%s",s);
		for(int i=0;s[i]!='\0';i++){
			if(s[i]==c) count++; 
		}
		printf("%d\n",count);
	}
	return 0;
} 
