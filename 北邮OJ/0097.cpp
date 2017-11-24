#include<stdio.h>
struct Node{
	int data;
	Node *lchild,*rchild;
};
Node *create(){
	Node *t = new Node;
	t->lchild=t->rchild=NULL;
	return t;
}
Node *insert(Node *T,int x){
	if(T==NULL){
		T=create();
		T->data=x;
		return T; 
	}
	else if(x<T->data){
		if(T->lchild==NULL)
			printf("%d\n",T->data);
		T->lchild=insert(T->lchild,x);
	}	
	else if(x>T->data){
		if(T->rchild==NULL)
			printf("%d\n",T->data);
		T->rchild=insert(T->rchild,x);
	}
	return T;
}
int main(){
	int t;
	scanf("%d",&t);
	int data;
	Node *T = NULL;
	for(int i=0;i<t;i++){
		scanf("%d",&data);
		if(i==0) {
			printf("-1\n");
		}
		T=insert(T,data);
	}
	return 0;
}
