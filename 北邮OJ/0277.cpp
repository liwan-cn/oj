#include<stdio.h>
#include<algorithm>
using namespace std;
struct Block{
	int size;
	bool mark;
	bool operator <(const Block &B) const{
		return size<B.size;
	}
};
Block block[128];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			block[i].mark=true;
			scanf("%d",&block[i].size);
		}
		sort(block,block+n);
		scanf("%d",&m);
		while(m--){
			int tmp;
			scanf("%d",&tmp);
			int i;
			for(i=0;i<n;i++){
				if(block[i].mark&&block[i].size>=tmp)
					break;
			}
			if(i<n){
				block[i].mark=false;
				printf("%d",block[i].size);
			}
			else printf("NULL");
			if(m>0) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
/*
2
4
7 5 10 3
2
4 6
4
3 5 9 10
3
5 12 6 
*/
