#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int a[128],m;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		while(m--){
			int temp;
			scanf("%d",&temp);
			int i=0;
			for(i=0;i<n;i++){
				if(a[i]==temp) {
					printf("YES\n");
					break;
				}
			}
			if(i==n) printf("NO\n");
		}
	}
	return 0;
}
