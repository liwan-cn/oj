#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
	char s[32];
	while(gets(s)){
		sort(s,s+strlen(s));
		puts(s);
	}
	return 0;
}
