#include<stdio.h>
int main(){
	int n;
    unsigned long long int tmp;
    while(scanf("%d",&n)!=EOF){
    	unsigned long long int ones = 0, twos = 0, threes = 0;
    	while(n--){
    		scanf("%llu",&tmp);
    		twos |= ones & tmp;//����һ�ε� & tmp,�õ�tmp �Ƿ�֮ǰ���ֹ������ | ֮ǰ����ĳ������� 
    		//tmpδ���ֹ��Խ����Ӱ�죬���ֹ���twos�м���tmp; 
			ones ^= tmp;//���3��1�εĽ��һ�������ֻ���ֹ����Σ���ones�в����棬ֻ���������ε� 
			threes = ones & twos; //���������ε�����ִ��ڵ������εģ�������3�ε� 
			ones &= ~threes;//�����������м�ȥ����3�ε� 
			twos &= ~threes;//���ִ��ڵ��������м�ȥ����3�ε� 
		}
		printf("%lld\n",ones);
	}
	return 0;
} 
