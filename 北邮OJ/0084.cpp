#include<stdio.h>
int main(){
	int n;
    unsigned long long int tmp;
    while(scanf("%d",&n)!=EOF){
    	unsigned long long int ones = 0, twos = 0, threes = 0;
    	while(n--){
    		scanf("%llu",&tmp);
    		twos |= ones & tmp;//出现一次的 & tmp,得到tmp 是否之前出现过，结果 | 之前保存的出现两次 
    		//tmp未出现过对结果无影响，出现过这twos中加入tmp; 
			ones ^= tmp;//异或3次1次的结果一样，如果只出现过两次，则ones中不保存，只保存奇数次的 
			threes = ones & twos; //出现奇数次的与出现大于等于两次的，即出现3次的 
			ones &= ~threes;//出现奇数次中减去出现3次的 
			twos &= ~threes;//出现大于等于两次中减去出现3次的 
		}
		printf("%lld\n",ones);
	}
	return 0;
} 
