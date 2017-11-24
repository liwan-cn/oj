#include<stdio.h>
#include<string.h>
char str[1024];
void print(int s,int e){
	for(int i=s;i<e;i++){
		printf("%c",str[i]);
	} 
	if(s>0) printf(" ");
	else printf("\n");
}
int main(){
	while(gets(str)){
		int l=strlen(str);
		int e=l,s;
		for(int i=l-1;i>=0;i--){
			if(str[i]==' '||i==0) {
				if(i==0) s=i;
				else s=i+1;
				print(s,e);
				e=i;
			}
		}
	}
}
