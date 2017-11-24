#include<stdio.h>
#include<string.h>
struct Student{
	char name[32];
	char sex[10];
	char birthday[16];
}; 
Student S[512];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		char name[32];
		char sex[10];
		char birthday[16];
		for(int i=0;i<n;i++){
			scanf("%s%s%s",name,sex,birthday);
			strcpy(S[i].name,name);
			strcpy(S[i].sex,sex);
			strcpy(S[i].birthday,birthday);
			//printf("--%s+%s+%s--\n",name,sex,birthday);
		}
		getchar();
		while(m--){
			int cnt=0;
			char str[128];
			gets(str);
			//puts(str);
			char str_t[3][40];
			int flag=sscanf(str,"%s %s %s",str_t[0],str_t[1],str_t[2]);
			bool mark1=false,mark2=false,mark3=false;
			char year_t[8],month_t[8],day_t[8];
			for(int i=0;i<flag;i++){
				//printf("----%s----\n",str_t[i]);
				if(str_t[i][0]=='N'){
					mark1=true;
					sscanf(str_t[i],"%*[^']'%[^']",name);
					//printf("--%s--\n",name);
				}
				else if(str_t[i][0]=='S'){
					mark2=true;
					sscanf(str_t[i],"%*[^']'%[^']",sex);
					//printf("--%s--\n",sex);
				}
				else if(str_t[i][0]=='B'){
					mark3=true;
					sscanf(str_t[i],"%*[^']'%[^/]/%[^/]/%[^']",year_t,month_t,day_t);
					//printf("--%s+%s+%s--\n",year_t,month_t,day_t);
				}
			}
			for(int i=0;i<n;i++){
				if(mark1){
					if(strcmp(S[i].name,name)) continue;
				}
				if(mark2){
					if(strcmp(S[i].sex,sex)) continue;
				} 
				if(mark3){
					char year[8],month[8],day[8];
					sscanf(S[i].birthday,"%[^/]/%[^/]/%s",year,month,day);
					if(strcmp(year_t,"*")!=0){
						if(strcmp(year_t,year)) continue;
					}
					if(strcmp(month_t,"*")!=0){
						if(strcmp(month_t,month)) continue;
					}
					if(strcmp(day_t,"*")!=0){
						if(strcmp(day_t,day)) continue;
					}
				}
				cnt++;
				printf("%s\n",S[i].name);
			} 
			if(cnt==0) printf("NULL\n");	
		}
	}
	return 0;
}
