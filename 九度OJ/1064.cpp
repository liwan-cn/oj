#include<stdio.h>
int main(){
	char s1[8],s2[8];
	for(int i=1000;i<1112;i++){
		int x=i,y=i*9;
		for(int j=0;j<4;j++){
			s1[j]=x%10;x/=10;
			s2[j]=y%10;y/=10;
		}
		int k;
		for(k=0;k<4;k++){
			if(s1[k]!=s2[3-k]) break;
		}
		if(k==4) printf("%d\n",i);
	}
	return 0;
}
