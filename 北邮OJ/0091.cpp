#include<stdio.h>
#include<string.h>
struct fileordir{
	int flag;
	char name[32];
	char father[32]; 
};
int main(){
	int t;
	int l=-1;
	fileordir ford[128];
	scanf("%d",&t);
	while(t--){
		l=-1;
		int n;
		scanf("%d",&n);
		while(n--){
			char s[32];
			scanf("%s",s);
			if(strcmp(s,"CREATEDIR")==0) {
				l++;
				ford[l].flag=0;
				scanf("%s",s); strcpy(ford[l].name,s);
				scanf("%s",s); strcpy(ford[l].father,s);
			}
			else if(strcmp(s,"CREATEFILE")==0) {
				l++;
				ford[l].flag=1;
				scanf("%s",s); strcpy(ford[l].name,s);
				scanf("%s",s); strcpy(ford[l].father,s);
			}
			else if(strcmp(s,"LISTDIR")==0) {
				scanf("%s",s);
				for(int i=0;i<=l;i++){
					if((strcmp(s,ford[i].father)==0&&ford[i].flag==0))
					printf("%s\n",ford[i].name);
				}
			}
			else if(strcmp(s,"LISTFILE")==0) {
				scanf("%s",s);
				for(int i=0;i<=l;i++){
					if((strcmp(s,ford[i].father)==0&&ford[i].flag==1))
					printf("%s\n",ford[i].name);
				}
			}
		}
		
	}
	return 0;
}
