#include<stdio.h>
#include<string.h>
char str[10001][2][32];
bool flag[10001];
bool flag_tj[32];
bool flag_jg[32];
void print(){
	puts("条件：");
	for(int k=0;k<26;k++){
		if(flag_tj[k]) printf("1");
		else printf("0");
	}
	puts("");
	puts("结果：");
	for(int k=0;k<26;k++){
		if(flag_jg[k]) printf("1");
		else printf("0");
	}
	puts("");
}
bool pd(bool flag_pd[32]){
	for(int i=0;i<26;i++){
		if(flag_pd[i]&&!flag_tj[i])
			return false;
	}
	return true;
}
bool equal_jg(bool flag_eq[32]){
	for(int i=0;i<26;i++){
		if(flag_eq[i]!=flag_jg[i])
			return true;
	}
	return false;
}
bool equal_tj(bool flag_eq[32]){
	for(int i=0;i<26;i++){
		if(flag_eq[i]!=flag_tj[i])
			return true;
	}
	return false;
}
bool js(){
	for(int i=0;i<26;i++){
		if(flag_jg[i])
			return false;
	}
	return true;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%*s%s",str[i][0],str[i][1]);
			flag[i]=false;
		}	
		char tj[32],jg[32];
		scanf("%s%*s%s",tj,jg);
		for(int i=0;i<=26;i++){
			flag_tj[i]=false;
			flag_jg[i]=false;
		}
		int l1=strlen(tj);
		int l2=strlen(jg);
		for(int i=0;i<l1;i++){
			flag_tj[tj[i]-'a']=true;
		}
		for(int i=0;i<l2;i++){
			if(!flag_tj[jg[i]-'a'])
				flag_jg[jg[i]-'a']=true;
		}
		bool f_jg[32],f_tj[32];
		//for(int i=0;i<25;i++) f[i]=flag_jg[i];
		do{
			for(int i=0;i<26;i++) {
				f_tj[i]=flag_tj[i];
				f_jg[i]=flag_jg[i];
			}
			for(int i=0;i<n;i++){
				//printf("====\n");
				if(!flag[i]){
					//printf("111\n");
					bool tmp[32];
					for(int j=0;j<26;j++) tmp[j]=false;
					int ll1=strlen(str[i][0]);
					int ll2=strlen(str[i][1]);
					//printf("%d %d\n",ll1,ll2);
					for(int j=0;j<ll1;j++) {
						flag_jg[str[i][0][j]-'a']=false;
						tmp[str[i][0][j]-'a']=true;
						//printf("222\n");
					}
					if(pd(tmp)){
						//print();
						flag[i]=true;
						for(int j=0;j<ll2;j++){
							flag_tj[str[i][1][j]-'a']=true;
							flag_jg[str[i][1][j]-'a']=false;
						} 
						//print();
					} 
				}
			}
		}while(equal_jg(f_jg)&&equal_tj(f_tj));
		
		if(js()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
