#include<stdio.h>
#include<string.h>
int main(){
	char s[256];
	while(scanf("%s",s)!=EOF){
		int t;
		scanf("%d",&t);
		while(t--){
			int flag,point,len;
			char ss[256];
			scanf("%d %d %d",&flag,&point,&len);
			if(flag) {
				scanf("%s",ss);
				for(int i=0;i<len;i++){
					s[i+point]=ss[i];
				}
			}
			else{
				char temp;
				for(int i=0;i<len/2;i++){
					temp=s[point+i];
					s[point+i]=s[point+len-i-1];
					s[point+len-i-1]=temp;
				}
			}
			printf("%s\n",s);
		}
	
	}
	return 0;
}
