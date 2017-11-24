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
            count+=int(pow(2.0,i++)); // 新增结点数
            m=m*2+1;  // 求左子树最大可达到的值
            left*=2;  // 求左子树最小可达到的值    
        }  
		if(n>=left)  
       		count=count+(n-left+1);
//        while(left<=n){  // 求又子树最大值和左子树最大值的差值 
//            count++; left++;    
//        }
        printf("%lld\n",count); 
    } 
    return 0;    
} 
