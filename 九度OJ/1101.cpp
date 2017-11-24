#include<stdio.h>
int main()
{
   char ch;
   int i,temp,a[200];
   while(scanf("%d",&temp)!=EOF)
   {
       i=1;
       a[0]=0;//用于存储最终的和
       a[1]=temp;//保留第一位数字
       while(scanf("%c",&ch)!=EOF&&ch!='\n')//取运算符
       {
           scanf("%d",&temp);//取运算符后的数字
           if(ch=='-') a[++i]=-temp;
           else if(ch=='+') a[++i]=temp;
           else if(ch=='*') a[i]*=temp;
           else if(ch=='/') a[i]/=temp;
       }
       for(int j=1;j<=i;j++)
       {
           a[0]+=a[j];
       }
       printf("%d\n",a[0]);
 
   }
    return 0;
}
 
