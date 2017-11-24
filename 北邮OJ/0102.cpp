#include<stdio.h>  
#include<stdlib.h>
#include<string.h>  
#include<math.h>   
#define MIN(x,y) (x)<(y)?(x):(y)  
#define PI acos(-1.0)  
int vis[360],dp[360];
int main(){  
    int n,a,tmp,t;  
    char temp[10];  
    double x,forward,backward,min;  
    scanf("%d",&t);  
    while(t--){  
        min=180; forward=backward=0;  
        memset(dp,0,sizeof(dp));  
        dp[0]=1;  
        scanf("%d",&n);  
        while(n--){  
            scanf("%s%d",temp,&a);  
            if(!strcmp(temp,"forward")) forward+=a;  
            if(!strcmp(temp,"backward")) backward+=a;  
            if(!strcmp(temp,"right")||!strcmp(temp,"left"))  
            {  
                memset(vis,0,sizeof(vis));  
                a=!strcmp(temp,"right")?a:360-a;  
                for(int j=0;j<360;j++){  
                    tmp=(j+a)%360;
                    if(!vis[j]&&dp[j]&&!dp[tmp]){//vis防止重复，必须3个条件满足 
                        dp[tmp]=1; vis[tmp]=1;  
                        min=MIN(min,abs(180-tmp));  
                    }  
                }  
            }  
        }  
        x=forward*forward+backward*backward-2*forward*backward*cos((180.0-min)/180.0*PI);  
        printf("%.3lf\n",sqrt(x));  
    }  
    return 0;  
} 
