#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
char str[100001];
int ans[100001];
int flag[26];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%s",str);
		memset(flag,-1,sizeof(flag));
		for(int i=0;str[i]!='\0';i++){
			ans[i]=-1;
			if(flag[str[i]-'a']!=-1){
				ans[i]=i-flag[str[i]-'a'];
				if(ans[flag[str[i]-'a']]==-1) ans[flag[str[i]-'a']] = ans[i];
				else ans[flag[str[i]-'a']] = (ans[i]<ans[flag[str[i]-'a']] ? ans[i] : ans[flag[str[i]-'a']]);	
			}
			flag[str[i]-'a']=i;		
		}
		int length=strlen(str);
		scanf("%d",&n);
		while(n--){
			char op[16];
			char c;
			int pos;
			scanf("%s",op);
			if(strcmp(op,"INSERT")==0){
				getchar();
				scanf("%c",&c);
				str[length]=c;str[length+1]=0;
				ans[length]=-1;
				if(flag[c-'a']!=-1){
					ans[length]=length-flag[c-'a'];
					if(ans[flag[c-'a']]==-1) ans[flag[c-'a']] = ans[length];
					else ans[flag[c-'a']] = (ans[length]<ans[flag[c-'a']] ? ans[length] : ans[flag[c-'a']]);	
				}
				flag[c-'a']=length;
				length++;
			} 
			else{
				scanf("%d",&pos);
				printf("%d\n",ans[pos]);
			}
		}
	}
	return 0;
}
