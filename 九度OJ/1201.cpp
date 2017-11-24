#include<stdio.h>
typedef int elem;
struct Node{
	elem data;
	Node *lchild,*rchild;
};
Node *create(){
	Node *t = new Node;
	t->lchild=t->rchild=NULL;
	return t;
}
void preOrder(Node *T){
	printf("%d ",T->data);
	if(T->lchild!=NULL) 
		preOrder(T->lchild);
	if(T->rchild!=NULL)
		preOrder(T->rchild);
}
void inOrder(Node *T){
	if(T->lchild!=NULL) 
		inOrder(T->lchild);
	printf("%d ",T->data);
	if(T->rchild!=NULL)
		inOrder(T->rchild);
}
void postOrder(Node *T){
	if(T->lchild!=NULL) 
		postOrder(T->lchild);
	if(T->rchild!=NULL)
		postOrder(T->rchild);
	printf("%d ",T->data);
}
Node *insert(Node *T,int x){
	if(T==NULL){
		T=create();
		T->data=x;
		return T;
	}
	else if(x<T->data)
		T->lchild=insert(T->lchild,x);
	else if(x>T->data)
		T->rchild=insert(T->rchild,x);
	return T;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		Node *T=NULL;
		while(n--){
			int x;
			scanf("%d",&x);
			T=insert(T,x);
		}
		preOrder(T);
		printf("\n");
		inOrder(T);
		printf("\n");
		postOrder(T);
		printf("\n");
	}
	return 0;
}
