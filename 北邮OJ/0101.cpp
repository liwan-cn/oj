#include<stdio.h>
//#include<stdlib.h>
int main(){
    int t, a, b, c, d;
    char s[20], k;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        if(sscanf(s,"%d.%d.%d.%d%c",&a,&b,&c,&d,&k)==4){
            if (0<=a&&a<=255&&0<=b&&b<=255&&0<=c&&c<=255&&0<=d&&d<=255)
				puts("Yes");
            else 
				puts("No");
        }
        else puts("No");
    }
    return 0;
}


