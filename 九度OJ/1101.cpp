#include<stdio.h>
int main()
{
   char ch;
   int i,temp,a[200];
   while(scanf("%d",&temp)!=EOF)
   {
       i=1;
       a[0]=0;//���ڴ洢���յĺ�
       a[1]=temp;//������һλ����
       while(scanf("%c",&ch)!=EOF&&ch!='\n')//ȡ�����
       {
           scanf("%d",&temp);//ȡ������������
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
 
