#include<stdio.h>
int main(){
	for(int i=0;i<256;i++){
		int x=i*i,size=0;
		char s[8];
		while(x!=0){
			s[size++]=x%10;
			x/=10;
		}
		int j;
		for(j=0;j<size;j++){
			if(s[j]!=s[size-j-1]) break;
		}
		if(j==size) printf("%d\n",i);
	}
	return 0;
}
