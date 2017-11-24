#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 101
int Tree[N];
int findRoot(int x){
    if(Tree[x]==-1) return x;
    else{
        int tmp=findRoot(Tree[x]);   
        Tree[x]=tmp;
        return tmp; 
    }    
}
struct Edge{
    int a,b;
    int cost;
    bool operator < (const Edge &A) const{
        return cost<A.cost;    
    }    
}edge[6000];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n!=0){
        int size=0; 
        while(--n){
            getchar();
            char ch1;
            int k;
            scanf("%c %d",&ch1,&k); 
            while(k--){
                char ch2;
                getchar();
                scanf("%c %d",&ch2,&edge[size].cost);
                edge[size].a=ch1-'A'+1;
                edge[size].b=ch2-'A'+1;
                size++;
                //printf(" (%c) ",ch2);
            }   
			//printf("%c\n",ch1); 
        } 
        
        for(int i=1;i<=N;i++) Tree[i]=-1;
        sort(edge,edge+size);
        int ans=0;
        for(int i=0;i<size;i++){
            int a=findRoot(edge[i].a);
            int b=findRoot(edge[i].b);
            if(a!=b){
                Tree[a]=b;  
				ans+=edge[i].cost;
            }   
        }
        printf("%d\n",ans);
    } 
    return 0;    
} 
