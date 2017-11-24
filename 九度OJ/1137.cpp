#include<stdio.h>
#include<string.h>
using namespace std;
struct BigFloat{
	int digit0[100],digit1[100];
	int size0,size1;
	void init(){
		for(int i=0;i<100;i++)
			digit1[i]=digit0[i]=0;
		size0=size1=0;
	}
	void set(char str[]){
		init();
		int L1;
		for(int i=0;str[i]!=0;i++){
			if(str[i]=='.'){
				L1=i;break;
			}
		}
		for(int i=L1-1;i>=0;i--)
			digit0[size0++]=str[i]-'0';
		for(int i=L1+1;str[i]!=0;i++)
			digit1[size1++]=str[i]-'0';
	//	output();
	}
	void output(){
		for(int i=size0-1;i>=0;i--)
			printf("%d",digit0[i]);
		printf(".");
		for(int i=0;i<size1;i++)
			printf("%d",digit1[i]);
		printf("\n");
	}
	BigFloat operator +(const BigFloat &x) const {
		BigFloat ret;
		ret.init();
		bool flag=false;
		int carry=0;
		for(int i=99;i>=0;i--){
			int tmp=digit1[i]+x.digit1[i]+carry;
			ret.digit1[i]=tmp%10;
			if(ret.digit1[i]!=0&&flag==false){
				ret.size1=i+1;
				flag=true;
			}
			carry=tmp/10;
		}
		for(int i=0;i<size0||i<x.size0;i++){
			int tmp=digit0[i]+x.digit0[i]+carry;
			ret.digit0[ret.size0++]=tmp%10 ;
			carry=tmp/10;
		}
		if(carry!=0) ret.digit0[ret.size0++]=carry;
		return ret;
	}
};
int main(){
	char str1[200],str2[200];
	BigFloat a,b,c;
	int n;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			scanf("%s %s",str1,str2);
			a.set(str1);b.set(str2);
			c=a+b;
			c.output();
		}
	}
	return 0;
}
