#include<stdio.h>
#include<string.h>
#include<vector> 
using namespace std;
vector<int> V;
int main(){
	int m;
	while(scanf("%d",&m)!=EOF){
		V.clear(); 
		while(m--){
			printf("%d",m);
			char str[10];
			scanf("%s",str);
			 if(strcmp(str,"append")==0){
			 	int tmp;
			 	scanf("%d",&tmp);
			 	V.push_back(tmp);
			 }
			 else if(strcmp(str,"pop")==0){
			 	V.pop_back();
			 }
			 else if(strcmp(str,"find")==0){
			 	int tmp;
			 	scanf("%d",&tmp);
			 	if(tmp<0) tmp=V.size()+tmp;
			 	else tmp--;
			 	printf("%d\n",V[tmp]);
			 }
		}
	}
	return 0;
} 
