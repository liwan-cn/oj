#include<stdio.h>
#include<math.h>
int main()
{
    long long n,m,left,count;
    while(scanf("%lld%lld",&m,&n)!=EOF && m!=0 && n!=0){
        long long count=0;
        int i=0;
        left=m;
        while(m<=n){
            count+=int(pow(2.0,i++)); // ���������
            m=m*2+1;  // �����������ɴﵽ��ֵ
            left*=2;  // ����������С�ɴﵽ��ֵ    
        }  
		if(n>=left)  
       		count=count+(n-left+1);
//        while(left<=n){  // �����������ֵ�����������ֵ�Ĳ�ֵ 
//            count++; left++;    
//        }
        printf("%lld\n",count); 
    } 
    return 0;    
} 
