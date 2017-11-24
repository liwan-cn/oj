#include<stdio.h>
#include<queue>
using namespace std;
struct Node{
	int data;
	int depth;
	Node *lchild,*rchild;
};
queue<Node *> Q;
Node *tmp=NULL;
Node *create(int data,int depth){
	Node *t = new Node;
	t->data=data;
	t->depth=depth;
	t->lchild=t->rchild=NULL;
	return t;
}
void find(Node *T,int root){
	if(T==NULL) return; 
	if(root==T->data){
		tmp=T;
		return;
	}
	find(T->lchild,root);
	find(T->rchild,root);
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n,m;
		Node *T = create(1,1);
		scanf("%d%d",&n,&m);
		while(n--){
			int data,root;
			scanf("%d%d",&data,&root);
			find(T,root);
			if(tmp->lchild==NULL){
				tmp->lchild=create(data,tmp->depth+1);
			}
			else{
				tmp->rchild=create(data,tmp->depth+1);
			}
		}
		while(!Q.empty()) Q.pop();
		printf("Q%d:",i);
		int d=0;
		Q.push(T);
		while(!Q.empty()){
			Node *t=Q.front();
			Q.pop();
			if(t->lchild) Q.push(t->lchild);
			if(t->rchild) Q.push(t->rchild);
			if(t->depth!=d){
				d=t->depth;
				printf("\n%d",t->data);
			}
			else printf(" %d",t->data);
		}
		printf("\n");
	}
	
	return 0;
}
