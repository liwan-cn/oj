#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
struct Student{
	char no[100];
	char name[100];
	int age;
	char sex[32];
}data[1000];
bool cmp(Student s1,Student s2){
	return (strcmp(s1.no,s2.no)<0);
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%s %s %s %d",data[i].no,data[i].name,data[i].sex,&data[i].age);
		sort(data,data+n,cmp);
		int t;
		scanf("%d",&t);
		while(t--){
			char no[100];
			int p=-1;
			scanf("%s",no);
			int low=0,high=n-1;
			while(high>=low){
				int mid=(low+high)/2;
				int tmp=strcmp(no,data[mid].no);
				if(tmp==0){
					p=mid;
					break;
				}
				else if(tmp<0) high=mid-1;
				else low=mid+1;
			}
			if(p==-1) printf("No Answer!\n");
			else printf("%s %s %s %d\n",data[p].no,data[p].name,data[p].sex,data[p].age);
		}
	}
	return 0;
}
