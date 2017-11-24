#include<stdio.h>
#include<string.h>
int main(){
	char s1[8],s2[100];
	while(gets(s1)){
		if(strcmp(s1,"#")==0) break;
		gets(s2);
		int l1=strlen(s1),l2=strlen(s2);
		for(int i=0;i<l1;i++){
			int ans=0;
			for(int j=0;j<l2;j++){
				if(s1[i]==s2[j])
					ans++;
			}
			printf("%c %d\n",s1[i],ans);
		}
	}
	return 0;
} 
