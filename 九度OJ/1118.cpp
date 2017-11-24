#include<stdio.h>
int main(){
	int a,b;
	char str[64];
	while(scanf("%d %s %d",&a,str,&b)!=EOF){
		long long int m=1,x=0;
		int i;
		for(i=0;str[i]!=0;i++){
			if(str[i]>='A'&&str[i]<='Z')
				str[i]=str[i]-'A'+'a';
		}
		i--;
		for(;i>=0;i--){
			if(str[i]>='0'&&str[i]<='9')
				x+=(str[i]-'0')*m;
			else 
				x+=(str[i]-'a'+10)*m;
			//printf("%d\n",m);
			m*=a;
		}
		//printf("%d\n",x);
		char ans[50];
		int size=0;
		while(x>=b){
			int tmp=x%b;
			ans[size++]=(tmp<10)?tmp+'0':tmp-10+'A';
			x/=b;
		}
		ans[size]=(x<10)?x+'0':x-10+'A';
		for(;size>=0;size--)
			printf("%c",ans[size]);
		printf("\n"); 
	}
	return 0;
}
