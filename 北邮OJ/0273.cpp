#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<string.h>
#include<string> 
using namespace std;
vector<int> List[101];
map<string,int> M;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int cnt=0;
		scanf("%d",&n);
		M.clear();
		for(int i=0;i<n;i++)
			List[i].clear();
		while(n--){
			char str[64];
			scanf("%s",str);
			int l=strlen(str);
			if(str[l-1]==']'){
				if(str[l-2]=='['){
					char name[16];
					sscanf(str,"%[^=]",name);
					if(!M[name]){
						M[name]=cnt++;
					}
					else{
						List[M[name]].clear();
					}
				}
				else{
					char name[16];
					int id;
					sscanf(str,"%[^[][%d]",name,&id);
					if(List[M[name]].size()>id){
						printf("%d\n",List[M[name]][id]);
					}
					else{
						printf("ERROR\n");
					}
				}
			}
			if(str[l-1]==')'){
				if(str[l-2]=='('){
					char name[16];
					sscanf(str,"%[^.]",name);
					sort(List[M[name]].begin(),List[M[name]].end());
				}
				else{
					char name[16];
					int tmp;
					sscanf(str,"%[^.].append(%d)",name,&tmp);
					List[M[name]].push_back(tmp);
				}
			}
		} 
	}
}
