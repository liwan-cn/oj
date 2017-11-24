#include<stdio.h>
using namespace std;
int main(){
   char ch;
   int i;
   double temp,a[200];
   while(scanf("%lf",&temp)!=EOF){
       i=1;
       a[0]=0;//用于存储最终的和
       a[1]=temp;//保留第一位数字
       ch=getchar();
       if(ch=='\n'&&temp==0) break;
       while(scanf("%c",&ch)!=EOF&&ch!='\n'){//取运算符
       		getchar();
            scanf("%lf",&temp);//取运算符后的数字
            if(ch=='-') a[++i]=-temp;
            else if(ch=='+') a[++i]=temp;
            else if(ch=='*') a[i]*=temp;
            else if(ch=='/') a[i]/=temp;
            ch=getchar();
            if(ch=='\n') break;
       }
       for(int j=1;j<=i;j++) a[0]+=a[j];
       printf("%.2lf\n",a[0]);
   }
    return 0;
}
 
