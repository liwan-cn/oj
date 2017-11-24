#include<stdio.h>
#include<string.h>
int main(){
	char s[8];
	while(gets(s)){
		for(int i=3;i>=0;i--)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
