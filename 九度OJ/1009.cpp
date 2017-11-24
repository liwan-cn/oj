#include<stdio.h>
#include<string.h>
struct Node{
	int data;
	Node *lchild,*rchild;
};
Node *create(){
	Node *T = new Node;
	T->lchild=T->rchild=NULL;
	return T;
}
char str1[24],str2[24];

int size;

void preOrder(Node *T){
	str2[size++]=T->data+'0';
	//printf("%d ",T->data);
	if(T->lchild!=NULL) 
		preOrder(T->lchild);
	if(T->rchild!=NULL)
		preOrder(T->rchild);
}
void inOrder(Node *T){
	if(T->lchild!=NULL) 
		inOrder(T->lchild);
	str2[size++]=T->data+'0';
	//printf("%d ",T->data);
	if(T->rchild!=NULL)
		inOrder(T->rchild);
}
void deleteNode(Node *T){
	if(T->lchild!=NULL) 
		deleteNode(T->lchild);
	if(T->rchild!=NULL)
		deleteNode(T->rchild);
	delete T;
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
	char tmp[16];
	while(scanf("%d",&n)!=EOF&&n!=0){
		Node *T=NULL;
		scanf("%s",tmp);
		for(int i=0;tmp[i]!=0;i++){
			T=insert(T,tmp[i]-'0');
		}
		size=0;
		preOrder(T);
		inOrder(T);
		str2[size]=0;
		//puts(str2);
		strcpy(str1,str2);
		while(n--){
			deleteNode(T);
			T=NULL;
			scanf("%s",tmp);
			for(int i=0;tmp[i]!=0;i++){
				T=insert(T,tmp[i]-'0');
			}
			size=0;
			preOrder(T);
			inOrder(T);
			str2[size]=0;
			if(strcmp(str1,str2)==0) 
				puts("YES");
			else 
				puts("NO");
		}
	}
	return 0;
}
