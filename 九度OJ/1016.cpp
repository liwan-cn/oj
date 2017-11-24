#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
stack<int> s_1,s_2,s_3;
int prime[1001];
int primesize;
bool mark[1001];
void init(){
     for(int i=0;i<=1001;i++)
        mark[i]=false;
     primesize=1;
     prime[0]=1;
     for(int i=2;i<=1000;i++){
        if(mark[i]==true)continue;
        prime[primesize++]=i;
        for(int j=i*i;j<=1000;j+=i)
            mark[j]=true;
     }
}
int main(){
    char s1[200],s2[200],s3[]="0";
    init();
    while(scanf("%s%s",s1,s2)!=EOF){
        if(strcmp(s1,s3)==0&&strcmp(s2,s3)==0)
        return 0;

        int flag=0,q;
        for(int i=0;s1[i]!=0;i++){
            if(s1[i]>='0'&&s1[i]<='9'){
                if(flag==1){
                    q=s_1.top();
                    s_1.pop();
                    s_1.push(q*10+s1[i]-'0');
                }
                else {
                    s_1.push(s1[i]-'0');
                    flag=1;
                }
            }
            else flag=0;
        }
        flag=0;
        for(int i=0;s2[i]!=0;i++){
            if(s2[i]>='0'&&s2[i]<='9'){
                if(flag==1){
                    q=s_2.top();
                    s_2.pop();
                    s_2.push(q*10+s2[i]-'0');
                }
                else {
                    s_2.push(s2[i]-'0');
                    flag=1;
                }
            }
            else flag=0;
        }
        int t1,t2,last=0,i=1;
        for(;!s_1.empty()&&!s_2.empty();last=(t1+t2+last)/prime[i++]){
        	t1=s_1.top();
			t2=s_2.top();
        	s_1.pop();
        	s_2.pop();
            s_3.push(((t1+t2)%prime[i]+last)%prime[i]);
            
        }
        for(;!s_1.empty();last=(t1+last)/prime[i++]){
        	t1=s_1.top();
        	s_1.pop();
            s_3.push((t1+last)%prime[i]);
		}
		for(;!s_2.empty();last=(t2+last)/prime[i++]){
			
        	t2=s_2.top();
        	s_2.pop();
            s_3.push((t2+last)%prime[i]);
            //printf("---%d-%d-%d-%d---\n",t2,last,i,prime[i]);
		}
		if(last>0) s_3.push(last);
		printf("%d",s_3.top());
		s_3.pop();
		while(!s_3.empty()){
			printf(",%d",s_3.top());
			s_3.pop();
		}
        printf("\n");
    }
    return 0;
}
