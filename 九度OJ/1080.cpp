#include<stdio.h>
#include<string.h>
#define max 100
struct BigInt{
	int digit[max];
	int size;
	void init(){
		for(int i=0;i<max;i++)
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
//	void set(char str[]){
//		init();
//		int L=strlen(str);
//		for(int i=L-1,j=0,t=0,c=1;i>=0;i--){
//			t+=(str[i]-'0')*c;
//			j++;
//			c*=10;
//			if(j==4||i==0){
//				digit[size++]=t;
//				j=0;t=0;c=1;
//			}
//		}
//	}
//	void output(){
//		for(int i=size-1;i>=0;i--){
//			if(i==size-1) printf("%d",digit[i]);
//			else printf("%04d",digit[i]);	
//		}
//		printf("\n");
//	}
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
			int t=(rem*10000+digit[i])/x;//日了狗了 非得用临时变量 直接赋值就错误 知道原因的请联系QQ 1349654484 
			int r = (rem*10000+digit[i])%x;
			ret.digit[i]=t;
			rem=r;
		}
		ret.size=0;
		for(int i=0;i<max;i++){
			if(digit[i]!=0) ret.size=i;//用ret.size=i+1错误  知道原因的请联系QQ 1349654484 
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
char str[10000];
char ans[10000];
BigInt a,b,c;
int main(){
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF){
		scanf("%s",str);
		int L=strlen(str);
		a.set(0);
		b.set(1);
		for(int i=L-1;i>=0;i--){
			int t;
			if(str[i]>='0'&&str[i]<='9')
				t=str[i]-'0';
			else
			    t=str[i]-'A'+10;
			a=a+b*t;
			b=b*m;
		}
		int size=0;
		do{
			int t=a%n;
			if(t>=10) ans[size++]=t-10+'a';
			else ans[size++]=t+'0';
			a=a/n;
		}while(a.digit[0]!=0||a.size!=1);
		for(int i=size-1;i>=0;i--)
			printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}
