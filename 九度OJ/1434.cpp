#include<stdio.h>
#include<algorithm>
using namespace std;
struct program{
	int startTime;
	int endTime;
}buf[100];
bool cmp(program p1,program p2){
	return p1.endTime<p2.endTime;
} 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		for(int i=0;i<n;i++)
			scanf("%d %d",&buf[i].startTime,&buf[i].endTime);
		sort(buf,buf+n,cmp);
		int currentTime=0,ans=0;
		for(int i=0;i<n;i++){
			if(currentTime<=buf[i].startTime){
				currentTime=buf[i].endTime;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
