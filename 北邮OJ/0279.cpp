#include<stdio.h>
#include<string.h>
int main(){
	int R[4];
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<4;i++)
			R[i]=0;
		int n;
		scanf("%d",&n);
		while(n--){
			char cmd[8];
			char tar[8];
			char from[32];
			scanf("%s %[^,],%s",cmd,tar,from);
			int l=strlen(from);
			int tmp=0,d;
			if((from[l-1]=='H'&&from[0]!='0')||from[l-1]=='L'||from[l-1]=='X'){ 
                    if(from[l-1]=='X') tmp=R[from[0]-'A'];  
                    else if(from[l-1]=='L') tmp=R[from[0]-'A']%256;  
                    else tmp=R[from[0]-'A']/256;
			}
			else {
				if(from[l-1]=='H'){
					d=16;
					l--;
				}
				else if(from[l-1]=='B'){
					d=2;
					l--;
				}
				else if(from[l-1]>='0'&&from[l-1]<='9'){
					d=10;
				}
				for(int i=0;i<l;i++)  { 
					int x; 
                    if(from[i]>='0'&&from[i]<='9')  
                        x=from[i]-'0';  
                    else  
                        x=from[i]-'A'+10;  
                    tmp=tmp*d+x;  
                } 
				
			}
			//printf("----%d----\n",tmp);
			
			if(strcmp(cmd,"MOV")==0){
				if(tar[1]=='H'){
					R[tar[0]-'A']=R[tar[0]-'A']%256+tmp*256;
				}
				else if(tar[1]=='L'){
					R[tar[0]-'A']=R[tar[0]-'A']/256*256+tmp;
				}
				else if(tar[1]=='X'){
					R[tar[0]-'A']=tmp;
				}
			}
			
			else if(strcmp(cmd,"ADD")==0){
				if(tar[1]=='H'){
					R[tar[0]-'A']+=tmp*256;
				}
				else 
					R[tar[0]-'A']+=tmp;
			}
		}
		printf("%d %d %d %d\n",R[0],R[1],R[2],R[3]);
	}
	return 0;
}
