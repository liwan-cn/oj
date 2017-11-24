#include <stdio.h>
char str[40],ans[200];
int nums[40],n,len;
int main() {
	while(~scanf("%s",str)){
		n=0;
		for(n=0; str[n];n++) nums[n] = str[n]-'0';
		int d;
		len = 0;
		int start = 0,tmp;
		while(start < n){
			d = 0; //½èÎ»
			ans[len++] = nums[n-1]%2 +'0';
			for(int i=start; i<n; i++){
				tmp = nums[i];
				nums[i] = (nums[i]+d) / 2;
				if(tmp & 1) d=10;//ÆæÊıÅ¼ÊıÅĞ¶Ï 
				else d=0;
			}
			if(nums[start] == 0) start++;
		}
		for(int i=len-1; i>=0; i--)
			printf("%c",ans[i]);
		puts("");
	}
	return 0;
}
