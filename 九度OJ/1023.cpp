#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
struct Elem{
	int num;
	char name[16];
	int score;
}data[100005];
bool cmp1(Elem a,Elem b){
	return a.num<b.num;
}
bool cmp2(Elem a,Elem b){
	int tmp=strcmp(a.name,b.name);
	if(tmp!=0) return tmp<0;
	else return a.num<b.num;
}
bool cmp3(Elem a,Elem b){
	if(a.score!=b.score) return a.score<b.score;
	else return a.num<b.num;
}
int main(){
	int n,c;
	int count=1;
	while(scanf("%d %d",&n,&c)!=EOF){
		if(n==0&&c==0) {
			count=1;
			continue;
		}
		else{
			for(int i=0;i<n;i++) 
				scanf("%d %s %d",&data[i].num,data[i].name,&data[i].score);
			if(c==1) sort(data,data+n,cmp1);
			else if(c==2) sort(data,data+n,cmp2);
			else if(c==3) sort(data,data+n,cmp3);
			printf("Case %d:\n",count);
			for(int i=0;i<n;i++)
				printf("%06d %s %d\n",data[i].num,data[i].name,data[i].score);
			
		}
		count++;
	}
	return 0;
}
