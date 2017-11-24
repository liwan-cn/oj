#include<stdio.h>
#include<string.h>
char s[100000]; 
int ans[27];
int main(){
	while(gets(s)){
		for(int i=0;i<27;i++)
			ans[i]=0;
		int l=strlen(s);
		for(int i=0;i<l;i++){
			if(s[i]>='A'&&s[i]<='Z')
				ans[s[i]-'A']++;
		}
		for(int i=0;i<26;i++)
			printf("%c:%d\n",i+'A',ans[i]);
	}
	return 0; 
}
