#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	char s[256];
	while(scanf("%s",s)!=EOF){
		sort(s,s+strlen(s));
		printf("%s\n",s);
	}
	return 0;
}
