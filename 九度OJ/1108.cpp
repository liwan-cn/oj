#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		stack<int> S;
		while(n-- > 0){
			char c;
			int tmp;
			cin>>c;
			if(c=='P'){
				scanf("%d",&tmp);
				S.push(tmp);
			}
			else if(c=='A'){
				if(!S.empty())
					printf("%d\n",S.top());
				else 
					printf("E\n");
			}
			else if(c=='O'){
				if(!S.empty())
					S.pop();
			}
		}
		printf("\n");
	}
	return 0;
}
