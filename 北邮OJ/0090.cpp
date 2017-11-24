#include<stdio.h>
int main(){
	int t;
	char s[1024];
	int a[27][27];
	for(int i = 0;i<26;i++)
		for(int j = 0;j<26;j++)
			a[i][j] = ((j+26-i)%26)<((i+26-j)%26)?((j+26-i)%26):((i+26-j)%26);
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int count=0,min=999999999;
		for(int i=0;i<26;i++,count=0){
			for(int j=0;s[j]!=0;j++)
				count += a[i][s[j]-'a'];
			min = count<min?count:min;
		}
		printf("%d\n",min);
	}
	return 0;
}
