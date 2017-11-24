#include<stdio.h>
#include<string.h>
typedef char elem;
char str1[32],str2[32];
struct Node{
	elem data;
	Node *lchild,*rchild;
};
Node *create(){
	Node *t=new Node;
	t->lchild=t->rchild=NULL;
	return t;
}
void preOrder(Node *T){
	printf("%c",T->data);
	if(T->lchild!=NULL) 
		preOrder(T->lchild);
	if(T->rchild!=NULL)
		preOrder(T->rchild);
}
void inOrder(Node *T){
	if(T->lchild!=NULL) 
		inOrder(T->lchild);
	printf("%c",T->data);
	if(T->rchild!=NULL)
		inOrder(T->rchild);
}
void postOrder(Node *T){
	if(T->lchild!=NULL) 
		postOrder(T->lchild);
	if(T->rchild!=NULL)
		postOrder(T->rchild);
	printf("%c",T->data);
}
Node *build(int s1,int e1,int s2,int e2){
	Node* root=create();
	root->data=str1[s1];
	int point=s2;
	while(str2[point]!=str1[s1]&&point<e2) point++;
	if(point!=s2)
		root->lchild=build(s1+1,s1+point-s2,s2,point-1);
	if(point!=e2)
		root->rchild=build(s1+point-s2+1,e1,point+1,e2);
	return root;
}
int main(){
	while(scanf("%s",str1)!=EOF){
		scanf("%s",str2);
		Node *T=build(0,strlen(str1)-1,0,strlen(str2)-1);
		postOrder(T);
		printf("\n");
	}
	return 0;
}
