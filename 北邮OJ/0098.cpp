#include<stdio.h>   
#include<string.h>    
#define LEN 1000  
char ipstr[LEN],temp[LEN];  
int toint(int begin,int end){
	int ans=0;           
    for(int i=end-1,c=1;i>=begin;i--,c*=16) {    
        if(ipstr[i]>='0'&&ipstr[i]<='9')
        	ans+=c*(ipstr[i]-'0');
        else
        	ans+=c*(ipstr[i]-'a'+10);
    }  
//	for(int i=begin;i<end;i++) printf("%c",ipstr[i]);  
//	printf("======%d=====\n",ans);   
    return ans;    
}    
     
void ip_field(int begin,int end){        
    for (int i=begin,flag=1;i<end;i+=2) {    
        int ip=toint(i,i+2);    
        printf("%d",ip);    
        if (flag<=3){    
            printf(".");    
            flag++;    
        }    
    }    
    printf("\n");    
}       
int main(){        
	int n;   
    while(scanf("%d\n",&n)!=EOF){        
        for(int i=1;i<=n;i++){           
            gets(temp);
			int j=0,k=0,length=length=strlen(temp);    
            for(;j<length;j++){    
                if(temp[j]!=' '){    
                    ipstr[k++]=temp[j];    
                }    
            }    
            ipstr[k]='\0';
            printf("Case #%d\n", i);      
            printf("Total length = %d bytes\n",toint(4,8));      
            printf("Source = ");    
            ip_field(24,32);    
            printf("Destination = ");    
            ip_field(32,40);      
            int l=toint(1,2)*8;    
            printf("Source Port = %d\n",toint(l,l+4));    
            printf("Destination Port = %d\n",toint(l+4,l+8));    
            printf("\n");    
        }        
    }    
    return 0;    
}  
