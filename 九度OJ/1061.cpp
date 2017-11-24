#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
struct Elem{
	char name[128];
	int age;
	int grade;
}data[1024];
bool cmp(Elem a,Elem b){
	if(a.grade!=b.grade) return a.grade<b.grade;
	int tmp=strcmp(a.name,b.name);
	if(tmp!=0) return tmp<0;
	return a.age<b.age;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++) scanf("%s%d%d",data[i].name,&data[i].age,&data[i].grade); 
		sort(data,data+n,cmp);
		for(int i=0;i<n;i++) printf("%s %d %d\n",data[i].name,data[i].age,data[i].grade);
	}
	return 0;
}
