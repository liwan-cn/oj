//Î´½â¾ö 
#include<stdio.h>
#include<string>
#define N 20000
using namespace std;
int Tree[N];
int findRoot(int x){
	if(Tree[x]==-1) return x;
	else{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
int Time[N];
int main(){
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF){
		for(int i=1;i<=N;i++){
			Tree[i]=-1;
			Time[i]=0;
		}
		char str1[8],str2[8];
		int time;
		int totalTime=0;
		int id=1;
		while(n--){
			scanf("%s %s %d",str1,str2,time);
			string name1=str1,name2=str2;
			int id1,id2;	
		}
	}
	return 0;
}
