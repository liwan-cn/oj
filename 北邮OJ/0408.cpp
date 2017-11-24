#include<stdio.h>
#include<string>
#include<map>
using namespace std;
map<string,int> M;
int main(){
	char str[128];
	while(scanf("%s",str)!=EOF){
		if(!M[str]) M[str]=1;
		else M[str]++;
		printf("%d\n",M[str]);
	} 
	return 0;
}
 
