#include<stdio.h>
#include<string.h>
int main(){
	int n;
	char str[128];
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		int cnt=0;
		int len=strlen(str);
		for(int i=0;i<len;i++){
			if(str[i]=='0') cnt=0;
			else if(str[i]=='1') cnt++;
			printf("%c",str[i]);
			if(cnt==5){
				cnt=0;
				i++;
			} 
		}
		printf("\n");
	}
	return 0;
} 
