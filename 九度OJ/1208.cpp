#include<stdio.h>
#include<string.h>
struct BigInt{
	int digit[1000];
	int size;
	void init(){
		for(int i=0;i<1000;i++)
			digit[i]=0;
		size=0;
	}
	void set(int x){
		init();
		do{
			digit[size++]=x%10000;
			x/=10000;
		}while(x!=0);
	}
	void set(char str[]){
		init();
		int L=strlen(str);
		for(int i=L-1,j=0,t=0,c=1;i>=0;i--){
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
	BigInt operator + (const BigInt &A) const{
		BigInt ret;
		ret.init();
		int carry=0;
		for(int i=0;i<A.size||i<size;i++){
			int tmp=A.digit[i]+digit[i]+carry;
			carry=tmp/10000;
			tmp%=10000;
			ret.digit[ret.size++]=tmp;
		}
		if(carry!=0)
			ret.digit[ret.size++]=carry;
		return ret;
	}
	BigInt operator * (int x) const{
		BigInt ret;
		ret.init();
		int carry=0;
		for(int i=0;i<size;i++){
			int tmp=x*digit[i]+carry;
			carry=tmp/10000;
			tmp%=10000;
			ret.digit[ret.size++]=tmp;
		}
		if(carry!=0) ret.digit[ret.size++]=carry;
		return ret;
	} 
	BigInt operator / (int x) const{
		BigInt ret;
		ret.init();
		int rem=0;
		for(int i=size-1;i>=0;i--){
			int t=(rem*10000+digit[i])/x;
			int r = (rem*10000+digit[i])%x;
			ret.digit[i]=t;
			rem=r;
		}
		ret.size=0;
		for(int i=0;i<1000;i++){
			if(digit[i]!=0) ret.size=i;
		}
		ret.size++;
		return ret;
	}
	int operator % (int x) const{
		int rem=0;
		for(int i=size-1;i>=0;i--){
			int r = (rem*10000+digit[i])%x; 
			rem=r;
		}	
		return rem;
	}
};
char str[1024];
char str2[10000];
BigInt a,b;
int main(){

	while(scanf("%s",str)!=EOF){
		int size=0;
		a.set(str);
		do{
			str2[size++]=a%2;
			a=a/2;
		}while(a.digit[0]!=0||a.size!=1);
		a.set(0);
		b.set(1);
		for(int i=size-1;i>=0;i--){
			if(str2[i]) a=a+b;
			b=b*2;
		}
		a.output();
	}
	return 0;
}
