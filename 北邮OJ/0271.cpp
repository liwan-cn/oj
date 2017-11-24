#include<stdio.h>  
char a[55][55];  
char b[55][55];  
int m,n;  
void rotate()  {  
    int i,j;  
    for(i=0; i<n; i++) {  
        for(j=0; j<m; j++)  
            b[i][j]=a[m-1-j][i];  
    }  
    for(i=0; i<n; i++) {  
        for(j=0; j<m; j++)  
            a[i][j]=b[i][j];  
        a[i][j]='\0';  
    }  
    int tmp=m;   
    m=n;  
    n=tmp;  
}  
  
int main(){  
    int t;  
    scanf("%d",&t);
    while(t--){
    	scanf("%d%d",&m,&n);  
    	//getchar();
        for(int i=0; i<m; i++)
            scanf("%s",a[i]);  
        int d;  
        scanf("%d",&d);  
        d=d/90;
        while(d--)  
            rotate();  
        for(int i=0; i<m; i++)  
            printf("%s\n",a[i]);  
	}            
    return 0;   
}  
