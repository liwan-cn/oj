#include<stdio.h>
#include<string.h>

int flag[10];
char a[128];

void pd(int l,int s){
	bool f=false;
	if(l<=4){
		for(int i=s+1;i<=9;i++){
			if(flag[i]>=l){
				f=true;
				break;
			}
		}
	}
	else{
		
		for(int i=s+1;i<=5;i++){
			int ans=0;
			for(int j=i;j<=i+5;j++){
				if(flag[j]>0) ans++;
				else break;
			}
			if(ans>=5){
				f=true;
				break;
			} 
		}
		
	}
	if(f) printf("YES\n");
	else printf("NO\n"); 
	
}

int main(){

	while(scanf("%s",a)!=EOF){
		int l=strlen(a);
		for(int i=1;i<=9;i++)
			flag[i]=0;
		for(int i=0;i<l;i++)
			flag[a[i]-'0']++;
		int n;
		scanf("%d",&n);
		if(n<10) pd(1,n);
		else if(n<100) pd(2,n/10);
		else if(n<1000) pd(3,n/100);
		else if(n<10000) pd(4,n/1000);
		else pd(5,n/10000);
	}
	return 0;
} 
