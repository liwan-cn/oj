#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <algorithm>
using namespace std;

int sum = 0;

typedef struct BiTNode
{
    double data;
    struct BiTNode *lchild,*rchild;//×óÓÒº¢Ö½Ö¸Õë
}BiTNode,*BiTree;

bool cmp(BiTree T1,BiTree T2){
    return (T1->data > T2->data);
}
void Traerse(BiTree &T,int n)
{
    if(T)
    {
        if(T->lchild==NULL&&T->rchild==NULL){
            sum = sum + (n*T->data);
        }
        Traerse(T->lchild,n+1);
        Traerse(T->rchild,n+1);
    }
}

int main(){
    int num=0;
    BiTree temp;
    BiTree b[1024];
    while(cin>>num){
	sum=0;
    for(int i = 0;i < num;i++){
        b[i] = (BiTree)malloc(sizeof(BiTNode));
        b[i]->lchild = NULL;
        b[i]->rchild = NULL;
        cin>>b[i]->data;
    }
    sort(b,b+num,cmp);
    while(num > 1){
        temp  = b[num-2];
        b[num-2] = (BiTree)malloc(sizeof(BiTNode));
        b[num-2]->data = temp->data + b[num-1]->data;
        b[num-2]->lchild = temp;
        b[num-2]->rchild =  b[num-1];
        num--;
        for(int j = num-1;j >= 1;j--){

            if(b[j]->data > b[j-1]->data)
            {temp=b[j];b[j]=b[j-1];b[j-1]=temp;}
            else break;
        }
    }
    Traerse(b[0],0);
    cout<<sum<<endl;
    }
    return 0;
}

