#include<stdio.h>
#include<string.h>
char s[1000],t[1000];
int main(){
	int n;
	scanf("%s",s);
	scanf("%d",&n);
	while(n--){
		char cmd[8];
		scanf("%s",cmd);
		if(strcmp(cmd,"COPY")==0){
			int l,r;
			scanf("%d%d",&l,&r);
			for(int i=0;i<=r-l;i++){
				t[i]=s[i+l];
			}
			t[r-l+1]=0;
			//puts(t);
			puts(s);
		}
		else if(strcmp(cmd,"CUT")==0){
			int l,r;
			scanf("%d%d",&l,&r);
			for(int i=0;i<=r-l;i++){
				t[i]=s[i+l];
			}
			t[r-l+1]=0;
			int len1=strlen(s);
			int len2=strlen(t);
			for(int i=l;i+len2<=len1;i++){
				s[i]=s[i+len2];
			}
			//puts(t);
			puts(s);
		}
		else {
			int p;
			scanf("%d",&p);
			int len=strlen(t);
			for(int i=strlen(s);i>p;i--){
				s[i+len]=s[i];
			}	
			for(int i=0;i<len;i++){
				s[p+i+1]=t[i];
			}
			//puts(t);
			puts(s);
		}
	}
	
	return 0;
}
