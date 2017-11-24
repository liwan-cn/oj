#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct BigInt{
	int digit[256];
	int size;
	void init(){
		for(int i=0;i<256;i++)
			digit[i]=0;
		size=0;
	}
	void set(char str[]){
		init();
		int L=strlen(str);
		for(int i=L-1,t=0,j=0,c=1;i>=0;i--){
			t+=(str[i]-'0')*c;
			j++;
			c*=10;
			if(j==4||i==0){
				digit[size++]=t;
				j=0;t=0;c=1;
			}
		}
	}
	void output(){
		for(int i=size-1;i>=0;i--){
			if(i==size-1) printf("%d",digit[i]);
			else printf("%04d",digit[i]);	
		}
		printf("\n");
	}
	bool operator <(const BigInt &x) const {
		if(size!=x.size) return size<x.size;
		for(int i=size-1;i>=0;i--){
			if(digit[i]!=x.digit[i])
				return  digit[i]<x.digit[i];
		}
	}
};
BigInt buf[100];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			char str[1024];
			buf[i].init();
			scanf("%s",str);
			buf[i].set(str);
		}
		sort(buf,buf+n);
		for(int i=0;i<n;i++)
			buf[i].output();
	}
	return 0;
}
